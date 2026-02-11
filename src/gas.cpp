#include <iostream>
using namespace std;

int main() {
  const double tanksize = 20.0;
  const double townmpg = 23.5;
  const double highwaympg = 28.9;

  double townDistance, highwayDistance;

  townDistance = tanksize * townmpg;
  highwayDistance = tanksize * highwaympg;

  cout << "Distance per tank of gas:" << endl;
  cout << "In town: " << townDistance << " miles" << endl;
  cout << "On highway: " << highwayDistance << " miles" << endl;

  return 0;
}