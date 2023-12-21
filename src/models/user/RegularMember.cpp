#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "./User.h"
#include "../skill/Review.h"
#include "../skill/Skill.h"
#include "RegularMember.h"

using std::cin;
using std::cout;
using std::string;

// Constructor
RegularMember::RegularMember(string username = "", string password = "", string fullName = "", string phoneNumber = "", string email = "", string homeAddress = "", allowedCities city, double latitude, double longitude, string creditCardNumber = "", float balance = 0) : User(username, password, "RegularMember")
{

    this->fullName = fullName;
    this->creditPoints = 20;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->homeAddress = homeAddress;
    this->city = city;
    this->latitude = latitude;
    this->longitude = longitude;
    this->creditCardNumber = creditCardNumber;
    this->balance = balance;
    this->skillRatingScore = 0;
    this->supporterRatingScore = 0;
    this->hostRatingScore = 0;
}

void RegularMember::printReceivedReviews()
{
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        (this->sentreceivedReviews[i])->printReview();
    }
}

float RegularMember::getSkillRatingScore()
{
    this->skillRatingScore = 0; // Reset the skill rating score before calculating
    // Calculate the average skill rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        this->skillRatingScore += (this->sentreceivedReviews[i])->getSkillRating();
    }
    return (float)this->skillRatingScore / this->sentreceivedReviews.size();
}

float RegularMember::getSupporterRatingScore()
{
    this->supporterRatingScore = 0; // Reset the supporter rating score before calculating
    // Calculate the average supporter rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        this->supporterRatingScore += (this->sentreceivedReviews[i])->getSupporterRating();
    }
    return (float)this->supporterRatingScore / this->sentreceivedReviews.size();
}

float RegularMember::getHostRatingScore()
{
    this->hostRatingScore = 0;
    // Calculate the average host rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        this->hostRatingScore += (this->sentreceivedReviews[i])->getHostRating();
    }
    return (float)this->hostRatingScore / this->sentreceivedReviews.size();
}

// Pay to the system for the registration fee
bool RegularMember::payRegistrationFee()
{
    if (this->balance < 20)
    {
        cout << "You don't have enough money to pay for the registration fee!\n";
        return false;
    }
    else
    {
        this->balance -= 20;
        return true;
    }
}

// Calculate the distance between a host and a supporter
double RegularMember::calculateDistance(RegularMember &otherMember)
{
    long double lat1, lon1, lat2, lon2;
    lat1 = this->latitude;
    lon1 = this->longitude;
    lat2 = otherMember.latitude;
    lon2 = otherMember.longitude;

    const int R = 6371; // Radius of the Earth in kilometers
    double latDistance = (lat2 - lat1) * M_PI / 180.0;
    double lonDistance = (lon2 - lon1) * M_PI / 180.0;
    double a = sin(latDistance / 2) * sin(latDistance / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(lonDistance / 2) * sin(lonDistance / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c * 1000;
}

void RegularMember::showInfo()
{
    cout << "Username: " << this->getUsername() << "\n";
    cout << "Credit points: " << this->creditPoints << "\n"; // 20 credit points for each new member
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Home address: " << this->homeAddress << "\n";
    cout << "City: " << this->city << "\n"; // Hanoi or Saigon only
    cout << "Balance: " << this->balance << "\n";
    cout << "Skills: ";
    for (int i = 0; i < this->skills.size(); i++)
    {
        (this->skills[i])->showInfo();
    }
    cout << "\n";
    cout << "Skill rating score: " << getSkillRatingScore() << "\n";
    cout << "Supporter rating score: " << getSupporterRatingScore() << "\n";
    cout << "Host rating score: " << getHostRatingScore() << "\n";
    cout << "Received reviews: \n";
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        (this->sentreceivedReviews[i])->printReview();
    }
}

void RegularMember::printRestrictedMemberInfo()
{
    cout << "Username: " << this->getUsername() << "\n";
    cout << "Credit points: " << this->creditPoints << "\n"; // 20 credit points for each new member
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Home address: " << this->homeAddress << "\n";
    cout << "City: " << this->city << "\n"; // Hanoi or Saigon only
    cout << "Skills: ";
    for (int i = 0; i < this->skills.size(); i++)
    {
        cout << this->skills[i] << ", ";
        if (i == this->skills.size() - 1)
        {
            cout << this->skills[i];
        }
    }
    cout << "\n";
}

bool RegularMember::topUp(int credPoints)
{
    cout << "Enter the amount you want to top up: ";
    cin >> credPoints;
    if (credPoints < 0)
    {
        cout << "Invalid amount!\n";
        return false;
    }
    if (credPoints > 1000)
    {
        cout << "You can only top up up to $1000!\n";
        return false;
    }
    if (credPoints > this->balance)
    {
        cout << "You don't have enough money in your bank account!\n";
        return false;
    }

    this->balance -= credPoints;
    this->creditPoints += credPoints;
    return true;
}