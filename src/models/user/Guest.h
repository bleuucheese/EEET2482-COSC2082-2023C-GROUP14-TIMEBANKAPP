#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_GUEST_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_GUEST_H

#include <iostream>
#include <string>
#include "User.h"

class Guest : public User
{
public:
    // Constructor
    Guest() : User("", "", "Guest"){};
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_GUEST_H