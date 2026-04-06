#include <iostream>
#include <random>  // Required for modern random number generation

using namespace std;

int main() {
  // 1. Initialize the random number generator
  random_device rd;
  mt19937 gen(rd());

  // 2. Define the distribution range
  uniform_int_distribution<> distr(1, 100);

  // 3. Generate the random target number
  int randomNumber = distr(gen);
  int userGuess = 0;
  int guessCount = 0;  // Keep a count of the number of guesses

  cout << "Welcome to the Random Number Guessing Game!" << endl;
  cout << "I have generated a number between 1 and 100." << endl;

  // 4. Use a loop that repeats until the correct guess
  while (userGuess != randomNumber) {
    cout << "Enter your guess: ";

    // Basic validation for interactive input
    if (!(cin >> userGuess)) {
      cout << "Invalid input. Please enter a number." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    guessCount++;  // Increment attempt counter

    // 5. Provide meaningful feedback
    if (userGuess > randomNumber) {
      cout << "Too high, try again." << endl;
    } else if (userGuess < randomNumber) {
      cout << "Too low, try again." << endl;
    } else {
      // 6. Success message and final guess count
      cout << "Congratulations! You guessed the correct number." << endl;
      cout << "Total attempts: " << guessCount << endl;
    }
  }

  return 0;
}