#include <iostream>
#include <string>
#include "Admin.h"
using std::cout;
using std::cin;
using std::string;

// Constructor
    Admin::Admin(float revenue = 0) : User("admin", "123", "Admin")
    {
        this->revenue = revenue;
    };