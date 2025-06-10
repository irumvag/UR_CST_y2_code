#include<iostream>
#include<string>
#ifndef UMUKIRIYA_H
#define UMUKIRIYA_H
using namespace std;
class Umukiriya{
    private:
    string amazinaUmukiriya;
    public:
    Umukiriya();
    Umukiriya(string myAmazinaUmukiriya);
    void setAmazinaUmukiriya(string myAmazinaUmukiriya);
    string getAmazinaUmukiriya();
    void erekanaIzinaUmukiriya();
};
#endif