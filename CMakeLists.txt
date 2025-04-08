cmake_minimum_required(VERSION 3.16)
project(BowlingGame)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(BowlingGame 
    src/main.cpp
    src/MyPlayer.cpp
    src/BowlingFrames.cpp
    src/BowlingApp.cpp
    include/BowlingApp.h
    include/BowlingFrames.h
    include/MyPlayer.h
    include/Constants.h
    Test/UnitTests/BowlingGameTest.cpp

)
 add_subdirectory(Test/googletest)
 target_link_libraries(BowlingGame gtest gtest_main)

 target_sources(BowlingGame PUBLIC
    Test/UnitTests/BowlingGameTest.cpp
  )

target_include_directories(BowlingGame PRIVATE
    Test/UT
)
