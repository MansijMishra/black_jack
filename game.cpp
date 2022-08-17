#include "game.h"
#include <iostream>
#include <map>
#include <string>
#include <list>
#include <ctime>


using std::map;
using std::list;
using std::string;
using std::pair;


BlackJack::BlackJack(std::string username)
{
    std::cout << "Welcome " << username << std::endl;

    CardInit();

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


void BlackJack::DeckValues()
{
    list<string> one {"A of Spades","A of Hearts","A of Diamonds", "A of Clubs"};
    list<string> two {"2 of Spades","2 of Hearts","2 of Diamonds", "2 of Clubs"};
    list<string> three {"3 of Spades","3 of Hearts","3 of Diamonds", "3 of Clubs"};
    list<string> four {"4 of Spades","4 of Hearts","4 of Diamonds", "4 of Clubs"};
    list<string> five {"5 of Spades","5 of Hearts","5 of Diamonds", "5 of Clubs"};
    list<string> six {"6 of Spades","6 of Hearts","6 of Diamonds", "6 of Clubs"};
    list<string> seven {"7 of Spades","7 of Hearts","7 of Diamonds", "7 of Clubs"};
    list<string> eight {"8 of Spades","8 of Hearts","8 of Diamonds", "8 of Clubs"};
    list<string> nine {"9 of Spades","9 of Hearts","9 of Diamonds", "9 of Clubs"};
    list<string> ten {"10 of Spades","10 of Hearts","10 of Diamonds", "10 of Clubs"
                      "J of Spades","J of Hearts","J of Diamonds", "J of Clubs",
                      "Q of Spades","Q of Hearts","Q of Diamonds", "Q of Clubs",
                      "K of Spades","K of Hearts","K of Diamonds", "K of Clubs"};

    map<int, list<string>> deck;

    deck.insert(pair<int, list<string>>(1,one));
    deck.insert(pair<int, list<string>>(2,two));
    deck.insert(pair<int, list<string>>(3,three));
    deck.insert(pair<int, list<string>>(4,four));
    deck.insert(pair<int, list<string>>(5,five));
    deck.insert(pair<int, list<string>>(6,six));
    deck.insert(pair<int, list<string>>(7,seven));
    deck.insert(pair<int, list<string>>(8,eight));
    deck.insert(pair<int, list<string>>(9,nine));
    deck.insert(pair<int, list<string>>(10,ten));

    /*for(auto pair : deck)
    {
        std::cout << pair.first << " - ";

        for(auto card : pair.second)
        std::cout << card << ", ";


        std::cout << std::endl;
    }*/
    

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