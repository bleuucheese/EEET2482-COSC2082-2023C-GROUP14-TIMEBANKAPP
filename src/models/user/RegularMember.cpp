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
RegularMember::RegularMember(string username, string password, string fullName, string phoneNumber, string email, string homeAddress, allowedCities city, double latitude, double longitude, string creditCardNumber, float balance, int creditPoints, float skillRatingScore, float supporterRatingScore, float hostRatingScore) : User(username, password, "RegularMember")
{

    this->fullName = fullName;
    this->creditPoints = creditPoints;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->homeAddress = homeAddress;
    this->city = city;
    this->latitude = latitude;
    this->longitude = longitude;
    this->creditCardNumber = creditCardNumber;
    this->balance = balance;
    this->skillRatingScore = skillRatingScore;
    this->supporterRatingScore = supporterRatingScore;
    this->hostRatingScore = hostRatingScore;
}

void RegularMember::printReceivedReviews()
{
    if (this->sentreceivedReviews.size() == 0)
    {
        cout << "You have not received any reviews yet!\n";
        return;
    }
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        (this->sentreceivedReviews[i])->printReview();
    }
}

void RegularMember::printSkills()
{
    if (this->skills.size() == 0)
    {
        cout << "You have not added any skills yet!\n";
        return;
    }
    for (int i = 0; i < this->skills.size(); i++)
    {
        cout << this->skills[i] << ", ";
        if (i == this->skills.size() - 1)
        {
            (this->skills[i])->showInfo();
        }
    }
}

float RegularMember::getSkillRatingScore()
{
    if (this->sentreceivedReviews.size() == 0)
    {
        return this->skillRatingScore;
    }
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
    if (this->sentreceivedReviews.size() == 0)
    {
        return this->supporterRatingScore;
    }
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
    if (this->sentreceivedReviews.size() == 0)
    {
        return this->hostRatingScore;
    }
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
    cout << "City: ";
    if ((this->city) == 24)
    {
        cout << "Hanoi"
             << "\n";
    }
    else
    {
        cout << "Saigon"
             << "\n";
    };
    cout << "Balance: " << this->balance << "\n";
    cout << "Skills:\n";
    printSkills();
    cout << "Skill rating score: " << getSkillRatingScore() << "\n";
    cout << "Supporter rating score: " << getSupporterRatingScore() << "\n";
    cout << "Host rating score: " << getHostRatingScore() << "\n";
    cout << "Received reviews: \n";
    printReceivedReviews();
}

void RegularMember::printRestrictedMemberInfo()
{
    cout << "Username: " << this->getUsername() << "\n";
    cout << "Credit points: " << this->creditPoints << "\n"; // 20 credit points for each new member
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Home address: " << this->homeAddress << "\n";
    cout << "City: ";
    if ((this->city) == 24)
    {
        cout << "Hanoi"
             << "\n";
    }
    else
    {
        cout << "Saigon"
             << "\n";
    };
    cout << "Skills: ";
    printSkills();
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

// int main()
// {
//     RegularMember mem1("ha", "123", "Ha", "123", "ha@gmail.com", "123", Hanoi, 0, 0, "123", 0, 0, 0, 0);
//     RegularMember mem2("bluchi", "123", "Bluchi", "123", "bluchi@gmail.com", "123", Saigon, 0, 0, "123", 0, 0, 0, 0);

//     mem1.showInfo();
//     return 0;
// }