#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <cmath>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    VideoCapture cap(1); //读取USB摄像头
    if (!cap.isOpened())
        return -1;

    // int nGaussianBlurValue = 3;
    CascadeClassifier face_cascade;
    string face_xml_filename =
        "F:/Program Files/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml";
    if (!face_cascade.load(face_xml_filename))
    {
        cout << "file not found!\n";
        return -1;
    }

    vector<Point> pts;
    while (true)
    {
        Mat imgOriginal;
        cap >> imgOriginal;
        //高斯滤波
        // GaussianBlur(imgOriginal, imgOriginal, Size(nGaussianBlurValue * +1, nGaussianBlurValue * 2 + 1), 0, 0);

        Mat imgGray;
        vector<Mat> hsvSplit;
        cvtColor(imgOriginal, imgGray, COLOR_BGR2GRAY); //转换颜色空间

        vector<Rect> faces;
        face_cascade.detectMultiScale(imgGray, faces, 1.3, 5);

        // int l = faces.size();

        for (auto f : faces)
        {

            rectangle(imgOriginal, Point(f.x, f.y), Point(f.x + f.width, f.y + f.height), Scalar(0, 0, 251), 1, 8);
            // vector<Vec4i> hierarcy;
            Point center = Point(f.x + f.width / 2, f.y + f.height / 2);
            pts.push_back(center);
            pts.insert(pts.begin(), center);
            for (int i = 0; i < pts.size() - 1 && i < 124; ++i)
            {
                int thickness = (int)sqrt((54 / float(i + 1)) * 2.5);
                line(imgOriginal, pts[i], pts[i + 1], Scalar(0, 0, 255), thickness);
            }
        }
        imshow("Original", imgOriginal); //显示最终图像
        char key = (char)waitKey(25);
        if (key == 27)
            break;
    }
    return 0;
}