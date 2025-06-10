#ifndef DELETE_H
#define DELETE_H
#include<stdio.h>

void deleteabaryi() {
    FILE *file = fopen("abaryi.txt", "r");
    if (!file) {
        printf("No data found!\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(file);
        return;
    }
    int id,id1,age,found = 0;
    char name[50];
    char line[100];
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);
    while (fgets(line,sizeof(line), file)) {
        sscanf(line, "%d %s %d", &id1,name,&age);
        if (id == id1) {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %d\n", id1, name, age);
    }

    fclose(file);
    fclose(temp);
    remove("abaryi.txt");
    rename("temp.txt", "abaryi.txt");
    if (found)
        printf("Umuryi deleted successfully!\n");
    else
        printf("ID not found!\n");
}
#endif