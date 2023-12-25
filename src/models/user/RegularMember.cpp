#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "./User.h"
#include "../skill/Review.h"
#include "../skill/Skill.h"
#include "RegularMember.h"

// Define ANSI escape codes for text formatting
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

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
        // cout << this->skills[i] << ", "; // Print the address of the skill
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
    int count = 0;              // Count the number of reviews with skill rating score > 0 (1->5)
    // Calculate the average skill rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        if ((this->sentreceivedReviews[i])->getSkillRating() != 0)
        {
            this->skillRatingScore += (this->sentreceivedReviews[i])->getSkillRating();
            count++;
        }
    }
    return (float)this->skillRatingScore / count;
}

float RegularMember::getSupporterRatingScore()
{
    if (this->sentreceivedReviews.size() == 0)
    {
        return this->supporterRatingScore;
    }
    this->supporterRatingScore = 0; // Reset the supporter rating score before calculating
    int count = 0;                  // Count the number of reviews with supporter rating score > 0 (1->5)
    // Calculate the average supporter rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        if ((this->sentreceivedReviews[i])->getSupporterRating() != 0)
        {
            this->supporterRatingScore += (this->sentreceivedReviews[i])->getSupporterRating();
            count++;
        }
    }
    return (float)this->supporterRatingScore / count;
}

float RegularMember::getHostRatingScore()
{
    if (this->sentreceivedReviews.size() == 0)
    {
        return this->hostRatingScore;
    }
    this->hostRatingScore = 0;
    int count = 0; // Count the number of reviews with host rating score > 0 (1->5)
    // Calculate the average host rating score
    for (int i = 0; i < this->sentreceivedReviews.size(); i++)
    {
        if ((this->sentreceivedReviews[i])->getHostRating() != 0)
        {
            this->hostRatingScore += (this->sentreceivedReviews[i])->getHostRating();
            count++;
        }
    }
    return (float)this->hostRatingScore / count;
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
    // Define ANSI escape codes for bold and blue text
    const std::string BOLD_BLUE = "\033[1;34m"; // Bold Blue

    std::cout << BOLD_BLUE << "Username:" << RESET << " " << getUsername() << "\n";
    std::cout << BOLD_BLUE << "Password:" << RESET << " " << getPassword() << "\n";
    std::cout << BOLD_BLUE << "Active status:" << RESET << " " << getIsAuthenticated() << "\n";
    std::cout << BOLD_BLUE << "Full Name:" << RESET << " " << fullName << "\n";
    std::cout << BOLD_BLUE << "Credit card Number:" << RESET << " " << creditCardNumber << "\n";
    std::cout << BOLD_BLUE << "Balance:" << RESET << " " << balance << "\n";
    std::cout << BOLD_BLUE << "Credit Points:" << RESET << " " << creditPoints << "\n";
    std::cout << BOLD_BLUE << "Phone Number:" << RESET << " " << phoneNumber << "\n";
    std::cout << BOLD_BLUE << "Email:" << RESET << " " << email << "\n";
    std::cout << BOLD_BLUE << "Home Address:" << RESET << " " << homeAddress << "\n";
    std::cout << BOLD_BLUE << "City:" << RESET << " ";
    if (city == Hanoi)
    {
        std::cout << "Hanoi\n";
    }
    else
    {
        std::cout << "Saigon\n";
    }
    std::cout << BOLD_BLUE << "Balance:" << RESET << " " << balance << "\n";

    // Print skills added by the member
    std::cout << BOLD_BLUE << "Skills:" << RESET << " ";
    if (skills.empty())
    {
        std::cout << "N/A";
    }
    else
    {
        for (size_t i = 0; i < skills.size(); ++i)
        {

            std::cout << skills[i]->getSkillID();
            if (i != skills.size() - 1)
            {
                std::cout << ", ";
            }
        }
    }
    std::cout << "\n";

    // Print listings created by the member
    std::cout << BOLD_BLUE << "Listings:" << RESET << " ";
    if (skillListings.empty())
    {
        std::cout << "N/A";
    }
    else
    {
        for (size_t i = 0; i < skillListings.size(); ++i)
        {

            std::cout << skillListings[i]->getListingID();
            if (i != skillListings.size() - 1)
            {
                std::cout << ", ";
            }
        }
    }
    std::cout << "\n";

    // Print blocked members' usernames
    std::cout << BOLD_BLUE << "Blocked Members:" << RESET << " ";
    if (blockedMembers.empty())
    {
        std::cout << "N/A";
    }
    else
    {
        for (size_t i = 0; i < blockedMembers.size(); ++i)
        {

            std::cout << blockedMembers[i]->getUsername();
            if (i != blockedMembers.size() - 1)
            {
                std::cout << ", ";
            }
        }
    }
    std::cout << "\n";
    // Pending requests counts
    int countRequest = 0;

    for (int i = 0; i < sentreceivedRequests.size(); i++)
    {
        if (sentreceivedRequests[i]->getReceiverName() == this->getUsername() && sentreceivedRequests[i]->getRequestStatus() == "Pending")
        {
            countRequest++;
        }
    }
    std::cout << BOLD_BLUE << "Pending Requests:" << RESET << " " << countRequest << "\n";

    // Rating scores
    std::cout << BOLD_BLUE << "Skill Rating Score:" << RESET << " " << getSkillRatingScore()  << "\n";
    std::cout << BOLD_BLUE << "Supporter Rating Score:" << RESET << " " << getSupporterRatingScore() << "\n";
    std::cout << BOLD_BLUE << "Host Rating Score:" << RESET << " " << getHostRatingScore() << "\n";

    // End with an empty line
    std::cout << "\n";
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

bool RegularMember::sellCredits(int credPoints)
{
    if (credPoints < 0)
    {
        cout << "Invalid amount!\n";
        return false;
    }

    if (credPoints > this->creditPoints)
    {
        cout << "You don't have enough credit points!\n";
        return false;
    }
    // Exchange rate, the admin will profit 10% for commission fee: 1 credit point = $0.9
    this->balance += credPoints * 0.9;
    this->creditPoints -= credPoints;
    return true;
}

bool RegularMember::blockMember(RegularMember &memberToBlock)
{
    for (int i = 0; i < this->blockedMembers.size(); i++)
    {
        if (this->blockedMembers[i]->getUsername() == memberToBlock.getUsername())
        {
            cout << "You have already blocked this member! Try again later.\n";
            return false;
        }
    }
    this->blockedMembers.push_back(&memberToBlock);
    return true;
}

// int main()
// {
//     RegularMember mem1("ha", "123", "Ha", "123", "ha@gmail.com", "123", Hanoi, 0, 0, "123", 0, 0, 0, 0);
//     RegularMember mem2("bluchi", "123", "Bluchi", "123", "bluchi@gmail.com", "123", Saigon, 0, 0, "123", 0, 0, 0, 0);

//     mem1.showInfo();
//     return 0;
// }