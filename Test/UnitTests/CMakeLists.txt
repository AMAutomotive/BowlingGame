cmake_minimum_required(VERSION 3.16)

# Only define project if built directly

    project(BowlingGameTest)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_BUILD_TYPE Debug)

    message(STATUS "Standalone test build")

    # Use absolute path to googletest
    set(GTEST_SOURCE_DIR /home/asmam/BowlingUnit/googletest)

    if(EXISTS ${GTEST_SOURCE_DIR})
        add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/googletest-build)
    else()
        message(FATAL_ERROR "googletest not found at ${GTEST_SOURCE_DIR}")
    endif()

    include_directories(/home/asmam/BowlingUnit/include)


# Define test executable
add_executable(BowlingGameTest
    BowlingGameTest.cpp
    ../../src/MyPlayer.cpp
    ../../src/BowlingFrames.cpp
)

# Include paths
target_include_directories(BowlingGameTest PRIVATE
    /home/asmam/BowlingUnit/include
    /home/asmam/BowlingUnit/googletest/googletest/include
)

# Link gtest libraries
 target_link_libraries(BowlingGameTest
     gtest
     gtest_main
    # pthread
 )
