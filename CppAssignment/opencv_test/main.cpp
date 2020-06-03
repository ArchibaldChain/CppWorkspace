#include <opencv.hpp>
#include <iostream>
using  namespace cv;
using namespace std;
int main() {
    cout << "success";
    cout << "OpenCV Version: " << CV_VERSION << endl;
    Mat img = imread("girl.jpg");
    imshow("girl", img);
    cout << "success";
    waitKey(0);
    return 0;
}

