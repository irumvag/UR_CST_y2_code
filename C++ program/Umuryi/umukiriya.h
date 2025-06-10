//umukiriya1.h - Header

/* The umukiriya1 class Header (umukiriya1.h) */

#include <string>   // using string
#include <iostream>

using namespace std;
 
// umukiriya1 class declaration
class umukiriya1 {

private:   // Accessible by members of this class only

    string amazinaUmukiriya1;
 
public:    // Accessible by ALL

umukiriya1(string myAmazinaUmukiriya1) {
    amazinaUmukiriya1 = myAmazinaUmukiriya1;
}
 
// Public setter for private data member amazinaUmukiriya1
void setAmazinaUmukiriya1(string myAmazinaUmukiriya1) {
    amazinaUmukiriya1 = myAmazinaUmukiriya1;
}
 
// Public getter for private data member amazinaUmukiriya1
string getAmazinaUmukiriya1() const {
    return amazinaUmukiriya1;
}
 
  // A public member function - other methods

void erekanaIzinaUmukiriya() {
    cout << "umukiriya1 wacu yitwa: " << amazinaUmukiriya1 << endl;
}
};