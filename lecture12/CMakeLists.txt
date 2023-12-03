cmake_minimum_required(VERSION 3.8)
project(lecture12)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

# include folder whish has all the header files
include_directories(include/lecture12)

# Create a variable for all dependencies
set(FRAME_DEMO_INCLUDE_DEPENDS
  rclcpp 
  tf2_ros
  geometry_msgs
  tf2
  tf2_geometry_msgs
)

# Find all dependencies
foreach(dependency IN ITEMS ${FRAME_DEMO_INCLUDE_DEPENDS})
  find_package(${dependency} REQUIRED)
endforeach()


#-----------------------------
# C++
#-----------------------------
add_executable(broadcaster_demo src/broadcaster_demo.cpp src/utils.cpp)
ament_target_dependencies(broadcaster_demo ${FRAME_DEMO_INCLUDE_DEPENDS})

install(TARGETS broadcaster_demo
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)


add_executable(listener_demo src/listener_demo.cpp src/utils.cpp)
ament_target_dependencies(listener_demo ${FRAME_DEMO_INCLUDE_DEPENDS})

install(TARGETS listener_demo
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

#-----------------------------
# Installation
#-----------------------------


install(TARGETS
broadcaster_demo
listener_demo
DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include
  DESTINATION share/${PROJECT_NAME}/
)
ament_package()