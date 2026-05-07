#include <cmath>  // Required for ceil()
#include <iomanip>
#include <iostream>

using namespace std;

// --- Global Constants ---
//
const double SQ_FT_PER_UNIT = 110.0;
const double LABOR_HOURS_PER_UNIT = 8.0;
const double LABOR_CHARGE_PER_HOUR = 25.0;

// --- Function Prototypes ---
int getNumRooms();
double getPricePerGallon();
double getSqFt(int roomNum);
int calculateGallons(double totalSqFt);
double calculateLaborHours(double totalSqFt);
void displayEstimate(int totalGallons, double totalLaborHours,
                     double paintPrice, double totalSqFt);

int main() {
  int numRooms;
  double pricePerGallon;
  double totalSqFt = 0.0;

  // Get initial validated inputs
  numRooms = getNumRooms();
  pricePerGallon = getPricePerGallon();

  // Accumulate square footage for all rooms
  for (int i = 1; i <= numRooms; i++) {
    totalSqFt += getSqFt(i);
  }

  // Perform calculations and display results
  int gallonsNeeded = calculateGallons(totalSqFt);
  double laborHoursNeeded = calculateLaborHours(totalSqFt);

  displayEstimate(gallonsNeeded, laborHoursNeeded, pricePerGallon, totalSqFt);

  return 0;
}

// --- Function Definitions ---

/**
 * Purpose: Prompts for and validates the number of rooms.
 * Parameters: None
 * Preconditions: None
 * Postconditions: Returns an integer >= 1.
 */
int getNumRooms() {
  int rooms;
  cout << "Enter the number of rooms to be painted: ";
  cin >> rooms;
  while (rooms < 1) {
    cout << "Error: Number of rooms must be at least 1. Re-enter: ";
    cin >> rooms;
  }
  return rooms;
}

/**
 * Purpose: Prompts for and validates the price of paint per gallon.
 * Parameters: None
 * Preconditions: None
 * Postconditions: Returns a double >= 10.00.
 */
double getPricePerGallon() {
  double price;
  cout << "Enter the price of paint per gallon: ";
  cin >> price;
  while (price < 10.00) {
    cout << "Error: Price must be $10.00 or greater. Re-enter: ";
    cin >> price;
  }
  return price;
}

/**
 * Purpose: Prompts for and validates square footage for a specific room.
 * Parameters: roomNum (int) - the current room number for display.
 * Preconditions: roomNum > 0.
 * Postconditions: Returns a double >= 0.
 */
double getSqFt(int roomNum) {
  double sqFt;
  cout << "Enter the square feet of wall space for room " << roomNum << ": ";
  cin >> sqFt;
  while (sqFt < 0) {
    cout << "Error: Square footage cannot be negative. Re-enter: ";
    cin >> sqFt;
  }
  return sqFt;
}

/**
 * Purpose: Calculates total gallons needed, rounding up to the next integer.
 * Parameters: totalSqFt (double)
 * Preconditions: totalSqFt >= 0.
 * Postconditions: Returns total gallons rounded up.
 */
int calculateGallons(double totalSqFt) {
  // 1 gallon per 110 sq ft
  return static_cast<int>(ceil(totalSqFt / SQ_FT_PER_UNIT));
}

/**
 * Purpose: Calculates total labor hours required.
 * Parameters: totalSqFt (double)
 * Preconditions: totalSqFt >= 0.
 * Postconditions: Returns total labor hours.
 */
double calculateLaborHours(double totalSqFt) {
  // 8 hours per 110 sq ft
  return (totalSqFt / SQ_FT_PER_UNIT) * LABOR_HOURS_PER_UNIT;
}

/**
 * Purpose: Calculates final costs and displays the formatted estimate.
 * Parameters: totalGallons (int), totalLaborHours (double),
 * paintPrice (double), totalSqFt (double)
 * Preconditions: All parameters are non-negative.
 * Postconditions: Displays cost breakdown to console.
 */
void displayEstimate(int totalGallons, double totalLaborHours,
                     double paintPrice, double totalSqFt) {
  double paintCost = totalGallons * paintPrice;
  double laborCost = totalLaborHours * LABOR_CHARGE_PER_HOUR;
  double totalCost = paintCost + laborCost;

  cout << fixed << showpoint << setprecision(2);
  cout << "\n--- Paint Job Estimate ---" << endl;
  cout << "Total Gallons of Paint: " << totalGallons << endl;
  cout << "Total Labor Hours:      " << totalLaborHours << endl;
  cout << "Cost of Paint:         $" << setw(8) << paintCost << endl;
  cout << "Labor Charges:         $" << setw(8) << laborCost << endl;
  cout << "--------------------------" << endl;
  cout << "Total Cost:            $" << setw(8) << totalCost << endl;
}