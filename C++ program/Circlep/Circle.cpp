//Circle.cpp - Implementation
/* The Circle class Implementation (Circle.cpp) */
#include "Circle.h" // user-defined header in the same directory
 
// Constructor
// default values shall only be specified in the declaration,
// cannot be repeated in definition
Circle::Circle(){
 radius = 1.0;
 color = "red";
}

Circle::Circle(double r) {
   radius = r;
   color = "red";
}
 
Circle::Circle(string c) {
   radius = 1.0;
   color = c;
}
 
Circle::Circle(double r, string c) {
   radius = r;
   color = c;
}
 
// Public getter for private data member radius
double Circle::getRadius() const {
   return radius;
}
 
// Public setter for private data member radius
void Circle::setRadius(double r) {
   radius = r;
}
// Public getter for private data member color
string Circle::getColor() const {
    return color;
 }
  
 // Public setter for private data member color
 void Circle::setColor(string c) {
    color = c;
 }
  
 // A public member function
 double Circle::getArea() const {
    return radius*radius*3.14159265;
 }
 
 double Circle::getCircumference() const {
    return 2*radius*3.14159265;
 }
 