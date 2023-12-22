#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H

#include <iostream>
#include <string>
using std::string;

class Skill
{

private:
    string skillID; // Sxxxxxxxx
    string skillName;
    string description;
    std::string skillEfficiency;
    std::string ownerName; // username of the member who created the skill

public:
    Skill(string skillID = "",string skillName = "", string description = "", std::string skillEfficiency = "",std::string ownerName = "");

    void showInfo();

    friend class SkillListing;
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILL_H