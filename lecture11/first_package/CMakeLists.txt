cmake_minimum_required(VERSION 3.8)
project(first_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include/first_package)

#hello
add_executable(hello src/first_package.cpp)
ament_target_dependencies(hello rclcpp)
install(TARGETS hello DESTINATION lib/${PROJECT_NAME})

#light_switcher_pub
add_executable(light_switcher_pub src/light_switcher_pub.cpp)
ament_target_dependencies(light_switcher_pub rclcpp)
install(TARGETS light_switcher_pub DESTINATION lib/${PROJECT_NAME})

#light_switcher_sub
add_executable(light_switcher_sub src/light_switcher_sub.cpp)
ament_target_dependencies(light_switcher_sub rclcpp)
install(TARGETS light_switcher_sub DESTINATION lib/${PROJECT_NAME})

# include_directories(include/first_package)

# # first_package
# add_executable(hello src/first_package.cpp)
# ament_target_dependencies(hello rclcpp)

# # light_switcher_pub
# add_executable(light_switcher_pub src/light_switcher_pub.cpp)
# ament_target_dependencies(light_switcher_pub rclcpp)

# # light_switcher_sub
# add_executable(light_switcher_sub src/light_switcher_sub.cpp)
# ament_target_dependencies(light_switcher_sub rclcpp)

# install(TARGETS hello DESTINATION lib/${PROJECT_NAME})
# install(TARGETS light_switcher_pub DESTINATION lib/${PROJECT_NAME})
# install(TARGETS light_switcher_sub DESTINATION lib/${PROJECT_NAME})


# install(DIRECTORY include launch DESTINATION share/${PROJECT_NAME})
ament_package()
