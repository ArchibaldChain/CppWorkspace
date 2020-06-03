cmake_minimum_required(VERSION 3.12)
project(newPorject)

set(CMAKE_CXX_STANDARD 14)


add_executable(Lab Lab/Lab2/Exercise1.cpp)
add_executable(Lab2Ex2 Lab/Lab2/Exercise2.cpp )
add_executable(Lab2Ex3 Lab/Lab2/Exercise3.cpp)
add_executable(test_csv Assignment/test_csv.cpp)
add_executable(Assignment2 Assignment/Assignment2.cpp)
add_executable(Lab7ex2 Lab/Lab7/Lab7ex2.cpp)
add_executable(Midterm1 Midterm/Question1.cpp)
add_executable(Midterm2 Midterm/Question2.cpp)
add_executable(Midterm3 Midterm/Question3.cpp)
add_executable(Midterm4 Midterm/Question4.cpp)

add_executable(Lab11ex1 Lab/Lab11/CandyBar.h Lab/Lab11/CandyBar.cpp Lab/Lab11/useCandyBar.cpp)
add_executable(Lab11ex2 Lab/Lab11/Rectangle.h Lab/Lab11/Rectangle.cpp Lab/Lab11/useRectangle.cpp)

add_executable(Lab12ex1 Lab/Lab12/Complex.h Lab/Lab12/Complex.cpp Lab/Lab12/usingComplex.cpp)
add_executable(Lab12ex2 Lab/Lab12/Number.h Lab/Lab12/Number.cpp Lab/Lab12/usingNum.cpp)

set(Lab13
        Lab/Lab13/CCube.cpp
        Lab/Lab13/CCube.h
        Lab/Lab13/CSphere.cpp
        Lab/Lab13/CSphere.h
        Lab/Lab13/CStereoShape.h
        Lab/Lab13/CStereoShape.cpp
        Lab/Lab13/testShape.cpp
        )
add_executable(Lab13ex1 ${Lab13})

add_executable(Lab14ex1 Lab/Lab14/maxTemplate.cpp)

set(file
        Lab/Lab14/Matrix.cpp
        Lab/Lab14/Matrix.h
        Lab/Lab14/useMatrixTemplate.cpp
        )
add_executable(Lab14ex2 ${file} )


add_executable(Lab15 Lab/Lab15/testException.cpp )
add_executable(test Lab/Lab15/test.cpp)
