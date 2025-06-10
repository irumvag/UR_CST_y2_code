//Circle.h - Header
/* The Circle class Header (Circle.h) */
#include <string>   // using string
using namespace std;
// Circle class declaration
class Circle {
private:   // Accessible by members of this class only
   // private data members (variables)
   double radius;
   string color;
 
public:    // Accessible by all
   // Declare prototype of member functions
   // Constructor with default values
   Circle();
   Circle(double rad1);
   Circle(string col1);
   Circle(double rad1, string col1);
 
   // Public getters & setters for private data members
   double getRadius() const;
   void setRadius(double radius);
   string getColor() const;
   void setColor(string color);
 
   // Public member Function
   double getArea() const;
   double getCircumference() const;
};
