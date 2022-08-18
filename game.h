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

        int player_score {0};

        int dealer_score {0};

    public:

        BlackJack(std::string username);

        int DeckValues(string card_obj);

        void Shuffle();

        void PrintDeck();

        int Deal();

        void ScoreTally(int player_hand, int dealer_hand, string display_score = "N");

};

#endif