// 移动物体检测 使用滤波

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

Point center;
Point fre_center; //存储前一帧中心坐标
int num = 0;
vector<Point> points;

Mat MoveDetect(Mat background, Mat img)
{
    Mat result = img.clone();
    Mat gray1, gray2;
    cvtColor(background, gray1, cv::COLOR_BGR2GRAY);
    cvtColor(img, gray2, cv::COLOR_BGR2GRAY);

    Mat diff;
    absdiff(gray1, gray2, diff);
    imshow("absdiss", diff);
    threshold(diff, diff, 45, 255, cv::THRESH_BINARY);
    imshow("threshold", diff);

    Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
    Mat element2 = getStructuringElement(MORPH_RECT, Size(9, 9));
    erode(diff, diff, element);
    imshow("erode", diff);
    dilate(diff, diff, element2);
    imshow("dilate", diff);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarcy;
    findContours(diff, contours, hierarcy, cv::RETR_EXTERNAL, CHAIN_APPROX_NONE); //查找轮廓
    vector<Rect> boundRect(contours.size());                                      //定义外接矩形集合
    //drawContours(img2, contours, -1, Scalar(0, 0, 255), 1, 8);  //绘制轮廓
    vector<RotatedRect> box(contours.size());
    int x0 = 0, y0 = 0, w0 = 0, h0 = 0;
    for (int i = 0; i < contours.size(); i++)
    {
        boundRect[i] = boundingRect((Mat)contours[i]); //查找每个轮廓的外接矩形

        x0 = boundRect[i].x;      //获得第i个外接矩形的左上角的x坐标
        y0 = boundRect[i].y;      //获得第i个外接矩形的左上角的y坐标
        w0 = boundRect[i].width;  //获得第i个外接矩形的宽度
        h0 = boundRect[i].height; //获得第i个外接矩形的高度
        if (w0 > 30 && h0 > 30)   //筛选长宽大于30的轮廓
        {
            num++;
            //rectangle(result, Point(x0, y0), Point(x0+w0, y0+h0), Scalar(0, 255, 0), 2, 8); //绘制第i个外接矩形
            box[i] = fitEllipse(Mat(contours[i]));
            ellipse(result, box[i], Scalar(255, 0, 0), 2, 8);           //椭圆轮廓
            circle(result, box[i].center, 3, Scalar(0, 0, 255), -1, 8); //画中心
            center = box[i].center;                                     //当前帧的中心坐标
            points.push_back(center);                                   //中心塞进points向量集
            if (num != 1)
            {
                //line(result, fre_center, center, Scalar(255, 0, 0), 2, 8);
                for (int j = 0; j < points.size() - 1; j++)
                    line(result, points[j], points[j + 1], Scalar(0, 255, 0), 2, 8);
            }
            //fre_center = center;
        }
    }
    return result;
}

int main()
{
    VideoCapture cap(1);
    if (!cap.isOpened()) //检查打开是否成功
        return 1;
    Mat frame;
    Mat background;
    Mat result;
    int count = 0;
    while (1)
    {
        cap >> frame;
        if (!frame.empty())
        {
            count++;
            if (count == 1)
                background = frame.clone(); //提取第一帧为背景帧
            imshow("video", frame);
            result = MoveDetect(background, frame);
            imshow("result", result);
            if (waitKey(30) == 27)
                break;
        }
        else
            break;
    }
    cap.release();
    return 0;
}