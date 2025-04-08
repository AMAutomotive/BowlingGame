#pragma once
#include "Constants.h"
#include "BowlingFrames.h"

namespace BowlingGame::Players
{
	class Player
	{

    private:
        std::vector<std::unique_ptr<BowlingGame::Frame::Frame>> m_frames;
        uint16_t m_finalScore;
        uint16_t m_frameNumber;
        std::string m_Name;

        //get the each throw data from user
        inline uint16_t getEachThrowScoreUser(const uint16_t &frameIndex, const uint16_t &throwNum, const uint16_t &prevthrowValue = 0);

        //check the score is valid or not for each throw
        inline bool isScoreValueValid(const uint8_t &throwValue);
        bool isValidFrameScore(uint8_t firstThrow, uint8_t secondThrow);

	public:
		Player();
		~Player() = default;

        //set player name
        bool setPlayerName(const std::string &first_name);

        //return player name
        std::string playerName();

        //calculate the total score from each frame
        const uint16_t &calculateFrameScore();


        //return total score of the player
        const uint16_t &getFinalScore();


        //get the each throw score from user
        void getThrowScore();


        //set the roll score for uint testing
        bool setthrowValue(const uint16_t &throwNumber, const uint16_t &frameIndex, const uint16_t &throwValue);



	};
}
