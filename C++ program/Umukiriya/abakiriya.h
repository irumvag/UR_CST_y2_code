#ifndef ABAKIRIYA_H
#define ABAKIRIYA_H
#include "umukiriya.h"
#include<iostream>
using namespace std;
Umukiriya::Umukiriya()
{
    cout<<"You are welcome Umukiriya\n";
}
Umukiriya::Umukiriya(string myAmazinaUmukiriya)
{
    cout<<"You are welcome Umukiriya\n";
    this->amazinaUmukiriya=myAmazinaUmukiriya;
}
void Umukiriya::setAmazinaUmukiriya(string myAmazinaUmukiriya)
{
    this->amazinaUmukiriya=myAmazinaUmukiriya;
}
string Umukiriya::getAmazinaUmukiriya()
{
    return amazinaUmukiriya;
}
void Umukiriya::erekanaIzinaUmukiriya()
{
    cout<<"Izina ryumukiriya: "<<amazinaUmukiriya;
}
#endif