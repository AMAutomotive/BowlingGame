#include "../include//BowlingFrames.h"

/*
*/
BowlingGame::Frame::Frame::Frame() : firstThrow{0}, secondThrow{0}, eachFrameScore{0},
                                     isSpareFlag{false}, isStrikeFlag{false}
{
}

/*
*/
bool BowlingGame::Frame::Frame::setFirstThrowScore(const uint16_t &throwValue)
{
    if (checkScoreValue(throwValue))
	{
        firstThrow = throwValue;
        if (throwValue == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
*/
const uint16_t &BowlingGame::Frame::Frame::getFirstThrowScore() const
{
    return firstThrow;
}

/*
*/
bool BowlingGame::Frame::Frame::setSecondThrowScore(const uint16_t &throwValue)
{
    if (checkScoreValue(throwValue))
	{
        secondThrow = throwValue;
        if (firstThrow == LEAST_THROW_VALUE && secondThrow == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // for score 10 in first go , set strike in that frame
		}
        else if (auto value{firstThrow + secondThrow}; value == MAX_THROW_VALUE)
		{
            isSpareFlag = true; // for score 10 in seond go then set spare in that frame
		}
		return true;
	}
	return false;
}

/*
*/
const uint16_t &BowlingGame::Frame::Frame::getSecondThrowScore() const
{
    return secondThrow;
}

/*
*/
const bool &BowlingGame::Frame::Frame::isStrike() const
{
    return isStrikeFlag;
}

/*
*/
const bool &BowlingGame::Frame::Frame::isSpare() const
{
    return isSpareFlag;
}

/*
*/
bool BowlingGame::Frame::Frame::setFrameScore(const uint16_t &frameScore)
{
    if (eachFrameScore != frameScore)
	{
        eachFrameScore = frameScore;
		return true;
	}
	return false;
}

/*
*/
const uint16_t &BowlingGame::Frame::Frame::getFrameScore() const
{
    return eachFrameScore;
}

/*
*/
bool BowlingGame::Frame::Frame::setThirdThrowScore(const uint16_t &throwValue)
{
	return false;
}

/*
*/
uint16_t BowlingGame::Frame::Frame::getThirdThrowScore() const
{
	return 0;
}

/*
*/
bool BowlingGame::Frame::Frame::checkScoreValue(const uint8_t &throwValue)
{
    if ((throwValue < LEAST_THROW_VALUE) || (throwValue > MAX_THROW_VALUE))
	{
		return false;
	}
	return true;
}

/*
*/
BowlingGame::Frame::LastTenthFrame::LastTenthFrame() : m_thirdThrow{0}
{

}

/*
*/
bool BowlingGame::Frame::LastTenthFrame::setThirdThrowScore(const uint16_t &throwValue)
{
    if (checkScoreValue(throwValue))
	{
		m_thirdThrow = throwValue;
        if (throwValue == MAX_THROW_VALUE)
		{
            isStrikeFlag = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
*/
uint16_t BowlingGame::Frame::LastTenthFrame::getThirdThrowScore() const
{
	return m_thirdThrow;
}
