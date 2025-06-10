#ifndef UPDATE_H
#define UPDATE_H
void updateabaryi(){
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
    int id,id1,age,age5,id5,found = 0;
    char name[50],name5[50];
    char line[100];
    printf("\nEnter ID to Edit: ");
    scanf("%d", &id);
    while (fgets(line,sizeof(line), file)) {
        sscanf(line, "%d %s %d", &id1,name,&age);
        if (id == id1) {
            found = 1;
            printf("\nUpdate Umuryi %s\nEnter umuryi ID: ",name);
            scanf("%d", &id5);
            printf("\nEnter Name: ");
            scanf("%s", name5);
            printf("\nEnter age: ");
            scanf("%d",&age5);
            fprintf(temp, "%d %s %d\n", id5, name5, age5);
            continue;
        }
        fprintf(temp, "%d %s %d\n", id1, name, age);
    }

    fclose(file);
    fclose(temp);
    remove("abaryi.txt");
    rename("temp.txt", "abaryi.txt");
    if (found)
        printf("Umuryi updated successfully!\n");
    else
        printf("ID not found!\n");
}
#endif