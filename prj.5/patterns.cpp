#include <iostream>

using namespace std;

int main() {
  // Pattern A: Increasing sequence from 1 to 10
  // Outer loop controls the number of rows (1 through 10)
  for (int i = 1; i <= 10; ++i) {
    // Inner loop prints the '+' character 'i' times
    for (int j = 1; j <= i; ++j) {
      cout << "+";
    }
    // Move to the next line after completing a row
    cout << endl;
  }

  // Adding a newline for visual separation between Pattern A and B
  cout << endl;

  // Pattern B: Decreasing sequence from 10 down to 1
  // Outer loop controls the number of rows (10 through 1)
  for (int i = 10; i >= 1; --i) {
    // Inner loop prints the '+' character 'i' times
    for (int j = 1; j <= i; ++j) {
      cout << "+";
    }
    // Move to the next line after completing a row
    cout << endl;
  }

  return 0;
}