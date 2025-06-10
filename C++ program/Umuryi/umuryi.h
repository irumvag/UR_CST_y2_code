//============================================================
//umuryi1.h - Header

/* The umuryi1 class Header (umuryi1.h) */

#include <string>   // using string
#include <iostream>
#include "umukiriya.h"

using namespace std;
 
// umuryi1 class declaration
class umuryi1 : public umukiriya1   {


private:   // Accessible by members of this class only
   // private data members (variables)
   int imyakaUmuryi1;
 
public:    // Accessible by ALL
// Constructor
umuryi1(string myAmazinaUmukiriya1, int myImyakaUmuryi1) : umukiriya1(myAmazinaUmukiriya1), imyakaUmuryi1(myImyakaUmuryi1){}
 
// Public getter for private data member imyakaUmuryi1

void erekanaImyakaUmuryi1() {
cout << "Umukiriya witwa: " << getAmazinaUmukiriya1() << " afite imyaka: " << imyakaUmuryi1 << endl;
}


void erekanaUmuryiInfo() {
cout << "Umukiriya witwa: " << getAmazinaUmukiriya1() << " afite imyaka: " << imyakaUmuryi1 << endl;
}

};