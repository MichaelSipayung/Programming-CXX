# CMakeList.txt : CMake project for Advanced C++, include source and define
# project specific logic here.
#
# Add source to this project's executable.
cmake_minimum_required(VERSION 3.25)
project(TheC)
add_executable (main "main.cxx" "main.h" "rassoc.cpp" "problem.cpp"
        rsales.cpp
        m_sales.cxx "dynamic.h" "dynamic.cpp"
        overload.cpp "cpcontrol.h" "cpcontrol.cpp" "algorithm_repo.h" "algorithm_repo.cpp")
set(CMAKE_CXX_STANDARD 11)
# TODO: Add tests and install targets if needed.
