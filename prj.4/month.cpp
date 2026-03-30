#include <iostream>
using namespace std;

int main() {
  int month, year, days;
  bool isLeapYear = false;

  // Get user input
  cout << "Enter a month (1-12): ";
  cin >> month;
  cout << "enter a year: ";
  cin >> year;

  // Input validation
  if (month < 1 || month > 12) {
    cout << "Error: invalid month. Please enter a number between 1 and 12."
         << endl;
    return 1;
  }

  // Determine if leap year
  if (year % 100 == 0) {
    if (year % 400 == 0) {
      isLeapYear = true;
    } else {
      isLeapYear = false;
    }
  }
  // otherwise it is a leap year if divisible by 4
  else if (year % 4 == 0) {
    isLeapYear = true;
  }
  // Determine the days in the month
  if (month == 2) {
    if (isLeapYear) {
      days = 29;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    days = 30;
  } else {
    days = 31;
  }

  // output the result
  cout << days << " days" << endl;

  return 0;
}