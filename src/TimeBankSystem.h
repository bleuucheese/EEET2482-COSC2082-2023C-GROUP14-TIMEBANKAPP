#ifndef TIMEBANKSYSTEM_H
#define TIMEBANKSYSTEM_H

#include <iostream>
#include <vector>
#include "./models/user/RegularMember.h"
using std::cout;
using std::cin;

class TimeBankSystem
{
    private:
        std::vector<RegularMember> memberList;
        std::vector<Request> requestList;
        std::vector<SkillListing> skillListingList;

    public:
        TimeBankSystem();
        void welcomeScreen();
        void guestMenu();
        void regularMemberMenu();
        void adminMenu();
};

#endif // TIMEBANKSYSTEM_H