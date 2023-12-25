#include <iostream>
#include <string>
#include "TimeBankSystem.h"
using std::cin;
using std::cout;

int main()
{
    TimeBankSystem sys;
    sys.loadData();
    sys.welcomeScreen();
    sys.systemMenu();
    sys.logout();
    sys.saveData();

    return 0;
}