#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // for std::time and std::localtime
#include <sstream> // for std::ostringstream
#include <iomanip>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Review
{
private:
    int skillRatingScore = 0;     // 1-5, filled by hosts only
    int supporterRatingScore = 0; // 1-5, filled by hosts only
    int hostRatingScore = 0;      // 1-5, filled by supporters only

    std::string comments;
    std::string reviewerUsername;
    std::string timestamp; // DD/MM/YYYY HH:MM:SS format

public:
    string parseDate()
    {
        // Get current system time
        std::time_t now = std::time(0);
        std::tm *localTime = std::localtime(&now);

        // Format the timestamp (assuming YYYY-MM-DD HH:MM:SS format)
        std::ostringstream timestampStream;
        timestampStream << (localTime->tm_year + 1900) << '-'
                        << (localTime->tm_mon + 1) << '-'
                        << localTime->tm_mday << ' '
                        << localTime->tm_hour << ':'
                        << localTime->tm_min << ':'
                        << localTime->tm_sec;
        return timestampStream.str();
    }
    // Constructor for review by host
    Review(int skillRatingScore, int supporterRatingScore, std::string comments, std::string reviewerUsername)
    {
        this->skillRatingScore = skillRatingScore;
        this->supporterRatingScore = supporterRatingScore;
        this->comments = comments;
        this->reviewerUsername = reviewerUsername;
        this->timestamp = parseDate();
    }

    // Constructor for review by supporter
    Review(int hostRatingScore, std::string comments, std::string reviewerUsername)
    {
        this->hostRatingScore = hostRatingScore;
        this->comments = comments;
        this->reviewerUsername = reviewerUsername;
        this->timestamp = parseDate();
    }

    void printReview()
    {
        cout << this->reviewerUsername << " ~ posted on " << this->timestamp << "\n";
        if (this->skillRatingScore != 0)
        {
            cout << "Skill Rating: " << this->skillRatingScore << "\n";
            cout << "Supporter Rating: " << this->supporterRatingScore << "\n";
        }
        else
        {
            cout << "Host Rating: " << this->hostRatingScore << "\n";
        }
        cout << "Description: " << this->comments << "\n";
        cout << std::endl;
    }

    int getSkillRatingScore()
    {
        return this->skillRatingScore;
    }

    int getSupporterRatingScore()
    {
        return this->supporterRatingScore;
    }

    int getHostRatingScore()
    {
        return this->hostRatingScore;
    }
};

class Request
{
private:
};

struct Address
{
private:
    string street;
    string city;
    double latitude;
    double longitude;

public:
    // Constructor
    Address(string street = "", string city = "", double latitude = 0, double longitude = 0)
    {
        this->street = street;
        this->city = city;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    // Getters and Setters
    string getStreet()
    {
        return this->street;
    }

    string getCity()
    {
        return this->city;
    }

    double getLatitude()
    {
        return this->latitude;
    }

    double getLongitude()
    {
        return this->longitude;
    }

    void setStreet(string street)
    {
        this->street = street;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setLatitude(double latitude)
    {
        this->latitude = latitude;
    }
    void setLongitude(double longitude)
    {
        this->longitude = longitude;
    }
};

class User
{
private:
    string username;
    string password;
    string role; // Admin, Guest, RegularMember
    bool isAuthenticated;

public:
    // Constructor
    User(string username = "", string password = "", string role = "", bool isAuthenticated = false)
    {
        this->username = username;
        this->password = password;
        this->role = role;
        this->isAuthenticated = isAuthenticated;
    };

    string getUsername()
    {
        return this->username;
    }
};

class Admin : public User
{
private:
    float revenue; // revenue of the company

public:
    // Constructor
    Admin(string username = "", string password = "", bool isAuthenticated = false, float revenue = 0) : User(username, password, "Admin", isAuthenticated)
    {
        this->revenue = revenue;
    };
};

class Guest : public User
{
public:
    // Constructor
    Guest(string username = "", string password = "", bool isAuthenticated = false) : User(username, password, "Guest", isAuthenticated){};
};

class RegularMember : public User
{
private:
    int creditPoints;
    string phoneNumber;
    string email;
    Address homeAddress;
    string creditCardNumber;
    int cvcNumber;
    float balance;
    vector<string> skills;
    float skillRatingScore;
    float supporterRatingScore;
    float hostRatingScore;
    vector<Review> receivedReviews;
    vector<Request> receivedRequests;

public:
    // Constructor
    RegularMember(string username, string password, bool isAuthenticated, string phoneNumber, string email, Address homeAddress, string creditCardNumber, int cvcNumber, float balance, vector<string> skills) : User(username, password, "RegularMember", isAuthenticated)
    {
        this->creditPoints = 20;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->homeAddress = homeAddress;
        this->creditCardNumber = creditCardNumber;
        this->cvcNumber = cvcNumber;
        this->balance = balance;
        this->skills = skills;
        this->skillRatingScore = 0;
        this->supporterRatingScore = 0;
        this->hostRatingScore = 0;
    };

    void addReview(Review review, RegularMember &receiver)
    {
        receiver.receivedReviews.push_back(review);
    }

    void printReceivedReviews()
    {
        for (int i = 0; i < this->receivedReviews.size(); i++)
        {
            this->receivedReviews[i].printReview();
        }
    }

    float getSkillRatingScore()
    {
        // Calculate the average skill rating score
        for (int i = 0; i < this->receivedReviews.size(); i++)
        {
            this->skillRatingScore += this->receivedReviews[i].getSkillRatingScore();
        }
        return (float)this->skillRatingScore / this->receivedReviews.size();
    }

    float getSupporterRatingScore()
    {
        // Calculate the average supporter rating score
        for (int i = 0; i < this->receivedReviews.size(); i++)
        {
            this->supporterRatingScore += this->receivedReviews[i].getSupporterRatingScore();
        }
        return (float)this->supporterRatingScore / this->receivedReviews.size();
    }

    float getHostRatingScore()
    {
        this->hostRatingScore = 0;
        // Calculate the average host rating score
        for (int i = 0; i < this->receivedReviews.size(); i++)
        {
            this->hostRatingScore += this->receivedReviews[i].getHostRatingScore();
        }
        return (float)this->hostRatingScore / this->receivedReviews.size();
    }

    // Pay to the system for the registration fee
    bool payRegistrationFee()
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
    long double calculateDistance(RegularMember &otherMember)
    {
        long double lat1, lon1, lat2, lon2;
        lat1 = this->homeAddress.getLatitude();
        lon1 = this->homeAddress.getLongitude();
        lat2 = otherMember.homeAddress.getLatitude();
        lon2 = otherMember.homeAddress.getLongitude();

        const int R = 6371; // Radius of the Earth in kilometers
        long double latDistance = (lat2 - lat1) * M_PI / 180.0;
        long double lonDistance = (lon2 - lon1) * M_PI / 180.0;
        long double a = sin(latDistance / 2) * sin(latDistance / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(lonDistance / 2) * sin(lonDistance / 2);
        long double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        return R * c * 1000;
    }

    friend class CRUDOperations;

    void printMemberInfo()
    {
        cout << "Username: " << this->getUsername() << "\n";
        cout << "Credit points: " << this->creditPoints << "\n"; // 20 credit points for each new member
        cout << "Phone number: " << this->phoneNumber << "\n";
        cout << "Email: " << this->email << "\n";
        cout << "Home address: " << this->homeAddress.getStreet() << ", " << this->homeAddress.getCity() << "\n";
        cout << "Credit card number: " << this->creditCardNumber << "\n";
        cout << "CVC number: " << this->cvcNumber << "\n";
        cout << "Balance: " << this->balance << "\n";
        cout << "Skills: ";
        for (int i = 0; i < this->skills.size(); i++)
        {
            cout << this->skills[i] << ", ";
        }
        cout << "\n";
        cout << "Skill rating score: " << getSkillRatingScore() << "\n";
        cout << "Supporter rating score: " << getSupporterRatingScore() << "\n";
        cout << "Host rating score: " << getHostRatingScore() << "\n";
        cout << "Received reviews: \n";
        for (int i = 0; i < this->receivedReviews.size(); i++)
        {
            this->receivedReviews[i].printReview();
        }
    }

    bool topUp(int credPoints)
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
};

class CRUDOperations
{
public:
    int getDigit(const int number)
    {
        if (number <= 9)
        {
            return number;
        }
        else
        {
            int firstDigit = number / 10;
            int secondDigit = number % 10;
            return firstDigit + secondDigit;
        }
    }

    int sumOfOddPlace(const string cardNumber)
    {
        int sum = 0;
        // Iterate through the card number from right to left, in the odd places
        for (int i = cardNumber.size() - 1; i >= 0; i -= 2)
        {
            int digit = cardNumber[i] - '0'; // substraction of char '0' gives the int value of the char (ASCII table 48 = '0' -> 57 = '9')
            sum += digit;
        }
        return sum;
    }

    int sumEvenDigits(const string cardNumber)
    {
        int sum = 0;
        // Iterate through the card number from right to left, in the even places
        for (int i = cardNumber.size() - 2; i >= 0; i -= 2)
        {
            int digit = cardNumber[i] - '0'; // substraction of char '0' gives the int value of the char (ASCII table 48 = '0' -> 57 = '9')
            sum += getDigit(digit * 2);
        }

        return sum;
    }
    // Function to trim whitespace from a string and replace spaces between words with an empty string
    std::string trimAndRemoveSpaces(std::string &str)
    {
        std::string result;

        for (char c : str)
        {
            if ((std::isspace(c)) || (c == '-'))
            {
                result += "";
            }
            else
            {
                result += c;
            }
        }

        return result;
    }

    bool isValidCard(string cardNumber)
    {
        string cleanInput = trimAndRemoveSpaces(cardNumber);
        int result = 0;
        result = sumOfOddPlace(cleanInput) + sumEvenDigits(cleanInput);
        if (result % 10 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Function to load balance amount information from the imaginary bank database
    float loadAccountInfo(std::string cardNumber)
    {
        std::ifstream database("./paymentacc.txt");
        if (database.is_open())
        {
            std::string line;
            while (std::getline(database, line))
            {
                std::istringstream iss(line);
                std::string storedCardNumber;
                float storedBalance;

                // Assuming the file format is "cardNumber,balance"
                std::getline(iss, storedCardNumber, ',');
                iss >> storedBalance;

                if (storedCardNumber == cardNumber)
                {
                    database.close();
                    return storedBalance;
                }
            }
            database.close();
        }
        else
        {
            std::cerr << "Unable to open the database file." << std::endl;
        }

        // Return a default value or handle the case where the card number is not found
        return -1.0; // Modify this accordingly based on your needs
    }

    // CRUD operations for RegularMember
    RegularMember addMember()
    {
        std::fstream userFile("TESTING_USER.txt", std::ios::out | std::ios::app);

        string name, password, phoneNumber, email, street, city, creditCardNumber;
        int cvcNum;
        float balance;
        double latitude, longitude;
        vector<string> mySkills;
        cout << "Enter username: ";
        getline(cin >> std::ws, name);
        cout << "Enter password: ";

        cin >> password;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
        cout << "Enter email: ";
        cin >> email;
        cout << "Before entering your address, go to the link below and find out your geographic location :)\n";
        cout << "https://support.google.com/maps/answer/18539?hl=en&co=GENIE.Platform\%3DDesktop\n";
        cout << "Enter the street name, district, etc: ";
        std::getline(cin >> std::ws, street);
        cout << "Enter your city (Hanoi/Saigon): ";

        cin >> city;
        cout << "Enter the latitude: ";
        cin >> latitude;
        cout << "Enter the longtitude: ";
        cin >> longitude;
        do
        {
            cout << "Enter your credit card number: ";
            cin >> creditCardNumber;
            if (!isValidCard(creditCardNumber))
            {
                cout << "Invalid credit card number!\n";
            }
            balance = loadAccountInfo(trimAndRemoveSpaces(creditCardNumber));
            if (balance < 20)
            {
                cout << "Please choose another card u broke :(\n";
            }
        } while (!isValidCard(creditCardNumber) || balance < 20);
        cout << "Enter your CVC number: ";
        cin >> cvcNum;

        cout << "How many skills do you have? ";
        int numSkills;
        cin >> numSkills;
        for (int i = 0; i < numSkills; i++)
        {
            string skill;
            cout << "Enter skill " << i + 1 << ": ";
            getline(cin >> std::ws, skill);
            mySkills.push_back(skill);
        }
        userFile << name << ": " << password << ": " << phoneNumber << ": " << email << ": " << street << ": " << city << ": " << latitude << ": " << longitude << ": " << creditCardNumber << ": " << cvcNum << ": " << balance << ": " << "0: 0: 0: ";
        for (int i = 0; i < mySkills.size(); i++)
        {
            userFile << mySkills[i] << ", ";
        }
        userFile << "\n";
        userFile.close();

        Address address(street, city, latitude, longitude);
        RegularMember newMember(name, password, false, phoneNumber, email, address, creditCardNumber, cvcNum, balance, mySkills);
        return newMember;
    }
};

int main()
{
    // RegularMember mem1("user1", "password", true, "0912951022", "example@gmail.com", Address("RMIT", "HCM", 10.784370047262946, 106.69587460622827), "1234 5678 9012 3456", 123, 0, vector<string>());
    RegularMember mem2("user2", "password", true, "0919140739", "example2@gmail.com", Address("Masteri Thao Dien", "HCM", 10.803142644579694, 106.74027861351652), "1234 5678 9012 3456", 123, 0, {"Piano", "Maths"});
    // Review review1(5, 5, "Great supporter!", "user1");
    // Review review3(3, 2, "Lied about the piano skills", "user1");
    // Review review4(4, 4, "Badass at meths", "user1");
    // Review review2(4, "Kind host, but stingy with the food", "user2");
    // // review1.printReview();
    // // review2.printReview();
    // mem1.addReview(review1, mem2);
    // mem1.addReview(review3, mem2);
    // mem1.addReview(review4, mem2);
    // mem2.addReview(review2, mem1);
    // cout << "Average skill ratings: " << mem2.getSkillRatingScore() << std::endl;
    // cout << "Average supporter ratings: " << std::fixed << std::setprecision(2) << mem2.getSupporterRatingScore() << std::endl;
    // mem2.printReceivedReviews();

    // mem1.printReceivedReviews();
    // cout << "Average host ratings: " << mem1.getHostRatingScore() << std::endl;

    // cout << "Member 1 and Member 2 distance is: " << mem1.calculateDistance(mem2) << " meters\n";

    // mem1.printMemberInfo();

    CRUDOperations crud;
    RegularMember mem1 = crud.addMember();
    mem2.addReview(Review(5, 5, "Great supporter!", "user1"), mem1);
    mem1.printReceivedReviews();
    cout << "Average skill ratings: " << mem1.getSkillRatingScore() << std::endl;
    cout << "Average supporter ratings: " << std::fixed << std::setprecision(2) << mem1.getSupporterRatingScore() << std::endl;
    cout << "Host ratings: " << mem1.getHostRatingScore() << std::endl;
    

    return 0;
}