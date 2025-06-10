#include <iostream>
#include "Circle.h"   // using Circle class
using namespace std;
int main(int argc, char** argv) {
   Circle c1;  // Removed parentheses
     cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()<< " Color=" << c1.getColor() << endl;
     c1.setRadius(2.1);   // Change radius and color of c1
     c1.setColor("blue");
     cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()<< " Color=" << c1.getColor() << endl;
     Circle c2;
     cout << "Radius=" << c2.getRadius() << " Area=" << c2.getArea()<< " Color=" << c2.getColor()  << endl;
     Circle c3(3.4);  
     cout << "Radius=" << c3.getRadius() << " Area=" << c3.getArea() << " Color=" << c3.getColor()  << endl;
     Circle c4("green"); 
     cout << "Radius=" << c4.getRadius() << " Area=" << c4.getArea()<< " Color=" << c4.getColor()  << endl;
     Circle c5(5.5, "yellow"); 
     cout << "Radius=" << c5.getRadius() << " Area=" << c5.getArea() << " Color=" << c5.getColor()  << endl;
     Circle c6(6.6, "black");
     cout << "Radius=" << c6.getRadius() << " Area=" << c6.getArea()<< " Color=" << c6.getColor()  << endl;
   return 0;
}
