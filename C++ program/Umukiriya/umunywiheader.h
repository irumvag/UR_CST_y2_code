#include "umunywi.h"
#include "ibinyobwa.h"
#include<string>
using namespace std;
    void ibinyobwa::getibinyobwa()
    {
        cout<<"\nDrink menu:\n";
        for(int i=0;i<4;i++)
        {
            cout<<i+1<<" > "<<ibinyobwa[0][i]<<" : "<<ibinyobwa[1][i]<<"\n";
        }
        cout<<"0.Go back\n";
    }
    void Umunywi::kunywa()
    {
        cout<<"Umukiya is drinking !!  ("<<ibinyobwa[0][c-1]<<")\n\n";
    }
    float Umunywi::gettotal2()
    {
        return gettotal;
    }
    void Umunywi::seticyokunywa()
    {
        label1:
        cout<<"\nEnter your choice from menu:";
        cin>>c;
        if(c==0||(c>4||c<0))
        {
            cout<<"\nYour choice is incorrect Try again\n";
            goto label1;
        }
        else
        gettotal+=stoi(ibinyobwa[1][c-1]);
    }