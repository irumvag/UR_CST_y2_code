#include "prototypes.h"
#include<stdio.h>
#ifndef CALCBODIES_H
#define CALCBODIES_H

int add(int a, int b, int c){
    return a+b+c;
}
int product(int a, int b, int c){
    return a*b*c;
}
int diff(int a, int b){
    return a-b;
}
float divi(float a, float b){
    return a/b;
}
void display(){
    printf("Village is: Ingeri\n");
    printf("Isibo is: Amahoro\n");
    printf("Cell is: Bibare\n");
    printf("Sector is: Kimironko\n");
    printf("District is: Gasabo\n");
    printf("Province is: Kigali city\n");
}

#endif