cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
project(robot_simulation)

# Include FetchContent module
include(FetchContent)

# Fetch these libraries
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip 
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# FetchContent_Declare(
#     wxWidgets
#     URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.zip
#     DOWNLOAD_EXTRACT_TIMESTAMP TRUE
# )

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

add_executable(robot_simulation
    ./main.cpp
    ./src/collision_detection/collision_detection.cpp
    ./src/items/cube.cpp
    ./src/items/item_manager.cpp
    ./src/map/map.cpp
    ./src/path_finder/path_finder.cpp
    ./src/robots/inventory.cpp
    ./src/robots/robot.cpp
    ./src/sensors/distance_sensor.cpp
    ./src/sensors/item_sensor.cpp
    ./src/robots/robot_manager.cpp
    ./src/app.cpp
    ./src/config.cpp
    ./src/events/publisher.cpp
)

# TODO fix this test stuff
# add_executable(tests
#     ./test/distance_sensor_test.cpp
#     ./test/robot_test.cpp
#     ./src/collision_detection/collision_detection.cpp
#     ./src/items/cube.cpp
#     ./src/items/item_manager.cpp
#     ./src/map/map.cpp
#     ./src/path_finder/path_finder.cpp
#     ./src/robots/inventory.cpp
#     ./src/robots/robot.cpp
#     ./src/sensors/distance_sensor.cpp
# )

# target_link_libraries(tests GTest::gtest_main)
# gtest_discover_tests(tests)