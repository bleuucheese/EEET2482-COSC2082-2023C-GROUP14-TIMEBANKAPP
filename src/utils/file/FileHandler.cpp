#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "../../models/user/User.h"
#include "../../models/user/Admin.h"
#include "../../models/user/RegularMember.h"
#include "../../models/skill/Skill.h"
#include "../../models/skill/SkillListing.h"
#include "../../models/skill/Request.h"
#include "../../models/skill/Review.h"
#include "../../utils/myUtils.h"
#include "FileHandler.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

FileHandler::FileHandler()
{
    userFile = "../../databases/users.csv";
    skillFile = "src/databases/skills.csv";
    listingFile = "src/databases/listings.csv";
    reviewFile = "src/databases/reviews.csv";
    requestFile = "src/databases/requests.csv";
}

// Function to split a string into tokens based on a delimiter
std::vector<std::string> FileHandler::splitString(const std::string &input, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

// Function to parse a CSV line and create User/RegularMember objects
RegularMember FileHandler::parseCSVLine(const std::string &csvLine)
{
    std::vector<std::string> fields = splitString(csvLine, ',');

    if (fields.size() != 17)
    {
        throw std::runtime_error("Invalid CSV line format");
    }

    std::string username = fields[0];
    std::string password = fields[1];
    std::string role = fields[2];
    bool isAuthenticated = (fields[3] == "1");
    std::string fullName = fields[4];
    std::string phoneNumber = fields[5];
    std::string email = fields[6];
    std::string homeAddress = fields[7];
    std::string cityCode = fields[8];
    double latitude = std::stod(fields[9]);
    double longitude = std::stod(fields[10]);
    std::string creditCardNumber = fields[11];
    float balance = std::stof(fields[12]);
    float skillRatingScore = std::stof(fields[13]);
    float supporterRatingScore = std::stof(fields[14]);
    float hostRatingScore = std::stof(fields[15]);
    int creditPoints = std::stoi(fields[16]);

    allowedCities city = (cityCode == "24") ? Hanoi : Saigon;

    // Depending on the "role" field, create RegularMember object
    if (role == "RegularMember")
    {
        if (cityCode == "24")
        {
            return RegularMember(username, password, fullName, phoneNumber, email, homeAddress, Hanoi, latitude, longitude, creditCardNumber, balance, skillRatingScore, supporterRatingScore, hostRatingScore);
        }
        else if (cityCode == "28")
        {
            return RegularMember(username, password, fullName, phoneNumber, email, homeAddress, Saigon, latitude, longitude, creditCardNumber, balance, skillRatingScore, supporterRatingScore, hostRatingScore);
        }
    }
}

std::vector<RegularMember> FileHandler::loadUsers(const std::string &filename)
{
    std::vector<RegularMember> memberList;

    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Error opening database file for reading." << std::endl;
        return memberList;
    }

    // Skip the header line
    std::string csvLine;
    std::getline(inFile, csvLine);

    while (std::getline(inFile, csvLine))
    {
        try
        {
            RegularMember user = parseCSVLine(csvLine);
            memberList.push_back(user);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error parsing CSV line: " << e.what() << std::endl;
        }
    }

    inFile.close();

    return memberList;
}

std::string FileHandler::convertToCSV(const RegularMember &user)
{
    std::ostringstream csvLine;
    csvLine << user.username << ","
            << user.password << ","
            << user.role << ","
            << (user.isAuthenticated ? "True" : "False") << ","
            << user.fullName << ","
            << user.phoneNumber << ","
            << user.email << ","
            << user.homeAddress << ","
            << user.city << ","
            << user.latitude << ","
            << user.longitude << ","
            << user.creditCardNumber << ","
            << user.balance << ","
            << user.creditPoints << ","
            << user.skillRatingScore << ","
            << user.supporterRatingScore << ","
            << user.hostRatingScore;
    return csvLine.str();
}

void FileHandler::saveUsers(const std::string &filename, const std::vector<RegularMember> &memberList)
{
    std::ofstream outFile(filename);
    if (!outFile.is_open())
    {
        std::cerr << "Error opening database file for writing." << std::endl;
        return;
    }

    // Write the header line
    outFile << "username,password,role,isAuthenticated,fullname,phoneNumber,email,homeAddress,city,latitude,longitude,creditCardNumber,balance,creditPoints,skillRatingScore,supporterRatingScore,hostRatingScore\n";

    for (const RegularMember &member : memberList)
    {
        std::string csvLine = convertToCSV(member);
        outFile << csvLine << '\n';
    }

    outFile.close();
}

int main()
{
    FileHandler fileHandler;
    std::vector<RegularMember> memberList = fileHandler.loadUsers("../../databases/users.csv");
    for (RegularMember &member : memberList)
    {
        member.showInfo();
    }
    RegularMember newMember("test", "test", "test", "test", "test", "test", Hanoi, 0, 0, "test", 0, 20, 0, 0, 0);
    memberList.push_back(newMember);
    fileHandler.saveUsers("../../databases/users.csv", memberList);
    return 0;
}