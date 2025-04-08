#include <gtest/gtest.h>
#include "../../include/BowlingApp.h"

using namespace BowlingGame::App;

class BowlingAppTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGame::Players::Player> player{nullptr};

protected:
    virtual void SetUp() override
    {
        player = std::make_unique<BowlingGame::Players::Player>();
    }

    virtual void TearDown() override
    {
    }
};


TEST_F(BowlingAppTest, calculateTotalScore)
{
    printf("Test Start");

    std::vector<int> score{1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};
    int throwNumber{1};
    int frameNumber{0};
    int throw1Score{0}, throw2Score{0}, throw3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalfinalScore{0};



    BowlingGame::Players::Player playerObj;
    playerObj.setPlayerName("Korea");


    for (; frameNumber < 9; frameNumber++)
    {
        throw1Score = score[scoreIndex];
        success = playerObj.setthrowValue(throwNumber, frameNumber, throw1Score);
        EXPECT_TRUE(success);
        if (throw1Score < MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw2Score = score[scoreIndex];
            success = playerObj.setthrowValue(throwNumber, frameNumber, throw2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        throwNumber = 1;
    }

    if (frameNumber == 9)
    {
       throw1Score = score[scoreIndex];
        success = playerObj.setthrowValue(throwNumber, frameNumber, throw1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        throwNumber++;
        throw2Score = score[scoreIndex];
        success = playerObj.setthrowValue(throwNumber, frameNumber, throw2Score);
        EXPECT_TRUE(success);

        if (throw1Score == MAX_THROW_VALUE || (throw2Score + throw1Score) == MAX_THROW_VALUE)
        {
            scoreIndex++;
            throwNumber++;
            throw3Score = score[scoreIndex];
            success = playerObj.setthrowValue(throwNumber, frameNumber, throw3Score);
            EXPECT_TRUE(success);
        }
    }
    totalfinalScore = playerObj.calculateFrameScore();

    // Expected
    EXPECT_EQ(totalfinalScore, 133);
}





