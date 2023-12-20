#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "myUtils.h"

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

int main()
{
    std::cout << generateRandomID() << "\n";
    return 0;
}

