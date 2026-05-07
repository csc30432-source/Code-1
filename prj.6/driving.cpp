#include <iostream>
#include <limits>
#include <string>

using namespace std;

/**
 * Purpose: Prompts the user for a region name and the number of accidents
 * reported in that region. Preconditions: None. Postconditions: accidents >= 0.
 * Validated values are returned via reference parameters.
 */
void getRegInfo(string& regionName, int& accidents);

/**
 * Purpose: Determines whether one accident count is less than or equal to
 * another. Preconditions: Both values represent validated accident counts.
 * Postconditions: Returns true if value1 <= value2; returns false otherwise.
 */
bool isLower(int value1, int value2);

/**
 * Purpose: Displays the name of the safest region and its number of accidents.
 * Preconditions: regionName corresponds to the region with the lowest accident
 * count. Postconditions: Results are written to the console.
 */
void showLowest(string regionName, int accidents);

/**
 * main()
 * Purpose: Controls the overall flow of the program. Coordinates data
 * collection, comparison, and output.
 */
int main() {
  // Assign the number of regions to a constant
  const int NUM_REGIONS = 5;

  string currentRegion;
  int currentAccidents;

  string safestRegion;
  int lowestAccidents =
      numeric_limits<int>::max();  // Initialize with highest possible value

  cout << "Safest Driving Area Analysis\n";
  cout << "----------------------------\n";

  for (int i = 0; i < NUM_REGIONS; i++) {
    // Get the name of a region and its accident count
    getRegInfo(currentRegion, currentAccidents);

    // Track the region with the lowest number of accidents
    if (isLower(currentAccidents, lowestAccidents)) {
      lowestAccidents = currentAccidents;
      safestRegion = currentRegion;
    }
    cout << endl;
  }

  // Display the safest region and its accident count
  showLowest(safestRegion, lowestAccidents);

  return 0;
}

void getRegInfo(string& regionName, int& accidents) {
  cout << "Enter the name of the region: ";
  cin >> regionName;

  // Apply input validation: accidents must be greater than or equal to 0
  do {
    cout << "Enter the number of accidents reported in " << regionName << ": ";
    cin >> accidents;

    if (accidents < 0) {
      cout << "Invalid input. Accident count cannot be negative. Please try "
              "again.\n";
    }
  } while (accidents < 0);
}

bool isLower(int value1, int value2) { return value1 <= value2; }

void showLowest(string regionName, int accidents) {
  cout << "Analysis Complete\n";
  cout << "----------------------------\n";
  cout << "The safest region is: " << regionName << endl;
  cout << "Number of accidents: " << accidents << endl;
}