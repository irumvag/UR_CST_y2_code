#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    cout<<"The top elements:"<<s1.top()<<endl;
    s1.pop();
    cout<<"sixe of stack"<<s1.size()<<endl;
    if(!s1.empty())
    {
        cout<<"Stack is not empty!"<<endl;
    }
    return 0;
}