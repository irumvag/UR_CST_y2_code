#include "umuryiheader.h"
#include "abakiriya.h"
#include "umunywiheader.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{
    bool b=true;
    Umuryi obj;
    string name;
    int i;
    cout<<"\nEnter name of Umukiriya:";
    cin>>name;
    obj.setAmazinaUmukiriya(name);
    cout<<"\n\n";
    obj.erekanaIzinaUmukiriya();
    label:
    while(b)
    {
    cout<<"Enter number based on your choice:\n  1.Umuryi\n  2.Umunywi\n  3.Kunywa & kurya\n  0.exit\n Enter your choice:";
    cin>>i;
    switch (i)
    {
    case 0:
        b=false;
        continue;
    case 1:
        cout<<"\nYou are welcome Umuryi!!\n"<<obj.getAmazinaUmukiriya();
        obj.getibiribwa();
        obj.setibyokurya();
        obj.kurya();
        cout<<"\nThe total amount to pay for Umuryi:"<<(obj.gettotal1()+obj.gettotal2())<<"Rwf\n\n";
        break;
    case 2:
        cout<<"\nYou are welcome Umuryi!!\n"<<obj.getAmazinaUmukiriya();
        obj.getibinyobwa();
        obj.seticyokunywa();
        obj.kunywa();
        cout<<"\nThe total amount to pay for umunywi:"<<(obj.gettotal1()+obj.gettotal2())<<"Rwf\n\n";
        break;
    case 3:
        cout<<"\nYou are welcome Umuryi & Umunywi!!\n"<<obj.getAmazinaUmukiriya();
        obj.getibiribwa();
        obj.setibyokurya();
        obj.getibinyobwa();
        obj.seticyokunywa();
        obj.kurya();
        obj.kunywa();
        cout<<"\nThe total amount to pay for Umunyi and umunywi:"<<(obj.gettotal1()+obj.gettotal2())<<"Rwf\n\n";
        break;
    default:
        cout<<"\nIncorrect choice....\n\n";
        break;
    }
    }
    return 0;
}
