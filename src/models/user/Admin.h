#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_ADMIN_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_ADMIN_H
#include <iostream>
#include <string>
#include "User.h"

using std::string;
class Admin : public User
{
private:
    float revenue; // revenue of the company

public:
    // Constructor
    explicit Admin(float revenue):User("@dmin", "2023", "Admin"){}; // avoid implicit type conversion
    float getRevenue() { return revenue; };
    void setRevenue(float revenue) { this->revenue = revenue; };
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_ADMIN_H