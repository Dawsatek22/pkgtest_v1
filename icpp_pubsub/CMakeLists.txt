cmake_minimum_required(VERSION 3.8)
project(icpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


set(msg_files
  "msg/Val1.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Val1.msg"
)

ament_export_dependencies(rosidl_default_runtime)

add_executable(italk src/ipub.cpp)
ament_target_dependencies(italk rclcpp )
add_executable(ilisten src/isub.cpp)
ament_target_dependencies(ilisten rclcpp )


 
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(italk "${cpp_typesupport_target}")

target_link_libraries(ilisten "${cpp_typesupport_target}")





if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source file
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
  
 
endif()

install(TARGETS
  italk
  ilisten
  DESTINATION lib/${PROJECT_NAME})
 
 

ament_package()
