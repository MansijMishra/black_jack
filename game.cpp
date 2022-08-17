#include "game.h"
#include <iostream>

BlackJack::BlackJack()
{
    std::cout << "Welcome to the game!" << std::endl;
}

int BlackJack::PrintScore(int score)
{
    std::cout << score << std::endl;
}