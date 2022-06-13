project(single-responsibility-demo)
cmake_minimum_required(VERSION 3.0)
add_executable(trade trade_main.cpp trade_processor.cpp utils.cpp)