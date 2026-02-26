#include <iostream>
#include <limits>  //for clearing input buffer
#include <random>  //for random number generation

using namespace std;

int main() {
  // initializing the random number device
  random_device rd;
  mt19937 gen(rd());

  // defining the random number range
  uniform_int_distribution<> distr(1, 100);

  // generating 2 random numbers
  int num1 = distr(gen);
  int num2 = distr(gen);
  int sum = num1 + num2;

  // showing the problem
  cout << "   Math tutor: Addition Practice   " << endl;
  cout << "Solve the following problem:" << endl;
  cout << "   " << num1 << " + " << num2 << " =?" << endl;

  // pausing execution using cin.get
  cout << "\nPress [Enter] when you are ready to see the answer   ";
  cin.get();

  // showing the correct solution
  cout << "The correct answer is: " << sum << endl;
  cout << "Great job practicing!" << endl;

  return 0;
}