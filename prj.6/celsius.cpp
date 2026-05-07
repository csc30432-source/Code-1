#include <iomanip>  // Required for formatting the table
#include <iostream>

using namespace std;

// Global Constants for the range
const int MIN_FAHRENHEIT = 0;   // Minimum Fahrenheit value
const int MAX_FAHRENHEIT = 20;  // Maximum Fahrenheit value

/**
 * Purpose: Converts a Fahrenheit temperature to Celsius.
 * Preconditions: fahrenheit represents a valid temperature value.
 * Postconditions: Returns the equivalent temperature in degrees Celsius.
 */
double getCelsius(double fahrenheit) {
  // Formula: C = 5/9 * (F - 32)
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}

/**
 * Purpose: Controls program flow. Displays headings, loops through
 * the temperature range, and outputs the table.
 */
int main() {
  // Display the table title and column headings
  cout << "Fahrenheit to Celsius Conversion Table" << endl;
  cout << "--------------------------------------" << endl;
  cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius" << endl;
  cout << "--------------------------------------" << endl;

  // Formatting: Right-align numeric output and set to one decimal place
  cout << fixed << setprecision(1) << right;

  // Loop through the Fahrenheit range
  for (int f = MIN_FAHRENHEIT; f <= MAX_FAHRENHEIT; ++f) {
    // Perform conversion using the required function
    double celsius = getCelsius(static_cast<double>(f));

    // Display both values in a formatted table
    cout << setw(12) << static_cast<double>(f) << setw(12) << celsius << endl;
  }

  return 0;
}