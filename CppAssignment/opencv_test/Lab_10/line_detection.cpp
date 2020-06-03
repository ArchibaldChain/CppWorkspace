//
// Created by jyh on 2020/4/23.
//
//#include <opencv.hpp>
#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{
    // Read the image as gray-scale
    Mat srcImage = imread("I:\\Programming\\CppWorkspace\\CppAssignment\\opencv_test\\Lab_10\\line-detection.jpg", IMREAD_COLOR);
    if(srcImage.empty())
    {
        cout<<"can not load image \n";
        return -1;
    }
    Mat midImage, dstImage;
    //midImage = Mat::zeros(srcImage.size(), srcImage.type());
    dstImage = Mat::zeros(srcImage.size(), srcImage.type());
    // Convert to gray-scale
    //cvtColor(srcImage, midImage, COLOR_BGR2GRAY);
    cvtColor(srcImage, dstImage, COLOR_BGR2GRAY);
    // Find the edges in the image using canny detector
    Canny(dstImage, dstImage, 0, 200);
    // Create a vector to store lines of the image
    vector<Vec4i> lines;
    // Apply Hough Transform
    HoughLinesP(dstImage, lines, 1, CV_PI/180, 150, 10, 10);
    // Draw lines on the image
    for (size_t i=0; i<lines.size(); i++) {
        Vec4i l = lines[i];
        line(srcImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 3, LINE_AA);
    }
    // Show result image
    imshow("Result Image", srcImage);
    waitKey(0);

}
