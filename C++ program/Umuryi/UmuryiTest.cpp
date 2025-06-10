#include "umuryi.h"
int main(int argc, char** argv) {
    umuryi1 c2("Muhanga", 25);
    c2.erekanaUmuryiInfo();
    string names=c2.getAmazinaUmukiriya1();
    cout << "Umuryi wacu yitwa: " << names << endl;               
    return 0;
}