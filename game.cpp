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
using std::cout;


BlackJack::BlackJack(string user_inpt)
{   
    username = user_inpt;

    cout << "USER:  " << username << std::endl;

    CardInit();
    Shuffle();

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


int BlackJack::Deal(string card_owner)
{
    if(cards.size() == 0)
        return 0;
    
    string temp = cards[cards.size()-1];
    cards.pop_back();

    if(card_owner == "PLAYER")
        player_hand.push_back(temp);
    else if(card_owner == "DEALER")
        dealer_hand.push_back(temp);

    return DeckValues(temp);

}


void BlackJack::ScoreTally(int player_hand, int dealer_hand)
{
    player_score += player_hand;
    dealer_score += dealer_hand;
}


void BlackJack::print_score(char player_print_score, char dealer_print_score)
{
    if(player_print_score == 'Y')
        cout << "PLAYER SCORE:" << player_score << std::endl;
        cout << username << "'s Hand: ";

        for(int i = 0; i < player_hand.size(); i++)
        {
            cout << player_hand[i] << " ";
        }
        cout << std::endl;
    
    if(dealer_print_score == 'Y')
        cout << "DEALER SCORE:" << dealer_score << std::endl;
        cout <<  "Dealers's Hand: ";

        for(int i = 0; i < dealer_hand.size(); i++)
        {
            cout << dealer_hand[i] << " ";
        }
        cout << std::endl;
}


void BlackJack::GamePlay()
{
    std::cout << "Welcome to BlackJack" << std::endl;
    std::cout << "..Deck created and shuffled..." << std::endl;

    ScoreTally(Deal("PLAYER"),0);
    ScoreTally(Deal("PLAYER"),0);
    ScoreTally(0,Deal("DEALER"));
    ScoreTally(0,Deal("DEALER"));

    print_score('Y','N');


    if(player_score == 21)
        cout << username << " WINS!" << std::endl;
    
    else if(player_score == 21 && dealer_score == 21)
        cout << "It was a draw..." << std::endl;

    else
    {
        while(true)
        {
            if(player_score > 21)
            {
                cout << username << " Loses..." << std::endl;
                cout << "Dealer WINS!" << std::endl;
                break;
            }
            
            char response;
            cout << "Would you like to draw another card " << username << "?[Y/N]" << std::endl;
            std::cin >> response;

            if(response == 'Y')
            {
                ScoreTally(Deal("PLAYER"),0);
                print_score('Y','N');
            }
            //Implement dealer logic/plays
            else
                break;
        }

    }
}