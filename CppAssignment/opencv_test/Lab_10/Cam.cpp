//
// Created by Archibald Chain on 2020/5/11.
//

#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){
    string file = R"(I:\Programming\Cpp_workspace\CppLearningCode\CppAssignment\opencv_test\head_square.mp4)";
    cv::VideoCapture cap(file);
//    cout << cap.get();
    Mat img, imgGray;
    int fps = 60;
    while (true) {
        if (!cap.isOpened()) { //check if video device has been initialised
            cout << "cannot open camera" << endl;
            return -1;
        }
        cap >> img;
//        cvtColor(img, imgGray, COLOR_BGR2GRAY);

        equalizeHist(imgGray, imgGray);//直方图均匀化
        waitKey(1000/fps);
        imshow("src", img);
    }

}

