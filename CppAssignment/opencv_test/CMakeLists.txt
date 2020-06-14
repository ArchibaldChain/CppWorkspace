cmake_minimum_required(VERSION 3.14)
project(opencv_test)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(
        /usr/include
        /usr/include/opencv2
        /usr/include/opencv
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}
)


link_directories(/usr/lib ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(cam camera)
add_executable(${cam} Lab_10/Cam.cpp )
target_link_libraries(${cam} ${OpenCV_LIBS})

set(test2 face_detection)
add_executable(${test2} Lab_10/detect_face.cpp )
target_link_libraries(${test2} ${OpenCV_LIBS})

set(test3 circle_detection)
add_executable(${test3}  Lab_10/detect_circles.cpp  )
target_link_libraries(${test3} opencv_core opencv_highgui opencv_imgproc)

set(test4 Line_detection)
add_executable(${test4} Lab_10/Line_detection.cpp)
target_link_libraries(${test4} opencv_core opencv_highgui opencv_imgproc)

set(test5 Lab10_demo)
add_executable(${test5}  Lab_10/main.cpp ${NAME_HEADERS} )
target_link_libraries(${test5} opencv_core opencv_highgui opencv_imgproc)

set(main test)
add_executable(${main} main.cpp ${NAME_HEADERS} )
target_link_libraries(${main} ${OpenCV_LIBS})

set(tra trajectory_test)
add_executable(${tra} trajectory_test.cpp ${NAME_HEADERS} )
target_link_libraries(${tra} ${OpenCV_LIBS})

add_executable(filewriter Lab_10/file_writer.cpp ${NAME_HEADERS} )
target_link_libraries(filewriter ${OpenCV_LIBS})

add_executable(facecap sample_code/traject_face.cpp ${NAME_HEADERS} )
target_link_libraries(facecap ${OpenCV_LIBS})
