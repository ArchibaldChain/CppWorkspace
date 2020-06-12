// 追踪笔的运动轨迹

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\core.hpp>

using namespace cv;
using namespace std;

vector<Point> points;
Point center;
//绘制贝塞尔曲线
Point pointAdd(Point p, Point q)
{
    p.x += q.x;
    p.y += q.y;
    return p;
}

Point pointTimes(float c, Point p)
{
    p.x *= c;
    p.y *= c;
    return p;
}

Point Bernstein(float u, Point qi, Point mid, Point mo)
{
    Point a, b, c, r;

    a = pointTimes(pow(u, 2), mo);
    b = pointTimes(pow((1 - u), 2), qi);
    c = pointTimes(2 * u * (1 - u), mid);

    r = pointAdd(pointAdd(a, b), c);

    return r;
}

int main(int argc, char **argv)
{
    VideoCapture cap(1); //读取USB摄像头
    if (!cap.isOpened())
        return -1;

    int iLowH = 0;
    int iHighH = 5;
    int iLowS = 45;
    int iHighS = 255;
    int iLowV = 45;
    int iHighV = 255;
    int nGaussianBlurValue = 3;

    //采取颜色识别方法，利用滑条选色，参考HSV对应的颜色，获取目标物体

    namedWindow("Control");
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);

    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;
        cap >> imgOriginal;
        //高斯滤波
        GaussianBlur(imgOriginal, imgOriginal, Size(nGaussianBlurValue * +1, nGaussianBlurValue * 2 + 1), 0, 0);

        Mat imgHSV;
        vector<Mat> hsvSplit;
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //转换颜色空间

        Mat element1 = getStructuringElement(MORPH_RECT, Size(5, 5)); //获取结构元素
        morphologyEx(imgHSV, imgHSV, MORPH_OPEN, element1);           //开操作
        morphologyEx(imgHSV, imgHSV, MORPH_CLOSE, element1);          //闭操作

        split(imgHSV, hsvSplit);                //HSV图像分离
        equalizeHist(hsvSplit[2], hsvSplit[2]); //直方图均衡化
        merge(hsvSplit, imgHSV);                //HSV图像聚合
        Mat imgThresholded;
        //根据颜色选取目标物体
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);

        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));          //获取结构元素
        morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);    //开操作
        morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);   //闭操作
        morphologyEx(imgThresholded, imgThresholded, MORPH_ELLIPSE, element); //膨胀操作
        vector<vector<Point>> contours;
        vector<Vec4i> hierarcy;
        findContours(imgThresholded, contours, hierarcy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE); //查找轮廓
        //drawContours(imgOriginal, contours, -1, Scalar(0, 255, 0), 2);//绘制轮廓
        vector<RotatedRect> box(contours.size());
        for (int i = 0; i < contours.size(); i++)
        {
            box[i] = fitEllipse(Mat(contours[i]));
            center = box[i].center;
            points.push_back(center);
            //circle(imgOriginal, center, 3, Scalar(0, 255, 0));//绘制目标物体质点
            //ellipse(imgOriginal, box[i], Scalar(0, 255, 0));//绘制拟合椭圆
            for (int j = 2; j < points.size(); j += 2)
            {
                Point pre, last, mid;
                pre = points[j - 2];
                mid = points[j - 1];
                last = points[j];
                Point pt_pre = points[j - 2];
                Point pt_now;
                //绘制贝塞尔曲线,一小段一小段的直线就能组合成曲线
                for (int k = 0; k <= 10; k++)
                {
                    float u = (float)k / 10;
                    Point new_point = Bernstein(u, pre, mid, last);
                    pt_now.x = (int)new_point.x;
                    pt_now.y = (int)new_point.y;
                    line(imgOriginal, pt_pre, pt_now, Scalar(0, 255, 0), 2, CV_8U, 0); //绘制直线
                    pt_pre = pt_now;
                }
            }
        }
        imshow("Thresholded Image", imgThresholded); //显示处理图像
        imshow("Original", imgOriginal);             //显示最终图像
        char key = (char)waitKey(300);
        if (key == 27)
            break;
    }
    return 0;
}