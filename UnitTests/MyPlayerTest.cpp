#include "../../include/Constants.h"
#include "../../include/MyPlayer.h"
#include <gtest/gtest.h>

using namespace BowlingGame::Players;

class PlayerTest : public ::testing::Test
{
public:
    BowlingGame::Players::Player player;

protected:
    virtual void SetUp() override
    {

    }

    virtual void TearDown() override
    {
    }
};
