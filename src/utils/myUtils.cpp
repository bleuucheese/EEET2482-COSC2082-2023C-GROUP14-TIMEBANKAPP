#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include "./myUtils.h"
#include "myUtils.h"
#include "./time/DateTime.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::string generateRandomID()
{
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Get the current year
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = ltm->tm_year + 1900;

    // Generate random four-digit number
    int randomDigits = rand() % 10000;

    // Combine the year and random digits
    std::stringstream resultStream;
    resultStream << std::setw(4) << std::setfill('0') << currentYear
                 << std::setw(4) << std::setfill('0') << randomDigits;

    return resultStream.str();
}

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

int sumOfOddPlace(const std::string cardNumber)
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

int sumEvenDigits(const std::string cardNumber)
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

bool isValidCard(std::string cardNumber)
{
    std::string cleanInput = trimAndRemoveSpaces(cardNumber);
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

std::string getValidUsername()
{
    string username;
    while (true)
    {
        cout << "Enter a username (6-17 characters, letters, numbers, underscores, and hyphens only, no spaces): ";
        getline(cin, username);
        if (std::regex_match(username, std::regex("^[a-zA-Z0-9_-]{6,17}$")))
        {
            return username;
        }
        else
        {
            cout << "Invalid username. Please try again." << endl;
        }
    }
}

std::string getValidPassword()
{
    std::string password;
    while (true)
    {
        cout << "Enter a password (8-17 characters, no spaces): ";
        getline(cin, password);
        if (password.length() >= 8 && password.length() <= 17 && password.find(' ') == string::npos)
        {
            return password;
        }
        else
        {
            cout << "Invalid password. Please try again." << endl;
        }
    }
}

std::string getValidFullName()
{
    std::string fullName;
    while (true)
    {
        cout << "Enter your full name (2-50 characters, letters, spaces, and hyphens only): ";
        getline(cin, fullName);
        if (std::regex_match(fullName, std::regex("^[a-zA-Z -]{2,50}$")))
        {
            return fullName;
        }
        else
        {
            cout << "Invalid full name. Please try again." << endl;
        }
    }
}

std::string getValidEmail()
{
    string email;
    while (true)
    {
        cout << "Enter your email address (must contain @ and no spaces): ";
        getline(cin, email);
        if (std::regex_match(email, std::regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$")))
        {
            return email;
        }
        else
        {
            cout << "Invalid email address. Please try again." << endl;
        }
    }
}

std::string getValidPhoneNumber()
{
    string phoneNumber;
    while (true)
    {
        cout << "Enter your phone number (10 digits, numbers only, no spaces): ";
        getline(cin, phoneNumber);
        if (std::regex_match(phoneNumber, std::regex("^[0-9]{10}$")))
        {
            return phoneNumber;
        }
        else
        {
            cout << "Invalid phone number. Please try again." << endl;
        }
    }
}

std::string getValidAddress()
{
    string address;
    while (true)
    {
        cout << "Enter your address (letters, numbers, spaces, and hyphens only, no commas): ";
        getline(cin, address);
        if (std::regex_match(address, std::regex("^[a-zA-Z0-9 -]+$")))
        {
            return address;
        }
        else
        {
            cout << "Invalid address. Please try again." << endl;
        }
    }
}

std::string getValidCardNumber()
{
    std::string cardNumber;
    while (true)
    {
        std::cout << "Enter a credit card number: ";
        getline(std::cin, cardNumber);
        if (!std::all_of(cardNumber.begin(), cardNumber.end(), ::isdigit))
        {
            std::cout << "Card number can only contain digits. Please try again." << std::endl;
            continue;
        }

        if (cardNumber.length() < 13 || cardNumber.length() > 19)
        {
            std::cout << "Invalid card number length. Please try again." << std::endl;
            continue;
        }

        // Luhn's algorithm
        if (!isValidCard(cardNumber))
        {
            std::cout << "Invalid credit card number. Please try again." << std::endl;
            continue;
        }

        return cardNumber;
    }
}

std::string getValidCity()
{
    std::string city;
    while (true)
    {
        std::cout << "Enter city (Hanoi or Saigon): ";
        std::cin >> city;
        if (city == "Hanoi" || city == "Saigon")
        {
            return city;
        }
        else
        {
            std::cout << "Invalid city. Please enter Hanoi or Saigon." << std::endl;
        }
    }
}

double getValidDouble(const std::string &prompt)
{
    double value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            // Check if there is any extra input (non-numeric characters)
            if (std::cin.peek() == '\n')
            {
                // Valid float input
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter a valid double." << std::endl;
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid double." << std::endl;
            std::cin.clear();                                                   // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }
    return value;
}

double getValidLatitude()
{
    return getValidDouble("Enter latitude (in decimal, e.g: 10.455): ");
}

double getValidLongitude()
{
    return getValidDouble("Enter longitude (in decimal, e.g: 106.344): ");
}

std::string getValidStringInput(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        getline(std::cin, input);
        if (std::regex_match(input, std::regex("^[a-zA-Z0-9 -]+$")))
        {
            return input;
        }
        else
        {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
}

float getValidFloat(const std::string &prompt)
{
    float value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            // Check if there is any extra input (non-numeric characters)
            if (std::cin.peek() == '\n')
            {
                // Valid float input
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter a valid float." << std::endl;
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid float." << std::endl;
            std::cin.clear();                                                   // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }
    return value;
}

int getValidInt(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            // Check if there is any extra input (non-numeric characters)
            if (std::cin.peek() == '\n')
            {
                // Valid int input
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();                                                   // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }
    return value;
}

std::string getValidTimestamp(const std::string &prompt)
{
    std::string input;
    DateTime dateTimeChecker; // Assuming DateTime has a default constructor

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::regex pattern("^\\d{2}/\\d{2}/\\d{4} \\d{2}:\\d{2}:\\d{2}$");
        if (!dateTimeChecker.isValidFormat(input) && !dateTimeChecker.isValidDate())
        {

            std::cout << "Invalid time. Please try again." << std::endl;
        }
        if (std::regex_match(input, pattern))
        {
            break; // Break if passed 2 test cases
        }
        else
        {
            std::cout << "Invalid format. Please try again." << std::endl;
        }
    }

    return input;
}