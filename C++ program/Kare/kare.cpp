#include <iostream>
#include <string>

using namespace std;

class Kare {
private:
    double side;
    string color;

public:
    // Constructor
    Kare(double s, string c) : side(s), color(c) {}

    // Default constructor
    Kare() : side(1), color("red") {}

    // Setter for color
    void setColor(string c) {
        color = c;
    }

    // Getter for color
    string getColor() const {
        return color;
    }

    // Setter for side
    void setSide(double s) {
        side = s;
    }

    // Getter for side
    double getSide() const {
        return side;
    }

    // Function to get area
    double getArea() const {
        return side * side;
    }

    // Function to get perimeter
    double getPerimeter() const {
        return 4 * side;
    }
};

int main() {
    Kare square(5.0, "red");
    cout << "Color: " << square.getColor() << endl;
    cout << "Area: " << square.getArea() << endl;
    cout << "Perimeter: " << square.getPerimeter() << endl;

    square.setColor("blue");
    cout << "New Color: " << square.getColor() << endl;

    Kare defaultSquare;
    cout << "Default Color: " << defaultSquare.getColor() << endl;
    cout << "Default Side: " << defaultSquare.getSide() << endl;

    defaultSquare.setSide(3.0);
    defaultSquare.setColor("green");
    cout << "Updated Default Square - Color: " << defaultSquare.getColor() << ", Side: " << defaultSquare.getSide() << endl;
    cout << "Updated Default Square - Area: " << defaultSquare.getArea() << ", Perimeter: " << defaultSquare.getPerimeter() << endl;

    return 0;
}