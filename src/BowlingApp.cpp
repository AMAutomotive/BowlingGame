#include "BowlingApp.h"
#include <algorithm>

/*
*/
bool BowlingGame::App::BowlingApp::setPlayer(std::string name)
{
    m_player.setPlayerName(name);
    return true;
}

/*
*/
void BowlingGame::App::BowlingApp::run()
{
    std::cout<<"\n"<<m_player.playerName()<<" Game started...\n";
        m_player.getThrowScore();
        if (m_player.calculateFrameScore() == MAX_SCORE)
        {
            std::cout<<"\n Got maximum score!\n";
        }
            std::cout<<"\n"<<m_player.playerName()<<" Game Finished...\n";
}
