//
// file_writer.cpp
// Created by Archibald Chain on 2020/6/14.
//

#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){
    string file = R"(I:\Programming\Cpp_workspace\CppLearningCode\CppAssignment\opencv_test\write.mp4)";
    cv::VideoCapture cap(file);

    Mat img;
    img = imread(R"(I:\Programming\Cpp_workspace\CppLearningCode\CppAssignment\opencv_test\girl.jpg)");

    VideoWriter video(file,CV_FOURCC('M','J','P','G'),60, Size(img.rows, img.cols));

//    cout << cap.get();
    int fps = 60;
    for (int i = 0; i < 100; ++i) {
        cout << i;
        img = imread(R"(I:\Programming\Cpp_workspace\CppLearningCode\CppAssignment\opencv_test\girl.jpg)");

//        cvtColor(img, imgGray, COLOR_BGR2GRAY);
        waitKey(1000/fps);
        imshow("src", img);
        video.write(img);
    }

}

