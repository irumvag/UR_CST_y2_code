#ifndef UMURYI_H
#define UMURYI_H
#include "umukiriya.h"
#include "umunywi.h"
#include "ibiribwa.h"
#include<string>
using namespace std;
class Umuryi : public Umukiriya, public Umunywi,public ibiribwa 
    {
    private:  
    float totalpaid=0;
    int choice;
    public:
    void kurya();
    float gettotal1();
    void setibiryo();
    void setibyokurya();
    };
#endif