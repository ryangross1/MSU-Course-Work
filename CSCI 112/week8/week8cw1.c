//your header will have a struct with 2 attributes - for class number ans class title
//class title
#include "class.h"
#include <stdio.h>
#include <string.h>

int main (void){
    //open the file
    FILE* fptr = fopen("/public/pgm1/classes.csv", "r");
    //check that the file is open (not NULL)
    if (fptr == NULL){
        printf("bad file name");
        return(1);
     }
    Class class1;

    char line[100];
    //read in one line
    fgets(line, 100, fptr);
    //printf(line);

    //pull off the first two items on the line and put in your struct
    char *classnum;
    classnum = strtok(line, ",");
    strcpy(class1.cnumber, classnum);
    //printf("%s", classnum);
    
    char *classtitle;
    classtitle = strtok(NULL, ",");
    strcpy(class1.ctitle, classtitle);
    //printf("%s", classtitle);

    //close your file
    fclose(fptr);
    char choice;

    //printf("Menu:\n");
    //printf("Class number:\tn\n");
    //printf("Class title:\tt\n");
    //printf("Quit:\t\tq\n");
    do {
        //ask user for choice
        printf("Menu:\n");              //not sure why menu is printing twice after first loop
        printf("Class number:\tn\n");
        printf("Class title:\tt\n");
        printf("Quit:\t\tq\n");
        
        //read in choice as a char
        scanf("%c", &choice);

        //switch on choice
        switch(choice){
            case 'n':
               //printf("n selected");
                printf("%s\n", classnum);
                printf("\n");
                break;
            case 't':
                //printf("t selected");
                printf("%s\n", classtitle);
                printf("\n");
                break;            
        }

    } while (choice != 'q');

 return(0);
}
