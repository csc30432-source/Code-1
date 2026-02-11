#include <iostream>
using namespace std;

int main() {
  const int total = 16500;
  const double drinks = 0.15;
  const double citrus = 0.58;

  double drinkPurchasers = total * drinks;
  double citrusDrinkers = drinkPurchasers * citrus;

  cout << "Energy Drink Survey Results:" << endl;
  cout << "Approximate number of weekly purchasers: " << drinkPurchasers
       << endl;
  cout << "Approximate number of citrus-flavor fans: " << citrusDrinkers
       << endl;

  return 0;
}