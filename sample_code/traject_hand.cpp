// 追踪掌心的运动轨迹

#include <iostream>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
Point YCrCb_Otsu_detect(Mat &src);
Point image_center(Mat &src, vector<vector<Point>> &filterContours, Mat &output_mask);

int main()
{
    VideoCapture cap;
    cap.open(1);
    if (!cap.isOpened())
    {
        cout << "failed to open the camera!" << endl;
        return 0;
    }
    Mat frame;
    Mat HSV;
    Mat YCrCb;
    Point center;
    vector<Point> center_all;
    int fps = 60;
    while (1)
    {
        cap >> frame;
        center = YCrCb_Otsu_detect(frame);
        center_all.push_back(center);
        if (center_all.size() != 1)
        {
            for (size_t i = 0; i < center_all.size() - 1; i++)
            {
                line(frame, center_all[i], center_all[i + 1], Scalar(128, 255, 128), 2);
            }
        }
        imshow("frame", frame);
        if (waitKey(1000 / fps) >= 0)
            break;
    }
    cap.release();
    return 0;
}

Point YCrCb_Otsu_detect(Mat &src)
{
    Mat ycrcb_image;
    GaussianBlur(src, src, Size(7, 7), 3, 3);
    cvtColor(src, ycrcb_image, cv::COLOR_BGR2YCrCb);
    Mat detect;
    vector<Mat> channels;
    split(ycrcb_image, channels);
    Mat output_mask = channels[1];
    threshold(output_mask, output_mask, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    src.copyTo(detect, output_mask);
    imshow("YCrCb_ output mask", output_mask);

    vector<vector<Point>> contours;
    vector<vector<Point>> filterContours;
    vector<Vec4i> hierarchy;
    findContours(output_mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    // int index;
    for (size_t i = 0; i < contours.size(); i++)
    {
        // int square = fabs(contourArea(Mat(contours[i])));
        if (fabs(contourArea(Mat(contours[i]))) > 100 && fabs(contourArea(Mat(contours[i]))) > 10000)
        {
            filterContours.push_back(contours[i]);
            // index = i;
        }
    }
    drawContours(src, filterContours, -1, Scalar(0, 255, 255), 3);

    Point center;
    center = image_center(src, filterContours, output_mask);
    return center;
}

Point image_center(Mat &src, vector<vector<Point>> &filterContours, Mat &output_mask)
{
    Point center;
    if (filterContours.size() == 0)
        return center;
    Moments moment = moments(output_mask, true);
    //求取质心
    center = Point(moment.m10 / moment.m00, moment.m01 / moment.m00);
    circle(src, center, 5, Scalar(0, 0, 255), cv::FILLED);
    vector<Point> hull;
    //凸包点集
    vector<int> hull_I;
    vector<Vec4i> defect;
    for (size_t i = 0; i < filterContours.size(); i++)
    {
        convexHull(Mat(filterContours[i]), hull, true);
        convexHull(Mat(filterContours[i]), hull_I, false);

        convexityDefects(Mat(filterContours[i]), hull_I, defect);
        int hullcount = (int)hull.size();
        for (int j = 0; j < hullcount - 1; j++)
        {
            circle(src, hull[j], 3, Scalar(255, 0, 0), cv::FILLED);
        }

        vector<Vec4i>::iterator d = defect.begin();

        while (d != defect.end())
        {
            Vec4i &v = (*d);
            int startidx = v[0];
            Point ptStart(filterContours[i][startidx]);
            // 堆凸包中的第一个点
            int endidx = v[1];
            Point ptEnd(filterContours[i][endidx]);
            // 堆凸包中的最后一个点
            int faridx = v[2];
            Point ptFar(filterContours[i][faridx]);
            //凹点
            int depth = v[3] / 256;
            //凹点与凸包的距离
            if (depth > 20 && depth < 140)
            {
                line(src, ptStart, ptFar, CV_RGB(0, 255, 0), 2);
                line(src, ptEnd, ptFar, CV_RGB(0, 255, 0), 2);
                circle(src, ptStart, 4, Scalar(255, 0, 100), 2);
                circle(src, ptEnd, 4, Scalar(255, 0, 100), 2);
                circle(src, ptFar, 4, Scalar(100, 0, 255), 2);
            }
            d++;
        }
    }
    return center;
}