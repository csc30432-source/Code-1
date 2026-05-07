#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

// Function Prototypes
double getScore();
bool isLower(double value1, double value2);
bool isHigher(double value1, double value2);
double calcAverage(double total, double minScore, double maxScore);

/**
 * Purpose: Controls program flow. Collects scores, tracks min/max,
 * calculates the final average, and displays the result.
 */
int main() {
  const int NUM_JUDGES = 5;
  double totalScore = 0.0;
  double minScore = 11.0;  // Higher than any possible score
  double maxScore = -1.0;  // Lower than any possible score
  char choice;

  do {
    totalScore = 0.0;
    minScore = 11.0;
    maxScore = -1.0;

    cout << "--- Star Search Talent Competition ---" << endl;

    for (int i = 1; i <= NUM_JUDGES; i++) {
      cout << "Judge #" << i << " ";
      double currentScore = getScore();

      totalScore += currentScore;

      // Track minimum score
      if (isLower(currentScore, minScore)) {
        minScore = currentScore;
      }

      // Track maximum score
      if (isHigher(currentScore, maxScore)) {
        maxScore = currentScore;
      }
    }

    double finalAverage = calcAverage(totalScore, minScore, maxScore);

    cout << fixed << setprecision(2);
    cout << "\nResults:" << endl;
    cout << "Highest Score Dropped: " << maxScore << endl;
    cout << "Lowest Score Dropped:  " << minScore << endl;
    cout << "Final Average Score:   " << finalAverage << endl;

    cout << "\nProcess another performer? (y/n): ";
    cin >> choice;
    cout << endl;

  } while (choice == 'y' || choice == 'Y');

  return 0;
}

/**
 * Purpose: Prompts the user for a judge’s score and validates the input.
 * Preconditions: None.
 * Postconditions: Returns a value between 0.0 and 10.0 (inclusive).
 */
double getScore() {
  double score;
  bool invalid = true;
  while (invalid) {
    cout << "Enter a score (0.0 - 10.0): ";
    cin >> score;

    if (score >= 0.0 && score <= 10.0) {
      invalid = false;
    } else {
      cout << "Invalid score. Please enter a value between 0 and 10." << endl;
    }
  }
  return score;
}

/**
 * Purpose: Determines whether one score is less than or equal to another.
 * Preconditions: Both values represent validated scores.
 * Postconditions: Returns true if value1 <= value2; returns false otherwise.
 */
bool isLower(double value1, double value2) { return value1 <= value2; }

/**
 * Purpose: Determines whether one score is greater than or equal to another.
 * Preconditions: Both values represent validated scores.
 * Postconditions: Returns true if value1 >= value2; returns false otherwise.
 */
bool isHigher(double value1, double value2) { return value1 >= value2; }

/**
 * Purpose: Calculates the average score after removing the highest and lowest
 * scores. Preconditions: total includes all five scores; minScore and maxScore
 * are valid. Postconditions: Returns the average of the three remaining scores.
 */
double calcAverage(double total, double minScore, double maxScore) {
  double adjustedTotal = total - minScore - maxScore;
  return adjustedTotal / 3.0;
}