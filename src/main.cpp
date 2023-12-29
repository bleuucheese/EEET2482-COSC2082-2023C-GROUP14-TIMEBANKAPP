#include <iostream>
#include <string>
#include "TimeBankSystem.h"
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

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