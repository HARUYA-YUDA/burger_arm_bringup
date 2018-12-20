cmake_minimum_required(VERSION 2.8.3)
project(burger_arm_bringup)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  dynamixel_sdk
  mikata_arm_msgs
  mikata_arm_toolbox
  dynamic_reconfigure
  cmake_modules
)
find_package(Eigen3 REQUIRED)

generate_dynamic_reconfigure_options(
  cfg/Position.cfg
  cfg/Velocity.cfg
)

catkin_package(DEPENDS EIGEN3)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../dynamixel_mikata_arm/mikata_arm_bringup/include
)

add_executable(burger_arm_bringup src/bringup.cpp)

add_executable(burger_arm_gui_control src/gui_control.cpp)

add_dependencies(burger_arm_bringup ${catkin_EXPORTED_TARGETS})
add_dependencies(burger_arm_gui_control ${PROJECT_NAME}_gencfg)

target_link_libraries(burger_arm_bringup ${catkin_LIBRARIES})
target_link_libraries(burger_arm_gui_control ${catkin_LIBRARIES})
