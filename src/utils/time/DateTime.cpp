#include <iostream>
#include <time.h>
#include <ctime>
#include "DateTime.h"
#include <string>

using std::string;
using std::cin;
using std::cout;

// Constructor
Date::Date() {
  // Get current date
  time_t now = time(0);
  tm *ltm = localtime(&now);
  day = ltm->tm_mday;
  month = ltm->tm_mon + 1;
  year = ltm->tm_year + 1900;
}

Date::Date(int Day, int Month, int Year) {
  day = Day;
  month = Month;
  year = Year;
}

bool Date::isLeapYear(int year) {
  // A year is a leap year if it is divisible by 4 but not by 100, except that years divisible by 400 are leap years.
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::daysInMonth(int month, int year) {
  if (month == 2) {
    return isLeapYear(year) ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}

Date Date::addDays(Date date, int days) {
  int totalDays = date.day + days;
  int remainingDays = totalDays;
  int newMonth = date.month;
  int newYear = date.year;

  while (remainingDays > daysInMonth(newMonth, newYear)) {
    remainingDays -= daysInMonth(newMonth, newYear);
    newMonth++;
    if (newMonth > 12) {
      newMonth = 1;
      newYear++;
    }
  }

  return Date{remainingDays, newMonth, newYear};
}

Date Date::addTimePeriod(Date startDate, int days, int hours, int minutes, int seconds) {
  int totalSeconds = days * 24 * 60 * 60 + hours * 60 * 60 + minutes * 60 + seconds;
  int totalDays = totalSeconds / (24 * 60 * 60);
  return addDays(startDate, totalDays);
}

Date Date::parseDate(std::string str) {
  Date date;
  sscanf(str.c_str(), "%d-%d-%d", &date.day, &date.month, &date.year);
  return date;
}

string Date::formatDate(Date date) {
  char buffer[20];
  sprintf(buffer, "%d-%d-%d", date.day, date.month, date.year);
  return string(buffer);
}

string Date::calculateEndDate(int days, int hours, int minutes, int seconds) {
  
  Date endDate = addTimePeriod(*this, days, hours, minutes, seconds);
  return formatDate(endDate);
}

int main() {
  string startDateStr;
  string timePeriodStr;

  cout << "Enter start date (dd-mm-yyyy): ";
  cin >> startDateStr;

  cout << "Enter time period (dd-hh-mm-ss): ";
  cin >> timePeriodStr;

  Date startDate = startDate.parseDate(startDateStr);
  int days, hours, minutes, seconds;
  sscanf(timePeriodStr.c_str(), "%d-%d-%d-%d", &days, &hours, &minutes, &seconds);

  Date endDate = endDate.addTimePeriod(startDate, days, hours, minutes, seconds);

  cout << "End date: " << endDate.formatDate(endDate) << std::endl;
  Date startDate1 = Date(28, 2, 2025);
  cout << startDate1.calculateEndDate(days, hours, minutes, seconds) << std::endl;

  Date dateToday;
  cout << dateToday.formatDate(dateToday) << std::endl;
  return 0;
}
