#ifndef READ_h
#define READ_h
void rebaumuryi(){
    FILE *file = fopen("abaryi.txt", "r");
        if (file == NULL) {
                printf("Failed to open file\n");
                return;
        }
    int id,age;
    char name[50];
    char line[100];
    printf("\nList of all abaryi: \n");
    while (fgets(line,sizeof(line), file)) {
        sscanf(line, "%d %s %d", &id,name,&age);
        printf("\nID: %d | Name: %s | AGE: %d",id,name,age);
    }
    printf("\n\n  End of read \n\n");
    fclose(file);
}
#endif