#include "game.h"
#include <iostream>
#include <map>
#include <string>
#include <list>
#include <ctime>
#include <vector>

using std::vector;
using std::map;
using std::list;
using std::string;
using std::pair;


BlackJack::BlackJack(std::string username)
{
    std::cout << "Welcome " << username << std::endl;

    CardInit();
    Shuffle();

    std::cout << "Deck Initialized!" << std::endl;

}

void BlackJack::CardInit()
{
    string suites[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    string names[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};   

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            cards.push_back(names[j] + " of " + suites[i]);
        }
    }
}


int BlackJack::DeckValues(string card_obj)
{
    if(card_obj[0] == 'A')
        return 1;
    else if(card_obj[0] == '2')
        return 2;
    else if(card_obj[0] == '3')
        return 3;
    else if(card_obj[0] == '4')
        return 4;
    else if(card_obj[0] == '5')
        return 5;
    else if(card_obj[0] == '6')
        return 6;
    else if(card_obj[0] == '7')
        return 7;
    else if(card_obj[0] == '8')
        return 8;
    else if(card_obj[0] == '9')
        return 9;
    else
        return 10;
}   

void BlackJack::Shuffle()
{
    srand(time(NULL));

    for (int i = 0; i < 52 ; i++)
    {
        int swap_index = rand() % 52;
        string temp = cards[i];
        cards[i] = cards[swap_index];
        cards[swap_index] = temp;

    }
}


void BlackJack::PrintDeck()
{
    for(auto elem : cards)
    {
        std::cout << elem << std::endl;
    }
}


int BlackJack::Deal()
{
    if(cards.size() == 0)
        return 0;
    
    string temp = cards[cards.size()-1];
    cards.pop_back();
    std::cout << temp << std::endl;
    return DeckValues(temp);

}


void BlackJack::ScoreTally(int player_hand, int dealer_hand, string display_score)
{
    player_score += player_hand;
    dealer_score += dealer_hand;

    if(display_score == "Y")
    {
        std::cout << "DEALER: " << dealer_score << " POINTS" << std::endl;
        std::cout << "PLAYER: " << player_score << " POINTS" << std::endl;
    }
}