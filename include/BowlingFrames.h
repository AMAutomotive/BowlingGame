#pragma once
#include "Constants.h"

namespace BowlingGame::Frame
{
	class Frame
	{
	public:
		Frame();
		virtual ~Frame() = default;

		/*
        store the first throw score for each frame
		*/
        virtual bool setFirstThrowScore(const uint16_t &throwValue);

		/*
        return score value of first throw for each frame
		*/
        virtual const uint16_t &getFirstThrowScore() const;

		/*
        store the second throw score for each frame
		*/
        virtual bool setSecondThrowScore(const uint16_t &throwValue);

		/*
        \return score value of second throw for each frame
		*/
        virtual const uint16_t &getSecondThrowScore() const;

		/*
         check is frame is strike frame
		*/
		virtual const bool &isStrike() const;

		/*
        check is frame is spare in each frame
		*/
		virtual const bool &isSpare() const;

		/*
        store each the frame score
		*/
		virtual bool setFrameScore(const uint16_t &frameScore);

		/*
        return score value of each frame
		*/
		virtual const uint16_t &getFrameScore() const;

		/*
        store the third throw score of 10th frame
		*/
        virtual bool setThirdThrowScore(const uint16_t &throwValue);

		/*
        return score value of third roll of 10th frame
		*/
        virtual uint16_t getThirdThrowScore() const;

		/*
        check the throw score is valid or not
		*/
        bool checkScoreValue(const uint8_t &throwValue);

	protected:
        uint16_t firstThrow;
        uint16_t secondThrow;
        uint16_t eachFrameScore;
        bool isStrikeFlag;
        bool isSpareFlag;
	};

    class LastTenthFrame : public Frame
	{
        //This is special 10th frame having 3 rolls.
	public:
        LastTenthFrame();
        ~LastTenthFrame() = default;

		/*
        store the third roll score of 10th frame
		*/
        bool setThirdThrowScore(const uint16_t &throwValue);

		/*
        return score value of third roll of 10th frame
		*/
        uint16_t getThirdThrowScore() const;

        uint16_t m_thirdThrow;
	};
};
