#include "class.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE* fptr = fopen("/public/pgm1/classes.csv", "r");    //open file
    if (fptr == NULL){
        printf("file error");   //catch
        return(1);
    }
    int size;
    char *line[20]; //create array of lines
    Class classes[50]; //create array of structs

    int i = 0;
    while (1){
        line[i] = malloc(sizeof(char) * 150);  //alloc line size

        if (fgets(line[i], 150, fptr) == NULL){  //read in lines and break on end
            break;
        }
        //printf("%s", line[i]);
        i++;
    }
    size = i;

    makeStruct(line, classes, size);
    userQuery(line, classes, size);
    // TO DO
    // ask user; process response
    // parse line into struct values
    // print format
}
