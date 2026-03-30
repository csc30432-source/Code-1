#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double weight, distance, rate, totalCost;
  int scalingFactor;

  // set output for currency
  cout << fixed << setprecision(2);

  // get user input
  cout << "Enter the weight of the package (in kg): ";
  cin >> weight;
  cout << "Enter the distance it is to be shipped (in miles): ";
  cin >> distance;

  // Input validation
  if (weight <= 0 || weight > 20) {
    cout << "Error: Weight must be greater than 0 and no more than 20 kg."
         << endl;
    return 1;
  }
  if (distance < 10 || distance > 3000) {
    cout << "Error: Distance must be between 10 and 3000 miles." << endl;
    return 1;
  }

  // Determine the rate based on weight tiers
  if (weight <= 2.0) {
    rate = 1.10;
  } else if (weight <= 6.0) {
    rate = 2.20;
  } else if (weight <= 10.0) {
    rate = 3.70;
  } else {
    rate = 4.80;
  }

  // Calculate the distance scaling factor
  scalingFactor = static_cast<int>(ceil(distance / 500.0));

  // Calculate total cost
  totalCost = rate * scalingFactor;

  // Display results
  cout << "\n--- Shipping Invoice ---" << endl;
  cout << "weight:   " << weight << " kg" << endl;
  cout << "Distance: " << distance << " miles" << endl;
  cout << "Rate:   $" << rate << " per 500 miles" << endl;
  cout << "Total:   $" << totalCost << endl;

  return 0;
}