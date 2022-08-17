#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>

using std::string;

class BlackJack
{
    private:

        std::vector<string> cards;

    public:

        BlackJack(std::string username);

        void CardInit();

        void DeckValues();

        void Shuffle();

        void PrintDeck();

};

#endif