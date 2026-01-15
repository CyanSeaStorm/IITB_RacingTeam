cmake_minimum_required(VERSION 3.8)
project(shm)

# Compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Required for services
find_package(rosidl_default_generators REQUIRED)

# Generate service interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/SetSHMParams.srv"
  "srv/ApplyForce.srv"
)

# Build executable
add_executable(damped_shm_node src/spring.cpp)

ament_target_dependencies(damped_shm_node
  rclcpp
  visualization_msgs
  geometry_msgs
  std_msgs
)

# Link service headers
rosidl_target_interfaces(damped_shm_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

# Install
install(TARGETS
  damped_shm_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
