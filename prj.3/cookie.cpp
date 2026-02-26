#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  // named constants for recipe
  const int yield = 48;
  const double sugar = 1.5;
  const double butter = 1.0;
  const double flour = 2.75;

  double desiredCookies;
  // terminal outputs
  cout << "   Cookie Ingredient Calculator   " << endl;
  cout << "How many cookies do you want to make? ";

  if (!(cin >> desiredCookies)) {
    cout << "Invalid input. Please enter a numerical value." << endl;
    return 1;
  }
  // input calculations
  double sugarNeeded = (sugar / yield) * desiredCookies;
  double butterNeeded = (butter / yield) * desiredCookies;
  double flourNeeded = (flour / yield) * desiredCookies;

  // outputs into terminal
  cout << fixed << setprecision(2);
  cout << "\nTo make " << desiredCookies << " cookies, you will need:" << endl;
  cout << " Sugar:   " << sugarNeeded << " cups" << endl;
  cout << " Butter:  " << butterNeeded << " cups" << endl;
  cout << " Flour:   " << flourNeeded << " cups" << endl;

  return 0;
}