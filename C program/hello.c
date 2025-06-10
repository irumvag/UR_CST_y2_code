#include<stdio.h>
void calc(int a,int b,int c){
    int sum=a+b+c;
    int prod=a*b*c;
    float div=a/b;
    int diff=a-b;
    printf("sum is: %d\n",sum);
    printf("difference is: %d\n",diff);
    printf("division is: %d\n",div);
    printf("product is: %d\n",prod);
}
void info(string village){
    printf("ENter your village: ");
    scanf("%s",&village);
}
void display(){
    printf ("Your village is: %s", info(village));
}
int main(){
 calc(5,3,1);
 info();
 display();
}