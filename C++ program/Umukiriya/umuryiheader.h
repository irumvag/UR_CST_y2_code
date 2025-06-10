#include "umuryi.h"
#include "ibiribwa.h"
#include<iostream>
#include<string>
#ifndef UMURYIHEADER_H
#define UMURYIHEADER_H
using namespace std;
    void ibiribwa::getibiribwa()
    {
        cout<<"\nFood menu:\n";
        for(int i=0;i<4;i++)
        {
            cout<<i+1<<" > "<<ibiribwa[0][i]<<" : "<<ibiribwa[1][i]<<"\n";
        }
        cout<<"0.Go back\n";
    }
    void Umuryi::kurya()
    {
        cout<<"\nUmukiriya is eating!! ("<<ibiribwa[0][choice-1]<<")\n\n";
    }
    float Umuryi::gettotal1()
    {
        return totalpaid;
    }
    void Umuryi::setibyokurya()
    {
        label1:
        cout<<"\nEnter your choice from menu:";
        cin>>choice;
        if(choice==0||(choice>4||choice<0))
        {
            cout<<"\nIncorrect choice\n try again:\n";
            goto label1;
        }
        else
        {
        totalpaid+=stoi(ibiribwa[1][choice-1]);
        }

    }
#endif