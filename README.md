# Space Concordia ROS2 Intro Task

## Requirements
- Ubuntu 22.04
- ROS 2 Humble

## Packages

### Python Package
py_intro_pkg

Contains:
- py_publisher
- py_subscriber

### C++ Package
cpp_intro_pkg

Contains:
- cpp_publisher
- cpp_subscriber


## Build

cd ~/ros2_intro_ws

colcon build

source install/setup.bash


## Run Python Nodes

ros2 run py_intro_pkg py_publisher

ros2 run py_intro_pkg py_subscriber


## Run C++ Nodes

ros2 run cpp_intro_pkg cpp_publisher

ros2 run cpp_intro_pkg cpp_subscriber
