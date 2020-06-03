#include <opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    cout << "OpenCV Version: " << CV_VERSION << endl;
	Mat img = imread( (R"(I:\Programming\CppWorkspace\CppAssignment\opencv_test\Lab_10\Pokemon02.png)"),1);
    if(img.empty())
    {
        cout<<"can not load image \n";
        return -1;
    }
	imshow("Pokemon", img);
	waitKey(0);
	return 0;
}
