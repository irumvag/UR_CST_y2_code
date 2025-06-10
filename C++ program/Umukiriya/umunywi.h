#ifndef UMUNYWI_H
#define UMUNYWI_H
#include "ibinyobwa.h"
using namespace std;
class Umunywi: public ibinyobwa {
    private:
    int c;
    float gettotal=0;
    public:
    void kunywa();
    float gettotal2();
    void seticyokunywa();
};
#endif