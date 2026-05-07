#include <iostream>
#include <string>

/**
 * Purpose: Prompts the user for the rectangle’s dimensions and validates input.
 * Preconditions: None.
 * Postconditions: length > 0 and width > 0. Validated values are returned to
 * the caller via reference parameters.
 */
void getLengthWidth(double& length, double& width);

/**
 * Purpose: Calculates and returns the perimeter of a rectangle.
 * Preconditions: length and width have already been validated.
 * Postconditions: Returns the calculated perimeter.
 */
double calcPerimeter(double length, double width);

/**
 * Purpose: Calculates and returns the area of a rectangle.
 * Preconditions: length and width have already been validated.
 * Postconditions: Returns the calculated area.
 */
double calcArea(double length, double width);

/**
 * Purpose: Displays the perimeter and area.
 * Preconditions: Valid perimeter and area values are provided.
 * Postconditions: Results are written to the console.
 */
void displayProperties(double perimeter, double area);

/**
 * main()
 * Purpose: Controls program flow. Repeats processing based on user choice.
 */
int main() {
  double length, width, perimeter, area;
  char choice;

  do {
    // Get input from user
    getLengthWidth(length, width);

    // Perform calculations
    perimeter = calcPerimeter(length, width);
    area = calcArea(length, width);

    // Display results
    displayProperties(perimeter, area);

    // Ask user to repeat or quit
    std::cout << "\nWould you like to process another rectangle? (y/n): ";
    std::cin >> choice;
    std::cout << std::endl;

  } while (choice == 'y' || choice == 'Y');

  return 0;
}

void getLengthWidth(double& length, double& width) {
  // Validation for Length
  do {
    std::cout << "Enter the rectangle length (must be > 0): ";
    std::cin >> length;
    if (length <= 0) {
      std::cout << "Invalid input. ";
    }
  } while (length <= 0);

  // Validation for Width
  do {
    std::cout << "Enter the rectangle width (must be > 0): ";
    std::cin >> width;
    if (width <= 0) {
      std::cout << "Invalid input. ";
    }
  } while (width <= 0);
}

double calcPerimeter(double length, double width) {
  return 2 * (length + width);  // [cite: 24]
}

double calcArea(double length, double width) { return length * width; }

void displayProperties(double perimeter, double area) {
  std::cout << "\n--- Rectangle Properties ---" << std::endl;
  std::cout << "Perimeter: " << perimeter << std::endl;
  std::cout << "Area:      " << area << std::endl;
}