#ifndef TIMEBANKSYSTEM_H
#define TIMEBANKSYSTEM_H

#include <iostream>
#include <vector>
#include "./models/user/RegularMember.h"
#include "./models/skill/Request.h"
#include "./models/skill/SkillListing.h"
#include "./models/skill/Skill.h"
#include "./utils/myUtils.h"
using std::cin;
using std::cout;

class TimeBankSystem
{
private:
    std::vector<User> memberList{};
    std::vector<Request> requestList{};
    std::vector<SkillListing> skillListingList{};
    std::vector<Skill> skillList{};

public:
    TimeBankSystem();
    void addMember(User &user);
    void welcomeScreen();
    void systemMenu();
    void guestMenu();
    void regularMemberMenu();
    void adminMenu();

    void loginMenu();
    void registerMenu();
    void promptLogin();
    void promptLogout();
    void promptRegister();

    bool login(const std::string &username, const std::string &password);
    bool isUniqueUsername(string username);

    int promptAndGetChoice(unsigned min, unsigned max);
};

#endif // TIMEBANKSYSTEM_H