#include <iostream>
#include "game.h"

using std::cout;

int main()
{
    BlackJack bjack("Epickaratedude02");
    bjack.PrintDeck();
    cout << "------------------------" << std::endl;
    cout << bjack.Deal() << std::endl;
    cout << bjack.Deal() << std::endl;
 

    return 0;
}