#include <iostream>
#include <string>
#include "SkillListing.h"
#include "Skill.h"
#include "myUtils.h"
using std::cin;
using std::cout;
using std::string;

// Constructor
SkillListing::SkillListing(Skill *skillPerformed = nullptr, int consumedCreds = 0, float minHostRatingScore = -1, string supporterName = "", string hostName = "")
{
    this->skillPerformed = skillPerformed;
    this->consumedCredsPerHour = consumedCredsPerHour;
    this->minHostRatingScore = minHostRatingScore;
    this->listingState = 0;
    this->listingID = "L" + generateRandomID();
};

// Methods
void SkillListing::displaySkillListing()
{
    if (this->skillPerformed != nullptr)
    {
        cout << "Perform skill: ";
        (this->skillPerformed)->showInfo();
        cout << "Cost: " << this->consumedCredsPerHour << "\n";
        cout << "Minimum Host Rating Score: " << this->minHostRatingScore << "\n";
        cout << "Listing State: " << this->listingState << "\n";
        cout << "Owner: " << this->supporterName << "\n";
        cout << "Host: " << this->hostName << "\n";
    }
    else
    {
        cout << "Error in displaying skill listing due to null pointer to Skill\n";
    }
};