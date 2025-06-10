#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,num1,num2;
    int sum,sub;
    cout<<"enter:";
    cin>>a;
    if(a[2]=='+')
    {
        num1=a[0];
        num2=a[1];
        sum=stoi(num1)+stoi(num2);
        cout<<"\nThe sum is:"<<sum;
    }
    else if(a[2]=='-')
    {
        num1=a[0];
        num2=a[1];
        sum=stoi(num1)-stoi(num2);
        cout<<"\nThe sub is:"<<sum;
    }
    else if(a[2]=='*')
    {
        num1=a[0];
        num2=a[1];
        sum=stoi(num1)*stoi(num2);
        cout<<"\nThe mult is:"<<sum;
    }
    else if(a[2]=='/')
    {
        num1=a[0];
        num2=a[1];
        sum=stoi(num1)/stoi(num2);
        cout<<"\nThe div is:"<<sum;
    }

    return 0;
}
