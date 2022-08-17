#ifndef GAME_H
#define GAME_H

#include <iostream>

class BlackJack
{
    public:

        BlackJack(std::string username);

        void CardInit();

        void DeckValues();

        void Shuffle();

};

#endif