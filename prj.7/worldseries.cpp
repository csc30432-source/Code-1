#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function Prototypes as specified in requirements
void getTeams(string filename, vector<string>& teamVector);
int findWinner(string teamName, const vector<string>& winnersVector);

int main() {
  vector<string> teams;
  vector<string> winners;
  string userInput;

  // Load data from files into vectors
  getTeams("Teams.txt", teams);
  getTeams("WorldSeriesWinners.txt", winners);

  // Display the list of unique team names
  cout << "Team Names:" << endl;
  for (const string& team : teams) {
    cout << team << endl;
  }
  cout << endl;

  // Sentinel-controlled loop for user queries
  cout << "Enter the name of a team (enter quit to end): " << endl;
  getline(cin, userInput);

  while (userInput != "quit") {
    // Calculate the number of wins
    int winCount = findWinner(userInput, winners);

    // Display results
    cout << "\n"
         << userInput << " won the World Series " << winCount << " times."
         << endl;

    // Prompt for next input or termination
    cout << "Enter the name of a team (enter quit to end): " << endl;
    getline(cin, userInput);
  }

  return 0;
}

/**
 * Opens a file, validates access, and reads lines into a vector
 */
void getTeams(string filename, vector<string>& teamVector) {
  ifstream inputFile;
  inputFile.open(filename);

  // File validation: Terminate if file cannot be opened
  if (!inputFile) {
    cout << "Error opening file: " << filename << endl;
    exit(EXIT_FAILURE);
  }

  string line;
  // Read data from the file and add to the end of the vector
  while (getline(inputFile, line)) {
    if (!line.empty()) {
      teamVector.push_back(line);
    }
  }

  inputFile.close();
}

/**
 * Searches the winners vector and returns the count of occurrences
 */
int findWinner(string teamName, const vector<string>& winnersVector) {
  int count = 0;

  // Requirement: Use a range-based for loop to iterate
  for (const string& winner : winnersVector) {
    if (winner == teamName) {
      count++;
    }
  }

  return count;
}