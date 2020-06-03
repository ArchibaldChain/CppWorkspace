cmake_minimum_required(VERSION 3.14)
project(opencv_test)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

set( NAME_SRC
        Lab_10/detect_face.cpp
        )

#        Lab_10/line_detection.cpp
set(NAME_BINARY_DIR
        )


include_directories(/usr/include /usr/include/opencv2 /usr/include/opencv ${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(/usr/lib ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(cam camera)
add_executable(${cam} Lab_10/Cam.cpp ${NAME_HEADERS} )
add_executable(test2 ${NAME_SRC} ${NAME_HEADERS} )
add_executable(test3  Lab_10/detect_circles.cpp ${NAME_HEADERS} )
add_executable(test4  Lab_10/Line_detection.cpp ${NAME_HEADERS} )
add_executable(test5  Lab_10/main.cpp ${NAME_HEADERS} )

target_link_libraries(${cam} opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(test2 opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(test3 opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(test4 opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(test5 opencv_core opencv_highgui opencv_imgproc)

