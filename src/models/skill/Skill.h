#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H

#include <iostream>
#include <string>
using std::string;

class Skill
{

private:
    string skillID; // S0001, S0002, S0003, ...
    string skillName;
    string description;
    std::string skillEfficiency;

public:
    Skill(string skillName = "", string description = "", std::string skillEfficiency = "");

    void showInfo();
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H