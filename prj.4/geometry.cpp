#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  const double PI = 3.14159;

  int choice;
  double radius, length, width, base, height, area;

  // display menu
  cout << "Geometry Calculator" << endl;
  cout << "1. Calculate the Area of a Circle" << endl;
  cout << "2. Calculate the Area of a Rectangle" << endl;
  cout << "3. Calculate the Area of a Triangle" << endl;
  cout << "4. Quit" << endl;
  cout << "Enter your choice (1-4): ";
  cin >> choice;

  // formatting
  cout << fixed << setprecision(2);

  // Process user choice
  switch (choice) {
    case 1:
      cout << "Enter the radius of the circle: ";
      cin >> radius;
      if (radius < 0) {
        cout << "Error : Radius cannot be negative." << endl;
      } else {
        area = PI * pow(radius, 2);
        cout << "The area of the circle is : " << area << endl;
      }
      break;

    case 2:
      cout << "Enter the length of the rectangle: ";
      cin >> length;
      cout << "Enter the width of the rectangle: ";
      cin >> width;
      if (length < 0 || width < 0) {
        cout << "Error: Dimensions cannot be negative." << endl;
      } else {
        area = length * width;
        cout << "The area of the rectangle is: " << area << endl;
      }
      break;

    case 3:
      cout << "Enter the base of the triangle: ";
      cin >> base;
      cout << "Enter the height of the triangle: ";
      cin >> height;
      if (base < 0 || height < 0) {
        cout << "Error: Dimensions cannot be negative." << endl;
      } else {
        area = base * height * 0.5;
        cout << "The area of the triangle is : " << area << endl;
      }
      break;

    case 4:
      cout << "Exiting the program..." << endl;
      break;

    default:
      cout << "Error: Choice must be between 1 and 4." << endl;
      break;
  }
  return 0;
}