#include <iostream>
#include <string>

#include "TimeBankSystem.h"
using std::cin;
using std::cout;


// Constructor
TimeBankSystem::TimeBankSystem()
{
}

void TimeBankSystem::welcomeScreen()
    {
        cout << "EEET2482/COSC2082 ASSIGNMENT\n";
        cout << "TIME BANK APPLICATION\n\n";

        cout << "Instructor: Mr. Tran Duc Linh\n";
        cout << "Group: Group 13 - HD Destroyers\n";
        cout << "Trinh Nguyen Ha (s3981134)\n";
        cout << "Chau Chan Thien (s3975010)\n";
        cout << "Chau Chan Bang (s3975015)\n";
        cout << "Tran Manon Ophelie (s3968993)\n";
        cout << "============================================\n"; //  For Hanoians and Saigonese only

        cout << "Use the application as: ";
        cout << "1. Guest ";
        cout << "2. Member ";
        cout << "3. Admin\n";
    }

int main()
{
    TimeBankSystem sys;
    sys.welcomeScreen();
    return 0;
}