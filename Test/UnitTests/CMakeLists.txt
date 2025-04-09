add_executable(BowlingGameTest
    BowlingGameTest.cpp
    ../../src/MyPlayer.cpp
    ../../src/BowlingFrames.cpp

)

target_link_libraries(BowlingGameTest
    gtest
    gtest_main

)

target_include_directories(BowlingGameTest PRIVATE
    ${PROJECT_SOURCE_DIR}/googletest/googletest/include
)
