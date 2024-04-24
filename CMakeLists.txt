cmake_minimum_required(VERSION 3.10)  # 指定CMake的最小版本要求

# 设置项目名称和版本
project(SimpleFSM VERSION 1.0 DESCRIPTION "Simple Finite State Machine")

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(SimpleFSM SimpleFSM.cpp)

# 配置项目信息
set_target_properties(SimpleFSM PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(SimpleFSM PROPERTIES DESCRIPTION ${PROJECT_DESCRIPTION})
