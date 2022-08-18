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

        void CardInit();

    public:

        BlackJack(std::string username);

        int DeckValues(string card_obj);

        void Shuffle();

        void PrintDeck();

        int Deal();

};

#endif