#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectionSort(char *strs[], int size){
    int i, j;
    char temp[150];

    for (i = 0; i < size-1; i++){
        for (j = i+1; j<size; j++){
            if (strcmp(strs[i], strs[j]) > 0){      //sort from prof cummings example
                strcpy(temp, strs[i]);
                strcpy(strs[i], strs[j]);           
                strcpy(strs[j], temp);
            }
        }
    }
}

void printForm(char *strs[], int size){
    FILE* fwtr = fopen("output.txt", "w");

        char* name;
        char* temp;         //declare vars for each 
        char* category;
        char* date; 
        fprintf(fwtr, "Hurricanes in Florida with category and date\n");
        fprintf(fwtr, "____________________________________________\n");
        for (int i = 0; i<size-1; i++){
            name = strtok(strs[i], ",");
            temp = strtok(NULL, " ");
            category = strtok(NULL, " ");      //splititng line[i] to format 
            temp = strtok(NULL, ",");
            date = strtok(NULL, ".");
            fprintf(fwtr, "%s\t\t%s\t%s", name, category, date);
        }
        fclose(fwtr);
    temp = "\n";        //did this to get rid of temp being unsused warning
    printf("%s", temp); 
}

int main(void){

    FILE* fptr = fopen("/public/lab4/hurricanes.csv", "r"); //open file
    if (fptr == NULL){
        printf("bad file\n");       //catch
        return(1);



    }
    int size;
    char *line[50];  //create array of lines
    //printf("Hurricanes in Florida with category and date\n");
    //printf("____________________________________________\n");

    int i = 0;
    while(1){
        line[i] = malloc(sizeof(char) * 150); //alloc size of each line

        if (fgets(line[i], 150, fptr) == NULL){ //get line and break statement
            break;
        }
        /*
        char* name; 
        name = strtok(line[i], ",");
        char* temp; 
        temp = strtok(NULL, " ");
        char* category;
        category = strtok(NULL, " ");
        temp = strtok(NULL, ",");
        char* date;
        date = strtok(NULL, ".");
        
        printf("%s\t%s\t%s", name, category, date);
        */
        i++;
    }
    fclose(fptr);
    size = i;
    SelectionSort(line, size);
    printForm(line, size);
   // for (int i = 0; i < size; i++){
     //   printf("%s", line[i]);
   // }
}
