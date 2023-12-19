#ifndef TIMEBANKSYSTEM_H
#define TIMEBANKSYSTEM_H

#include <iostream>
using std::cout;
using std::cin;

class TimeBankSystem
{
    private:

    public:
        TimeBankSystem();
        void welcomeScreen();
        void guestMenu();
        void regularMemberMenu();
        void adminMenu();
};

#endif // TIMEBANKSYSTEM_H