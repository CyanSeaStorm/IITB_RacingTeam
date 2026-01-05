cmake_minimum_required(VERSION 3.8)
project(com)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# --- executables ---
add_executable(vcu_node src/VCU.cpp)   # Matches your file name exactly
ament_target_dependencies(vcu_node rclcpp std_msgs)

add_executable(ai_node src/AI.cpp)     # Matches your file name exactly
ament_target_dependencies(ai_node rclcpp std_msgs)

install(TARGETS
  vcu_node
  ai_node
  DESTINATION lib/${PROJECT_NAME}
)

# --- testing / lint (optional) ---
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# finalize package
ament_package()
