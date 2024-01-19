/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082 Advanced Programming Techniques
  Semester: 2023-3
  Assignment: Final Group Project
  Author: Trinh Nguyen Ha (s3981134)
  Compiler used: g++ (MinGW.org GCC-6.3.0-1) 6.3.0
  Created date: 23/12/2023
  Acknowledgement: https://stackoverflow.com/questions/70380743/deleting-a-line-in-a-txt-file-without-using-another-file-or-array-in-c
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib> // for system()

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

FileHandler::FileHandler() {}

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
    float creditPoints = std::stof(fields[13]);
    float skillRatingScore = std::stof(fields[14]);
    float supporterRatingScore = std::stof(fields[15]);
    float hostRatingScore = std::stof(fields[16]);

    allowedCities city = (cityCode == "24") ? Hanoi : Saigon;

    // Depending on the "role" field, create RegularMember object
    if (role == "RegularMember")
    {
        if (cityCode == "24")
        {
            return RegularMember(username, password, fullName, phoneNumber, email, homeAddress, Hanoi, latitude, longitude, creditCardNumber, balance, creditPoints, skillRatingScore, supporterRatingScore, hostRatingScore);
        }
        else if (cityCode == "28")
        {
            return RegularMember(username, password, fullName, phoneNumber, email, homeAddress, Saigon, latitude, longitude, creditCardNumber, balance, creditPoints, skillRatingScore, supporterRatingScore, hostRatingScore);
        }
    }
    else
    {
        throw std::runtime_error("Invalid role: " + role);
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

Admin FileHandler::loadAdmin(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    // Skip the header line
    getline(file, line);

    if (getline(file, line))
    {
        std::stringstream ss(line);
        std::string username, password, role;
        std::string isAuthenticatedStr;
        bool isAuthenticated;
        double revenue;
        char delimiter = ',';

        getline(ss, username, delimiter);
        getline(ss, password, delimiter);
        getline(ss, role, delimiter);
        getline(ss, isAuthenticatedStr, delimiter);
        isAuthenticated = isAuthenticatedStr == "True";
        ss >> revenue;
        // cout << revenue << std::endl;

        return Admin(revenue);
    }
    else
    {
        throw std::runtime_error("File is empty: " + filename);
    }
}

void FileHandler::saveAdmin(const std::string &filename, const Admin &admin)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }
    // write header
    file << "username,password,role,isAuthenticated,revenue" << std::endl;
    file << admin.getUsername() << ','
         << admin.getPassword() << ','
         << admin.getRole() << ','
         << (admin.getIsAuthenticated() ? "True" : "False") << ','
         << admin.getRevenue() << std::endl;
}

std::vector<Skill> FileHandler::loadSkills(const std::string &filename)
{
    std::vector<Skill> skills;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    // Skip the header line
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string skillID, skillName, description, skillEfficiency, ownerName;
        char delimiter = ',';

        getline(ss, skillID, delimiter);
        getline(ss, skillName, delimiter);
        getline(ss, description, delimiter);
        getline(ss, skillEfficiency, delimiter);
        getline(ss, ownerName, delimiter);

        skills.push_back(Skill(skillID, skillName, description, skillEfficiency, ownerName));
    }

    return skills;
}

void FileHandler::saveSkills(const std::string &filename, const std::vector<Skill> &skills)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    // write header
    file << "skillID,skillName,description,skillEfficiency,ownerName" << std::endl;

    for (const auto &skill : skills)
    {
        file << skill.getSkillID() << ','
             << skill.getSkillName() << ','
             << skill.getDescription() << ','
             << skill.getSkillEfficiency() << ','
             << skill.getOwnerName() << std::endl;
    }
}

std::vector<SkillListing> FileHandler::loadListings(const std::string &filename)
{
    std::vector<SkillListing> listings;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    // Skip the header line
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string listingID, skillID, supporterName, hostName;
        int consumedCreds, listingState;
        float minHostRatingScore;
        std::string startDateStr, endDateStr;
        char delimiter = ',';

        getline(ss, listingID, delimiter);
        getline(ss, skillID, delimiter);
        ss >> consumedCreds >> delimiter;
        ss >> minHostRatingScore >> delimiter;
        ss >> listingState >> delimiter;
        getline(ss, supporterName, delimiter);
        getline(ss, hostName, delimiter);
        getline(ss, startDateStr, delimiter);
        getline(ss, endDateStr);

        DateTime startDate(startDateStr), endDate(endDateStr);
        Period workingTimeSlot(startDate, endDate);

        listings.push_back(SkillListing(listingID, skillID, consumedCreds, minHostRatingScore, listingState, supporterName, hostName, workingTimeSlot));
    }

    return listings;
}

void FileHandler::saveListings(const std::string &filename, const std::vector<SkillListing> &listings)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    // write header
    file << "listingID,skillID,consumedCredsPerHour,minHostRatingScore,listingState,supporterName,hostName,startDate,endDate" << std::endl;

    for (const auto &listing : listings)
    {
        file << listing.getListingID() << ','
             << listing.getSkillID() << ','
             << listing.getConsumedCredsPerHour() << ','
             << listing.getMinHostRatingScore() << ','
             << listing.getListingState() << ','
             << listing.getSupporterName() << ','
             << listing.getHostName() << ','
             << listing.getWorkingTimeSlot().getStartDate().getFormattedTimestamp() << ','
             << listing.getWorkingTimeSlot().getEndDate().getFormattedTimestamp() << std::endl;
    }
}

std::vector<Review> FileHandler::loadReviews(const std::string &filename)
{
    std::vector<Review> reviews;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    // Skip the header line
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string reviewID, listingID, comments, reviewer, reviewee, timeStampStr;
        int skillRating, supporterRating, hostRating;
        char delimiter = ',';

        getline(ss, reviewID, delimiter);
        getline(ss, listingID, delimiter);
        ss >> skillRating >> delimiter;
        ss >> supporterRating >> delimiter;
        ss >> hostRating >> delimiter;
        getline(ss, comments, delimiter);
        getline(ss, reviewer, delimiter);
        getline(ss, reviewee, delimiter);
        getline(ss, timeStampStr);

        DateTime timeStamp(timeStampStr);

        if (reviewID[1] == 'S')
        {
            reviews.push_back(Review(reviewID, listingID, skillRating, supporterRating, comments, reviewer, reviewee, timeStamp));
        }
        else if (reviewID[1] == 'H')
        {
            reviews.push_back(Review(reviewID, listingID, comments, reviewer, reviewee, timeStamp, hostRating));
        }
        else
        {
            throw std::runtime_error("Invalid review type in file: " + filename);
        }
    }

    return reviews;
}

void FileHandler::saveReviews(const std::string &filename, const std::vector<Review> &reviews)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    // write header
    file << "reviewID,listingID,skillRating,supporterRating,hostRating,comments,reviewer,reviewee,timestamp" << std::endl;

    for (const auto &review : reviews)
    {
        file << review.getReviewID() << ','
             << review.getListingID() << ','
             << review.getSkillRating() << ','
             << review.getSupporterRating() << ','
             << review.getHostRating() << ','
             << review.getComments() << ','
             << review.getReviewer() << ','
             << review.getReviewee() << ','
             << review.getTimestamp().getFormattedTimestamp() << std::endl;
    }
}

std::vector<Request> FileHandler::loadRequests(const std::string &filename)
{
    std::vector<Request> requests;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    // Skip the header line
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string requestID, listingID, requesterName, receiverName, requestTimeStampStr, requestStatus;
        char delimiter = ',';

        getline(ss, requestID, delimiter);
        getline(ss, listingID, delimiter);
        getline(ss, requesterName, delimiter);
        getline(ss, receiverName, delimiter);
        getline(ss, requestTimeStampStr, delimiter);
        getline(ss, requestStatus);

        DateTime requestTimeStamp(requestTimeStampStr);
        requests.push_back(Request(requestID, listingID, requesterName, receiverName, requestTimeStamp, requestStatus));
    }

    return requests;
}

void FileHandler::saveRequests(const std::string &filename, const std::vector<Request> &requests)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    // write header
    file << "requestID,listingID,requesterName,receiverName,requestTimeStamp,requestStatus" << std::endl;

    for (const auto &request : requests)
    {
        file << request.getRequestID() << ','
             << request.getListingID() << ','
             << request.getRequesterName() << ','
             << request.getReceiverName() << ','
             << request.getRequestTimeStamp().getFormattedTimestamp() << ','
             << request.getRequestStatus() << std::endl;
    }
}

void FileHandler::initDatabase()
{
    std::string databasePath = "./databases";

    // Check and create the directory based on the operating system
    #if defined(_WIN32)
        std::string command = "if not exist \"" + databasePath + "\" mkdir \"" + databasePath + "\"";
    #elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
        std::string command = "mkdir -p " + databasePath;
    #else
    #error "Unknown operating system"
    #endif

    if (system(command.c_str()) != 0)
    {
        std::cerr << "Failed to create directory: " << databasePath << std::endl;
        return;
    }

    // Create the database files
    std::ofstream userFile(databasePath + "/users.csv");
    std::ofstream adminFile(databasePath + "/admin.csv");
    std::ofstream skillFile(databasePath + "/skills.csv");
    std::ofstream listingFile(databasePath + "/listings.csv");
    std::ofstream requestFile(databasePath + "/requests.csv");
    std::ofstream reviewFile(databasePath + "/reviews.csv");
    std::ofstream blockFile(databasePath + "/blocklist.csv");
    std::ofstream ccFile(databasePath + "/samplecards.txt");

    // Check if the files were created successfully and write headers
    if (userFile)
        userFile << "username,password,role,isAuthenticated,fullname,phoneNumber,email,homeAddress,city,latitude,longitude,creditCardNumber,balance,creditPoints,skillRatingScore,supporterRatingScore,hostRatingScore\n";
    if (adminFile)
        adminFile << "username,password,role,isAuthenticated,revenue\n";
    adminFile << "@dmin2023,aptfinalproject,Admin,False,0\n";
    if (skillFile)
        skillFile << "skillID,skillName,description,skillEfficiency,ownerName\n";
    if (listingFile)
        listingFile << "listingID,skillID,cost,minHostRatingScore,listingState,supporterName,hostName,startDate,endDate\n";
    if (requestFile)
        requestFile << "requestID,listingID,requesterName,receiverName,requestTimeStamp,requestStatus\n";
    if (reviewFile)
        reviewFile << "reviewID,listingID,skillRating,supporterRating,comments,reviewer,reviewee,timestamp\n";
    if (blockFile)
        blockFile << "blocker,blockedMember\n";
    if (ccFile)
    {
        ccFile << "# This is a sample of credit card numbers, they are not real, but they are valid according to the Luhn algorithm.\n";
        ccFile << "# You can use these numbers to test the system.\n";
        ccFile << "// References:\n";
        ccFile << "[1] https://www.freeformatter.com/credit-card-number-generator-validator.html\n";
        ccFile << "[2] https://support.bluesnap.com/docs/test-credit-card-numbers\n";
        ccFile << "--------------------------\n";
        ccFile << "6011000990139424\n374245455400126\n378282246310005\n5011054488597827\n6271701225979642\n6034932528973614\n6250941006528599\n60115564485789458\n6011000991300009\n6362970000457013\n6062826786276634\n3566000020000410\n3530111333300000\n5425233430109903\n2222420000001113\n2223000048410010\n5895626746595650\n5200533989557118\n6034883265619896\n4263982640269299\n4917484589897107\n4001919257537193\n4007702835532454\n4701322211111234\n4347699988887777\n ";
    }

    // Close the files
    userFile.close();
    adminFile.close();
    skillFile.close();
    listingFile.close();
    requestFile.close();
    reviewFile.close();
    blockFile.close();
}