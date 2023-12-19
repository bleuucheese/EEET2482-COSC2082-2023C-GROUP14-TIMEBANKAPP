#include <iostream>
#include <string>
#include "SkillListing.h"
using std::cin;
using std::cout;
using std::string;

// Constructor
SkillListing::SkillListing(string skillPerformed = "", int consumedCredsPerHour = 0, int minHostRatingScore = -1, int listingState = 0, RegularMember *pOwner = nullptr)
{
    this->skillPerformed = skillPerformed;
    this->consumedCredsPerHour = consumedCredsPerHour;
    this->minHostRatingScore = minHostRatingScore;
    this->listingState = listingState;
    this->pOwner = pOwner;
};

// Methods
void SkillListing::displaySkillListing()
{
    cout << "Perform skill: " << this->skillPerformed << "\n";
    cout << "Cost: " << this->consumedCredsPerHour << "\n";
    cout << "Minimum Host Rating Score: " << this->minHostRatingScore << "\n";
    cout << "Listing State: " << this->listingState << "\n";
    cout << "Owner: " << this->pOwner->getUsername() << "\n";
};