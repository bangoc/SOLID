project(isp-smart-door)
add_executable(door doors_main.cpp timer_client.cpp timer.cpp)
target_link_libraries(door pthread)