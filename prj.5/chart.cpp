#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Variable declarations
  string fileName;
  string townName;
  ifstream inputFile;
  int population;
  int year = 1900;               // Starting year as per instructions
  const int YEAR_INTERVAL = 20;  // 20-year interval

  // Step 1: Request user input
  cout << "Enter the name of the data file (e.g., People.txt): ";
  getline(cin, fileName);

  cout << "Enter the name of the town: ";
  getline(cin, townName);

  // Step 2: Open and validate the file
  inputFile.open(fileName);

  if (!inputFile) {
    cout << "Error: Could not open file '" << fileName
         << "'. Please check the filename and try again." << endl;
    return 1;  // Exit with error code
  }

  // Step 3: Display Chart Header
  cout << "\n" << townName << " Population Growth" << endl;
  cout << "(each * represents 1,000 people)" << endl;

  // Step 4: Read data and generate bar chart
  while (inputFile >> population) {
    // Display the year
    cout << year << " ";

    // Calculate number of asterisks (1 per 1,000 people)
    int numAsterisks = population / 1000;

    // Nested loop to print the bar
    for (int i = 0; i < numAsterisks; i++) {
      cout << "*";
    }

    // Move to the next line for the next data point
    cout << endl;

    // Increment year by the interval
    year += YEAR_INTERVAL;
  }

  // Step 5: Close the file
  inputFile.close();

  return 0;
}