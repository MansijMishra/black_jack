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

        void ScoreTally(int player_hand=0, int dealer_hand=0);

        void print_score(char player_print_score, char dealer_print_score);

    public:

        string username;

        BlackJack(string user_input);

        int DeckValues(string card_obj);

        void Shuffle();

        void PrintDeck();

        int Deal();
        
        void GamePlay();

};

#endif