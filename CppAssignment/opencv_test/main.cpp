#include <opencv.hpp>
#include <iostream>
using  namespace cv;
using namespace std;
int main() {
    cout << "success";
    cout << "OpenCV Version: " << CV_VERSION << endl;
    Mat img = imread("I:\\Programming\\Cpp_workspace\\CppLearningCode\\CppAssignment\\opencv_test\\girl.jpg");
    if(img.empty())
    {
        cout<<"can not load image \n";
        return -1;
    }
    imshow("girl", img);
    cout << "success";
    waitKey(0);
    return 0;
}

