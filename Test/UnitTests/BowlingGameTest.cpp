#include <gtest/gtest.h>
#include "../../include/MyPlayer.h"
#include "../../include/BowlingFrames.h"
#include <memory>


class BowlingAppTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGame::Players::Player> player{nullptr};
    std::unique_ptr<BowlingGame::Frame::Frame> firstFrame{nullptr};

protected:
    virtual void SetUp() override
    {
        player = std::make_unique<BowlingGame::Players::Player>();
        firstFrame = std::make_unique<BowlingGame::Frame::Frame>();

    }

    virtual void TearDown() override
    {
    }
};

/* Test functions in MyPlayer class */
TEST_F(BowlingAppTest, TestPlayerConstructor)
{
    printf("*********** SWUT_setPlayerName_0001 \n");
    // Precondition
    std::string Name = "Tata Technolgies";

    // Action
    bool isName = player->setPlayerName(Name);

    // Expected
    EXPECT_TRUE(isName);
    EXPECT_EQ(player->playerName(), Name);
}

/* Test functions in MyPlayer class */
TEST_F(BowlingAppTest, checkStrikecore)
{
    printf("*********** checkStrikecore \n");

    // Precondition
    uint16_t score{10};

    // Action
    firstFrame->setFirstThrowScore(score);

    // Expected
    EXPECT_TRUE(firstFrame->isStrike());
}

/* Test functions in MyPlayer class */
TEST_F(BowlingAppTest, checkSpareValue)
{
    printf("*****checkSpareValue \n");

    // Precondition
    uint16_t score{5};
    firstFrame->setFirstThrowScore(score);

    // Action
    firstFrame->setSecondThrowScore(score);

    // Expected
    EXPECT_FALSE(firstFrame->isStrike());
    EXPECT_TRUE(firstFrame->isSpare());
}





