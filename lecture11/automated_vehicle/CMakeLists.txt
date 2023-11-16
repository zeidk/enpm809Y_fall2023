cmake_minimum_required(VERSION 3.8)
project(automated_vehicle)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

include_directories(include/automated_vehicle)

#camera_driver
add_executable(camera_driver src/camera.cpp)
ament_target_dependencies(camera_driver rclcpp sensor_msgs)
install(TARGETS camera_driver DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY include launch DESTINATION share/${PROJECT_NAME})


ament_package()
