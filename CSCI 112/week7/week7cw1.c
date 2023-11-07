#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    //read in first line /public/lab4/hurricanes.csv
    FILE* fptr = fopen("/public/lab4/hurricanes.csv", "r");
    if (fptr == NULL){
        printf("bad file name\n");
        return(1);
    }
    //set aside memory for line - malloc
    char line[75]; //= malloc(sizeof(char) * 50);
    //use fgets to read first line
    fgets(line, 75, fptr);
    char *result; //needs no memory allocates because it is pointing somewhere in line
    result = strtok(line, ",");
    //print result
    printf("Hurricane name: %s\n", result);
    result = strtok(NULL, ",");
    //print result
    printf("Type: %s\n", result);
    result = strtok(NULL, ",");
    //print result
    printf("Date: %s", result);
    result = strtok(NULL, ",");
    //print result which will be " 1950"
    printf(" %s", result);

    return(0);
}
