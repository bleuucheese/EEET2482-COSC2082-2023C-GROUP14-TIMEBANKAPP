#include <iostream>
#include <string>
#include "SkillListing.h"
#include "Skill.h"
#include "../../utils/myUtils.h"

using std::cin;
using std::cout;
using std::string;

// Constructor implementation without default arguments
SkillListing::SkillListing(string listingID, string skillID, int consumedCreds, float minHostRatingScore, int listingState, string supporterName, string hostName, Period workingTimeSlot)
{
    // this->skillPerformed = skillPerformed;
    this->supporterName = supporterName;
    this->hostName = hostName;
    this->workingTimeSlot = workingTimeSlot;
    this->consumedCredsPerHour = consumedCreds;
    this->minHostRatingScore = minHostRatingScore;
    this->listingState = listingState;
    this->listingID = "L" + generateRandomID();
    this->skillID = skillID;
}

// Methods
void SkillListing::displaySkillListing()
{
    cout << "Listing ID: " << this->listingID << "\n";
    cout << "Skill Perform: " << this->skillID << "\n";
    cout << "Cost: " << this->consumedCredsPerHour << "\n";
    cout << "Minimum Host Rating Score: " << this->minHostRatingScore << "\n";
    cout << "Listing State: " << this->listingState << "\n";
    cout << "Owner: " << this->supporterName << "\n";
    cout << "Host: " << this->hostName << "\n";
    cout << "Working Time Slot: " << this->workingTimeSlot.getFormattedPeriod() << "\n";
};