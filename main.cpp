#include <iostream>
#include "game.h"

using std::cout;

int main()
{
    std::string user;
    std::cout << "Enter Username: ";
    std::cin >> user;
    std::cout << std::endl;
    BlackJack bjack(user);
    
    bjack.GamePlay();
    
    return 0;
}