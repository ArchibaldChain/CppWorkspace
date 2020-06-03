//
// Created by Archibald Chain on 2020/5/11.
//

#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){
    cv::VideoCapture cap;
    cap.open(1);
    if (!cap.open(0)) {
        cout << "Failed to open camera!!" << endl;
//        return -1;
    }
    Mat img, imgGray;
    int fps = 60;
    while (true) {
        cap >> img;
//        cvtColor(img, imgGray, COLOR_BGR2GRAY);
        equalizeHist(imgGray, imgGray);//直方图均匀化
        waitKey(1000/fps);
        imshow("src", img);
    }
}

