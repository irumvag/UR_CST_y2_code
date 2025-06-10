#include<stdio.h>
#include "create.h"
#include "delete.h"
#include "read.h"
#include "update.h"
#include<stdbool.h>
int main()
{
    bool t=true;
    while(t){ 
    printf("You're welcome Umuryi..\n\nEnter number accourding to our choice.\n 1.Add Umuryi.\n 2.Delete Umuryi\n 3.Update Umuryi\n 4.View Abaryi\n 0.To exit()\n  Enter your choice: ");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 0:
        t=false;
        break;
        case 1:
        createumuryi();
        break;
        case 2:
        deleteabaryi();
        break;
        case 3:
        updateabaryi();
        break;
        case 4:
        rebaumuryi();
        break;
        default:
        printf("\n!!!! invalid input");
    }
    }
    return 0;
}