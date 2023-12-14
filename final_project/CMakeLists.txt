cmake_minimum_required(VERSION 3.8)
project(final_project)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(std_msgs REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(orocos_kdl REQUIRED)
find_package(mage_msgs REQUIRED)


link_directories(${gazebo_dev_LIBRARY_DIRS})

# Ariac Logical Camera Plugin
add_library(AriacLogicalCameraPlugin SHARED
  src/ariac_logical_camera_plugin.cpp
)
target_include_directories(AriacLogicalCameraPlugin PUBLIC include)
ament_target_dependencies(AriacLogicalCameraPlugin
  "gazebo_ros"
  "mage_msgs"
  "sensor_msgs"
  "image_transport"
  "camera_info_manager"
)
ament_export_libraries(AriacLogicalCameraPlugin)


# Disable Shadows Plugin
add_library(disable_shadows_plugin SHARED
  src/disable_shadows_plugin.cpp
)
target_include_directories(disable_shadows_plugin PUBLIC include)
ament_target_dependencies(disable_shadows_plugin
  "gazebo_ros"
)
ament_export_libraries(disable_shadows_plugin)


install(DIRECTORY include/
        DESTINATION include)

install(TARGETS
    AriacLogicalCameraPlugin
    disable_shadows_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY 
  config
  launch
  models
  worlds
  maps
  DESTINATION share/${PROJECT_NAME}/
)


# Install Python modules
ament_python_install_package(${PROJECT_NAME} SCRIPTS_DESTINATION lib/${PROJECT_NAME})

# Install Python executables
install(PROGRAMS
  nodes/environment_startup_node.py
  nodes/sensor_tf_broadcaster.py
  nodes/part_spawner.py
  nodes/object_tf_broadcaster.py
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
