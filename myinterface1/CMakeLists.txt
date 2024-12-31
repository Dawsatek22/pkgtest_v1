cmake_minimum_required(VERSION 3.12.3)
project(myinterface1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(rosidl_default_generators REQUIRED)
set(msg_files
"msg/Val1.msg")
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  
add_executable(pub src/custom_pub.cpp)
ament_target_dependencies(pub rclcpp)





target_link_libraries(pub "${cpp_typesupport_target}")
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
pub
DESTINATION lib/${PROJECT_NAME})


ament_package()
