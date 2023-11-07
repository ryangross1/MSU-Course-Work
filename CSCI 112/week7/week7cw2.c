#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectionSort(char *strs[], int size){
    int i, j;
    char temp[75];

    for (i = 0; i <size-1; i++){
        for (j = i+1; j<size; j++){
            if (strcmp(strs[i], strs[j]) > 0){
                strcpy(temp, strs[i]);
                strcpy(strs[i], strs[j]);
                strcpy(strs[j], temp);
            }
        }
    }
}



int main(void){
    //open file /public/lab4/hurricanes.csv
    FILE* fptr = fopen("/public/lab4/hurricanes.csv", "r");
    //check that fptr in not null
    if (fptr == NULL){
        printf("bad file name\n");
        return(1);
    }
    int size;
    //create array of lines
    char *line[50];
    //loop while (1)
    int i = 0;
    while (1){
    //  malloc memory for one line
        line[i] = malloc(sizeof(char) * 75);
    //  readin line using fgets
       // fgets(line, 75, fptr);
    //end loop
        
        if (fgets(line[i], 75, fptr) == NULL){
            break;
        }
        i++;
    }
    size = i;
    //SelectionSort with array of lines
    SelectionSort(line, size);
    //printf("got here");
    //loop on number of lines
    //print each line in sorted order
    for (int i = 0; i < size; i++){
         printf("%s", line[i]);
    }
}
