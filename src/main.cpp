#include <iostream>
#include <string>
#include "TimeBankSystem.h"
using std::cin;
using std::cout;

int main()
{
    TimeBankSystem sys;
    sys.welcomeScreen();
    int choice;
    do
    {
        cout << "Enter your choice: ";

        cin >> choice;
    } while (choice < 1 || choice > 3);
    switch(choice) {
        
    }

        return 0;
}