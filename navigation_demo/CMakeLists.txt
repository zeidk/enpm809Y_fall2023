cmake_minimum_required(VERSION 3.8)
project(navigation_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)


include_directories(include/navigation_demo)

#navigation_demo
add_executable(navigation_demo src/navigation_demo.cpp)
ament_target_dependencies(navigation_demo rclcpp rclcpp_action rclcpp_components nav2_msgs geometry_msgs)
install(TARGETS navigation_demo DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include DESTINATION share/${PROJECT_NAME})

ament_package()
