// BowlingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyPlayer.h"
#include "BowlingApp.h"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    /* uncommnet this line if you wnat to run the gtest */
    //::testing::InitGoogleTest(&argc, argv);
    std::cout << "Bowling Game!!!\n";
    BowlingGame::App::BowlingApp bowlingAppObj;
    std::string player1_Name{"Tata Technolgies"} ;
    if (bowlingAppObj.setPlayer(player1_Name))// Display name of player on console
    {
        std::cout<<"\nPlayer "<<player1_Name<<" "<<" is playing bowling game"<<"\n";
    }

    //You can add any number of players here.
    bowlingAppObj.run();
    return 0;

    //return RUN_ALL_TESTS();

}
