cmake_minimum_required(VERSION 3.28.3)
project(multi_int1)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


find_package(ament_cmake_python)
# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the folloa section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)



  add_executable(pub src/pub2025.cpp)
  ament_target_dependencies(pub rclcpp std_msgs)

  
  
  install(TARGETS
  
  pub
  DESTINATION lib/${PROJECT_NAME}
)

# Install Python modules
ament_python_install_package(scripts)

# Install Python executables
install(PROGRAMS
  scripts/py_sub.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()