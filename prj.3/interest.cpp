#include <cmath>    // For the pow function
#include <iomanip>  // For setprecision and fixed
#include <iostream>

using namespace std;

int main() {
  // Variables
  double principal, annualRate, timesCompounded;
  double amount, interestEarned, decimalRate;

  // Get user input
  cout << "Enter the principal balance: ";
  cin >> principal;
  cout << "Enter the annual interest rate (as a percentage, e.g., 4.25): ";
  cin >> annualRate;
  cout << "Enter the number of times interest is compounded per year: ";
  cin >> timesCompounded;

  // Convert percentage to decimal
  decimalRate = annualRate / 100.0;

  // Compound Interest Formula: Amount = Principal * (1 + Rate/T)^T
  amount =
      principal * pow((1 + (decimalRate / timesCompounded)), timesCompounded);

  // Calculate interest earned
  interestEarned = amount - principal;

  // Display financial report
  cout << fixed << setprecision(2) << endl;
  cout << left << setw(25) << "Interest Rate:" << right << setw(10)
       << annualRate << "%" << endl;
  cout << left << setw(25) << "Times Compounded:" << right << setw(10)
       << (int)timesCompounded << endl;
  cout << left << setw(25) << "Principal:" << "$" << right << setw(9)
       << principal << endl;
  cout << left << setw(25) << "Interest:" << "$" << right << setw(9)
       << interestEarned << endl;
  cout << left << setw(25) << "Amount in Savings:" << "$" << right << setw(9)
       << amount << endl;

  return 0;
}