cmake_minimum_required(VERSION 3.8)
project(shm)

# Compiler warnings (good practice)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)

# Build executable
add_executable(shm src/spring.cpp)

ament_target_dependencies(shm
  rclcpp
  visualization_msgs
)

# Install executable
install(TARGETS
  shm
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
