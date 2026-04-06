#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int startPop;
  double dailyIncrease;
  int days;

  // 1. Input Validation: Starting Population
  cout << "Enter the starting number of organisms (minimum 2): ";
  while (!(cin >> startPop) || startPop < 2) {
    cout << "Error: Starting population must be an integer 2 or greater. Try "
            "again: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  // 2. Input Validation: Daily Increase
  cout << "Enter the average daily population increase (as a percentage, e.g., "
          "5 for 5%): ";
  while (!(cin >> dailyIncrease) || dailyIncrease <= 0) {
    cout
        << "Error: Daily increase must be a number greater than 0. Try again: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  // 3. Input Validation: Number of Days
  cout << "Enter the number of days they will multiply (minimum 1): ";
  while (!(cin >> days) || days < 1) {
    cout
        << "Error: Number of days must be an integer 1 or greater. Try again: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  // Convert percentage to decimal
  double growthRate = dailyIncrease / 100.0;
  double currentPop = startPop;

  // 4. Calculation and Output Loop
  cout << "\nDay\tPopulation Size" << endl;
  cout << "-----------------------" << endl;

  for (int i = 1; i <= days; i++) {
    // Display current population before increasing for the next day
    cout << i << "\t" << fixed << setprecision(2) << currentPop << endl;

    // Calculate population for the next day
    currentPop += (currentPop * growthRate);
  }

  return 0;
}
