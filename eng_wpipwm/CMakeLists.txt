cmake_minimum_required(VERSION 3.28.3)
project(eng_wpipwm)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
add_executable(pwm1 src/pwm1.cpp)
add_executable(pwm2 src/pwm2.cpp)
target_link_libraries(pwm1 -lwiringPi)
target_link_libraries(pwm2 -lwiringPi)
ament_target_dependencies(pwm1 rclcpp std_msgs)
ament_target_dependencies(pwm2 rclcpp std_msgs)
# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

install(TARGETS
  pwm1
  pwm2
  DESTINATION lib/${PROJECT_NAME})

ament_package()

