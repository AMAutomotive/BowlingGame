#include "MyPlayer.h"

/*
*/
BowlingGame::Players::Player::Player() : m_finalScore{0}, m_Name{}, m_frameNumber{0}
{
    m_frames.reserve(MAX_NUMBER_OF_FRAME);
    for (uint16_t frameIndex = 0; frameIndex < (MAX_NUMBER_OF_FRAME - 1); frameIndex++)
    {
        m_frames.push_back(std::make_unique<BowlingGame::Frame::Frame>());
    }
    m_frames.push_back(std::make_unique<BowlingGame::Frame::LastTenthFrame>());

    m_frameNumber = m_frames.size();
}


/*
*/
bool BowlingGame::Players::Player::setPlayerName(const std::string &name)
{
    if ((m_Name != name))
	{
        m_Name = name;
		return true;
	}
	return false;
}

/*
*/
std::string BowlingGame::Players::Player::playerName()
{
    return m_Name;
}

/*
 calculte each frame scrore
*/
const uint16_t &BowlingGame::Players::Player::calculateFrameScore()
{
    m_finalScore = 0;

    for (uint16_t frame = 0; frame < MAX_NUMBER_OF_FRAME; ++frame)
    {
        uint16_t frameScore = 0;
        const auto &curr = m_frames[frame];

        if (frame == MAX_NUMBER_OF_FRAME - 1) // 10th frame
        {
            frameScore = curr->getFirstThrowScore() +
                         curr->getSecondThrowScore() +
                         curr->getThirdThrowScore();  // must include this
        }
        else if (curr->isStrike())
        {
            frameScore = 10;
            if (frame + 1 < MAX_NUMBER_OF_FRAME)
            {
                const auto &next = m_frames[frame + 1];
                frameScore += next->getFirstThrowScore();

                if (next->isStrike())
                {
                    // Look ahead to next frame if possible
                    if (frame + 2 < MAX_NUMBER_OF_FRAME)
                    {
                        frameScore += m_frames[frame + 2]->getFirstThrowScore();
                    }
                    else
                    {
                        // Frame 9 strike, Frame 10 strike: take second throw from 10th
                        frameScore += next->getSecondThrowScore();
                    }
                }
                else
                {
                    frameScore += next->getSecondThrowScore();
                }
            }
        }
        else if (curr->isSpare())
        {
            frameScore = 10;
            if (frame + 1 < MAX_NUMBER_OF_FRAME)
            {
                frameScore += m_frames[frame + 1]->getFirstThrowScore();
            }
        }
        else
        {
            frameScore = curr->getFirstThrowScore() + curr->getSecondThrowScore();
        }

        m_finalScore += frameScore;
        std::cout << "Frame {" << (frame + 1) << "} = " << m_finalScore << "\n";
    }

    return m_finalScore;
}
/*
Getter function for Final score
*/
const uint16_t &BowlingGame::Players::Player::getFinalScore()
{
	return m_finalScore;
}

/*
   Getting the score for each throw depending upon the frame number
*/
void BowlingGame::Players::Player::getThrowScore()
{
    uint16_t throw1Score{0}, throw2Score{0}, throw3Score{0};

    for (uint16_t frame = 0; frame < MAX_NUMBER_OF_FRAME; ++frame)
    {
        uint16_t throwNum = 1;

        throw1Score = getEachThrowScoreUser(frame, throwNum++);
        m_frames[frame]->setFirstThrowScore(throw1Score);

        // Handle 10th frame separately
        if (frame == MAX_NUMBER_OF_FRAME - 1)
        {
            if (m_frames[frame]->isStrike())
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum++);
                m_frames[frame]->setSecondThrowScore(throw2Score);

                throw3Score = getEachThrowScoreUser(frame, throwNum);
                m_frames[frame]->setThirdThrowScore(throw3Score);
            }
            else
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum++, throw1Score);
                m_frames[frame]->setSecondThrowScore(throw2Score);

                if (m_frames[frame]->isSpare())
                {
                    throw3Score = getEachThrowScoreUser(frame, throwNum);
                    m_frames[frame]->setThirdThrowScore(throw3Score);
                }
            }

            m_frames[frame]->setFrameScore(throw1Score + throw2Score + throw3Score);
        }
        else
        {
            if (throw1Score < MAX_THROW_VALUE)
            {
                throw2Score = getEachThrowScoreUser(frame, throwNum, throw1Score);
                m_frames[frame]->setSecondThrowScore(throw2Score);
            }

            m_frames[frame]->setFrameScore(throw1Score + throw2Score);
        }

        // Reset for next frame
        throw1Score = throw2Score = throw3Score = 0;
    }
}

/*
*/
bool BowlingGame::Players::Player::setthrowValue(const uint16_t &throwNumber, const uint16_t &frameIndex, const uint16_t &Score)
{
    bool flag{false};
    if (frameIndex < 0 || frameIndex >= MAX_NUMBER_OF_FRAME)
	{
		return false;
	}
    if(throwNumber == THROW_ONE)
         flag = m_frames[frameIndex]->setFirstThrowScore(Score);

    else if(throwNumber == THROW_SECOND)
        flag = m_frames[frameIndex]->setSecondThrowScore(Score);

    else if(throwNumber == THROW_THREE)
        flag = m_frames[frameIndex]->setThirdThrowScore(Score);

    return flag;
}


uint16_t BowlingGame::Players::Player::getEachThrowScoreUser(const uint16_t &frameIndex, const uint16_t &throwNum, const uint16_t &prevthrowValue)
{
    bool checkScoreValue{false};
    uint16_t throwValue{0};
    do
    {
        std::cout << "Frame:{" << (frameIndex + 1) << "}" << "throw{" << throwNum << "}:";
        std::cin >> throwValue;
        checkScoreValue = isScoreValueValid(throwValue + prevthrowValue);
        if (!checkScoreValue)
        {
            std::cout << "Please enter valid score (0-10)\n";
        }
    } while (!checkScoreValue);
    return throwValue;
}

bool BowlingGame::Players::Player::isScoreValueValid(const uint8_t &throwValue)
{
    if ((throwValue < LEAST_THROW_VALUE) || (throwValue > MAX_THROW_VALUE))
    {
        return false;
    }
    return true;
}


bool isValidFrameScore(uint8_t firstRoll, uint8_t secondRoll) {
    return (firstRoll <= 10 && secondRoll <= 10 && (firstRoll + secondRoll) <= 10);
}


