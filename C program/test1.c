#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]) {
    // printf("Number of arguments: %d\n", argc);
    // for(int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }
    if(argc!=3)
    {
        printf("Please pass necessary two numbers\n");
        return 1;
    }
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    if(start<end)
    {
        printf("Natural numbers between %d and %d are:\n", start, end);
        for(int i = start; i <= end; i++) {
            printf("%d\t",i);
        }
        return 1;
    }
    else if(start>end)
    {
        printf("Natural numbers between %d and %d are:\n", start, end);
        for(int i = start; i >= end; i--) {
            printf("%d\t", i);
        }
        return 1;
    }
    else
    {
        printf("Both numbers are same\n");
        return 1;
    }        
    return 0;
}