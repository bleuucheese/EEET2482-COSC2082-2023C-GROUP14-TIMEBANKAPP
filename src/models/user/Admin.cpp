#include <iostream>
#include <string>
#include "Admin.h"
using std::cin;
using std::cout;
using std::string;

// Constructor
Admin::Admin(float revenue) : User("@dmin2023", "aptfinalproject", "Admin")
{
    this->revenue = revenue;
};

void Admin::showInfo()
{
    cout << "Username: " << this->getUsername() << "\n";
    cout << "Role: " << this->getRole() << "\n";
    cout << "Revenue of Time Bank company: " << this->revenue << "\n";
}
