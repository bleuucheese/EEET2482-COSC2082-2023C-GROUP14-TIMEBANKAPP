// Period.cpp
#include <iostream>
#include <string>
#include <stdexcept>

#include "Period.h"
#include "DateTime.h"

// Default constructor
Period::Period() : startDate(DateTime())
{
    startDate.addTimePeriod(2, 0, 0, 0); // Add 2 days to current system time
    endDate = startDate;
    endDate.addTimePeriod(7, 0, 0, 0); // Then add 7 days to startDate for endDate
}

// Constructor with parameters
Period::Period(const DateTime &start, const DateTime &end) : startDate(start), endDate(end)
{
    if (startDate.toTimeT() > endDate.toTimeT())
    {
        throw std::invalid_argument("Start date must be before end date");
    }
}
// Method to check if this period overlaps with another
bool Period::isOverlappedWith(const Period &other) const
{
    return startDate.toTimeT() <= other.endDate.toTimeT() &&
           other.startDate.toTimeT() <= endDate.toTimeT();
}

// Method to calculate the duration of the period in seconds
int Period::durationInSeconds() const
{
    return static_cast<int>(endDate.toTimeT() - startDate.toTimeT());
}

// Method to compare two periods
bool Period::isSameAs(const Period &other) const
{
    return startDate.toTimeT() == other.startDate.toTimeT() &&
           endDate.toTimeT() == other.endDate.toTimeT();
}

std::string Period::convertSecToDuration(long n)
{
    int day = n / (24 * 3600); // an hour has 3600 seconds

    n = n % (24 * 3600); // get the modulus subtracted from a whole day
    int hour = n / 3600;

    n %= 3600; // get the modulus subtracted from a whole hour
    int minutes = n / 60;

    n %= 60; // get the modulus subtracted from a whole minute
    int seconds = n;

    return "Duration: " + std::to_string(day) + " day(s), " + std::to_string(hour) + " " + "hour(s), " + std::to_string(minutes) + " " + "min(s), and " + std::to_string(seconds) + " " + "sec(s).";
}

std::string Period::getFormattedPeriod() const
{
    return startDate.getFormattedTimestamp() + " - " + endDate.getFormattedTimestamp();
}