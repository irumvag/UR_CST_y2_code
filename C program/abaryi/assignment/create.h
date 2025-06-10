#ifndef CREATE_H
#define CREATE_H
#include<stdio.h>
//#include<stdbool.h>
void createumuryi(){
    int id,age;
    char Name[50];
        FILE *file = fopen("abaryi.txt", "w");
        if (file == NULL) {
                printf("Failed to open file\n");
                return;
        }
        printf("\nCreate Umuryi\nEnter umuryi ID: ");
            scanf("%d", &id);
            printf("\nEnter Name: ");
            scanf("%s", Name);
            printf("\nEnter age: ");
            scanf("%d",&age);
        if(fprintf(file,"%d %s %d\n",id,Name,age))
            printf("\nUmuryi added successful..\n");
        else
        printf("\noperation Failed\n");    
        fclose(file);
}
#endif