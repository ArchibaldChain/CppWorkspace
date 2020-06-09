//
// Created by jyh on 2020/4/6.
//

#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
static const std::string OPENCV_WINDOW = "Image window";


int main(int argc, char** argv)
{
    //detect circles
    // Read the image as gray-scale
    //Mat srcImage = imread("../circle-detection.jpg", IMREAD_COLOR);
    string filename = R"(I:\Programming\Cpp_workspace\CppLearningCode\CppAssignment\opencv_test\Lab_10\circle-detection.jpg)";
    Mat srcImage = imread(filename, 1/*, IMREAD_COLOR*/);
    if(srcImage.empty())
    {
        cout<<"can not load image\n";
        cout << "*****************\n";
        return -1;
    }
    cout << "succeed\n";

    Mat midImage, dstImage;
    dstImage = srcImage.clone();
    // Convert to gray-scale
    cvtColor(srcImage, midImage, COLOR_BGR2GRAY);
    medianBlur(midImage, midImage, 5);
// Create a vector for detected circles
    vector<Vec3f>  circles;
// Apply Hough Transform
    HoughCircles(midImage, circles, HOUGH_GRADIENT, 1, 50, 200, 10, 25, 35);
// Draw detected circles
    for(size_t i=0; i<circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(dstImage, center, radius, Scalar(255, 0, 0), 2, 8, 0);
    }

        // Update GUI Window
        cv::imshow(OPENCV_WINDOW, dstImage);
//    cv::imshow(OPENCV_WINDOW, srcImage);
//    cv::imshow(OPENCV_WINDOW, srcImage);
        cv::waitKey(0);
    return 0;
}
