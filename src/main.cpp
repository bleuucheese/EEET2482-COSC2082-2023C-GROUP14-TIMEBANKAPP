#include <iostream>
#include <string>
#include "TimeBankSystem.h"
using std::cin;
using std::cout;

int main()
{
    TimeBankSystem sys;
    sys.loadData();
    sys.automaticallyUpdate();
    sys.welcomeScreen();
    sys.systemMenu();
    sys.saveData();
    sys.clearData();

    return 0;
}