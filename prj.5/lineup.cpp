#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Variable declarations
  ifstream inputFile;
  string currentName;
  string frontName;
  string endName;
  int studentCount = 0;

  // Attempt to open the file
  inputFile.open("LineUp.txt");

  // Input Validation: Verify file opened successfully
  if (!inputFile) {
    cout << "Error: Could not open the file 'LineUp.txt'." << endl;
    return 1;  // Exit with error code
  }

  // Process the first name to initialize front and end
  if (inputFile >> currentName) {
    studentCount++;
    frontName = currentName;
    endName = currentName;

    // Read remaining data until end-of-file
    while (inputFile >> currentName) {
      studentCount++;

      // String comparisons for alphabetical order
      if (currentName < frontName) {
        frontName = currentName;
      }
      if (currentName > endName) {
        endName = currentName;
      }
    }

    // Close the file after reading
    inputFile.close();

    // Output final results
    cout << "Class size: " << studentCount << " students" << endl;
    cout << "Student at the front: " << frontName << endl;
    cout << "Student at the end: " << endName << endl;
  } else {
    // Handle case where file is empty
    cout << "The file is empty." << endl;
    inputFile.close();
  }

  return 0;
}