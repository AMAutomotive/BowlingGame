cmake_minimum_required(VERSION 3.16)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add main executable
add_executable(BowlingGame
    src/main.cpp
    src/MyPlayer.cpp
    src/BowlingFrames.cpp
    include/BowlingFrames.h
    include/MyPlayer.h
    include/Constants.h
)

# Add GoogleTest
# add_subdirectory(googletest)

# Add unit test directory
add_subdirectory(Test/UnitTests)

# Link gtest to the main executable (optional if tests only use it)
# target_link_libraries(BowlingGame gtest gtest_main)

# Enable test discovery and integration with ctest
 enable_testing()
 add_test(NAME BowlingGameTest COMMAND BowlingGameTest)
