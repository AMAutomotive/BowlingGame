#pragma once

#include "MyPlayer.h"
#include "Constants.h"

namespace BowlingGame::App
{

    class BowlingApp
	{

    private:
        BowlingGame::Players::Player m_player;

	public:
        BowlingApp() = default;
        ~BowlingApp() = default;

		/*
        set player name in the bowling App
		*/
        bool setPlayer(std::string name);

		/*
        start  game river method
        */
        void run();
	};

}
