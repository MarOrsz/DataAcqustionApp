cmake_minimum_required(VERSION 3.20)

project(DataAcqusitionApp VERSION 0.0)

# ====== CXX STANDARD ======
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ====== EXECUTABLE ======
add_executable(DataAcqusitionApp app/main.cpp)