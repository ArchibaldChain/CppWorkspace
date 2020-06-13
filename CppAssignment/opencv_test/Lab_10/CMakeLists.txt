cmake_minimum_required(VERSION 3.6)
PROJECT(opencv_demo)

set(OpenCV_INCLUDE_DIRS G:/2020Spring/CS205/LAB/opencv_4_2/mingw_opencv/include/opencv2)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(
        ${PROJECT_SOURCE_DIR}
        #${OpenCV_INCLUDE_DIRS}
        "G:/2020Spring/CS205/LAB/opencv_4_2/mingw_opencv/include/opencv2"

)
#include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv_demo main.cpp)
target_link_libraries(opencv_demo ${OpenCV_LIBS})



add_executable(line_detection line_detection.cpp)
target_link_libraries(line_detection ${OpenCV_LIBS})

add_executable(detect_circles detect_circles.cpp)
target_link_libraries(detect_circles ${OpenCV_LIBS})


add_executable(detect_face detect_face.cpp)
target_link_libraries(detect_face ${OpenCV_LIBS})