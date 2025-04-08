#include "../../include/Constants.h"
#include "../../include/BowlingFrames.h"
#include <gtest/gtest.h>


using namespace BowlingGame::Frame;

class BowlingFrameTest : public ::testing::Test
{
public:
    BowlingGame::Frame::Frame simpleFrame;
    BowlingGame::Frame::LastTenthFrame tengthFrame;

protected:
    virtual void SetUp() override
    {

    }

    virtual void TearDown() override
    {
    }
};



/*
Test: setFirstThrowScore
Desc: check first roll score in the current frame
*/
TEST_F(BowlingFrameTest, setFirstThrowScore)
{
    printf("setFirstThrowScore\n");

    // Precondition
    uint16_t throwValue{10};

    // Action
    simpleFrame.setFirstThrowScore(throwValue);

    // Expected
    EXPECT_EQ(throwValue, simpleFrame.getFirstThrowScore());
}



/*
Test: setFirstThrowScore_2
Desc: check the score is valid
*/
TEST_F(BowlingFrameTest, setFirstThrowScore_2)
{
    printf("**setFirstThrowScore \n");

    // Precondition
    int16_t throwValue{-1};

    // Action
    bool checkScoreValue = simpleFrame.setFirstThrowScore(throwValue);

    // Expected
    EXPECT_FALSE(checkScoreValue);
}

/*
Test : Test set second roll score
Desc : check frame have strike/spare or not
*/
TEST_F(BowlingFrameTest, setSecondThrowScore_0001)
{
    printf("*********** setSecondThrowScore_0001 \n");

    // Precondition
    uint16_t throwValue{5};
    simpleFrame.setFirstThrowScore(throwValue);

    // Action
    simpleFrame.setSecondThrowScore(throwValue);

    // Expected
    EXPECT_FALSE(simpleFrame.isStrike());
    EXPECT_TRUE(simpleFrame.isSpare());
}

/*
Test: setSecondThrowScore_0003
Desc : check the score is valid
*/
TEST_F(BowlingFrameTest, setSecondThrowScore_0003)
{
    printf("*********** setSecondThrowScore_0003 \n");

    // Precondition
    int16_t throwValue{100};

    // Action
    bool checkScoreValue = simpleFrame.setSecondThrowScore(throwValue);

    // Expected
    EXPECT_FALSE(checkScoreValue);
}

/*
Test: setFrameScore_0001
Desc : check frame score
*/
TEST_F(BowlingFrameTest, setFrameScore_0001)
{
    printf("*********** setFrameScore_0001 \n");

    // Precondition
    uint16_t throwValue{5};
    simpleFrame.setFirstThrowScore(throwValue);
    throwValue = 4;
    simpleFrame.setSecondThrowScore(throwValue);

    // Action
    uint16_t frameScore = simpleFrame.getFirstThrowScore();
    frameScore += simpleFrame.getSecondThrowScore();
    simpleFrame.setFrameScore(frameScore);

    // Expected
    EXPECT_EQ(frameScore, simpleFrame.getFrameScore());
}

/*
Test: setThirdthrowValue_0001
Desc : check final frame third roll score
*/
TEST_F(BowlingFrameTest, setThirdthrowValue_0001)
{
    printf("*********** setThirdthrowValue_0001 \n");

    // Precondition
    uint16_t throwValue{5};

    // Action
    tengthFrame.setThirdThrowScore(throwValue);

    // Expected
    EXPECT_EQ(throwValue, tengthFrame.getThirdThrowScore());
}

/*
Test: setThirdthrowValue_0002
Desc : check the score is valid
*/
TEST_F(BowlingFrameTest, setThirdthrowValue_0002)
{
    printf("*********** setThirdthrowValue_0002 \n");

    // Precondition
    int16_t throwValue{-1};

    // Action
    bool checkScoreValue = tengthFrame.setThirdThrowScore(throwValue);

    // Expected
    EXPECT_FALSE(checkScoreValue);
}


