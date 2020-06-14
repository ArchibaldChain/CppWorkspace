#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\core.hpp>

using namespace cv;
using namespace std;

const int redLower[] = {170, 100, 100};
const int redUpper[] = {179, 255, 255};


int main(int argc, char **argv)
{
    VideoCapture cap(0); //读取USB摄像头
    if (!cap.isOpened())
        return -1;

    int nGaussianBlurValue = 3;

    //采取颜色识别方法，利用滑条选色，参考HSV对应的颜色，获取目标物体

    vector<Point> centers;
    while (true)
    {
        Mat imgOriginal;
        cap >> imgOriginal;
        //高斯滤波
        GaussianBlur(imgOriginal, imgOriginal, Size(nGaussianBlurValue * +1, nGaussianBlurValue * 2 + 1), 0, 0);

        Mat imgHSV;
        vector<Mat> hsvSplit;
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //转换颜色空间

        split(imgHSV, hsvSplit);                //HSV图像分离
        equalizeHist(hsvSplit[2], hsvSplit[2]); //直方图均衡化
        merge(hsvSplit, imgHSV);                //HSV图像聚合
        Mat imgThresholded;
        //根据颜色选取目标物体
        inRange(imgHSV, Scalar(redLower[0], redLower[1], redLower[2]),
                Scalar(redUpper[0], redUpper[1], redUpper[2]), imgThresholded);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarcy;
        findContours(imgThresholded, contours, hierarcy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE); //查找轮廓 改为圆圈
        drawContours(imgOriginal, contours, -1, Scalar(0, 255, 0), 2);                                //绘制轮廓

        if (contours.size() > 0){
            int maxIndex = 0;
            int maxSize = 0;
            for (int i = 0; i < contours.size(); ++i) {
                if(contours[i].size() > maxSize) {
                    maxSize = contours[i].size();
                    maxIndex = i;
                }
            }
            // find the biggest circle
            auto circle = contours[maxIndex];
            Point2f center;
            float radius;
            cv::minEnclosingCircle(circle, center, radius);
            // get the radius and center of the circle

            auto M = cv::moments(circle);

            if (radius > 10){
                // draw circle around the cap and the center.
                cv::circle(imgOriginal, center, (int)radius,Scalar(0,255,255), 2);
                cv::circle(imgOriginal, center, 5, Scalar(0,0,25), -1);
            }

            //put centers into the content
            centers.push_back(center);
            centers.insert(centers.begin(), center);
        }
        // show centers
        for (int i = 0; i < centers.size() - 1 && i < 124; ++i){
            int thickness = (int)sqrt((54 / float(i + 1)) * 2.5);
            line(imgOriginal, centers[i], centers[i + 1], Scalar(0, 0, 255), thickness);
        }

        imshow("Thresholded Image", imgThresholded); //显示处理图像
        imshow("Original", imgOriginal);             //显示最终图像
        char key = (char)waitKey(300);
        if (key == 27)
            break;
    }
    return 0;
}