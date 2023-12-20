#include <iostream>
#include "Skill.h"

using std::cout;
using std::cin;

Skill::Skill(string skillName, string description, std::string skillEfficiency)
{
    this->skillName = skillName;
    this->description = description;
    this->skillEfficiency = skillEfficiency;
}

void Skill::showInfo()
{
    cout << "Skill ID: " << this->skillID << "\n";
    cout << "Skill Name: " << this->skillName << "\n";
    cout << "Description: " << this->description << "\n";
    cout << "Skill Efficiency: " << this->skillEfficiency << "\n";
}