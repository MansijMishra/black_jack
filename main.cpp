#include <iostream>
#include "game.h"

using std::cout;

int main()
{
    BlackJack bjack("Epickaratedude02");
    bjack.PrintDeck();
    cout << "------------------------" << std::endl;
    bjack.Shuffle();
    bjack.PrintDeck();

    return 0;
}