#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

int userQuery(char *line[], Class classes[], int size){
    char choice, nl;
    do {
        printf("Menu:\n");
        printf("n - print class given number\n");
        printf("d - print all classes for a given day combo\n");    //print user menu
        printf("p - print all classes for a given professor\n");
        printf("q - quit\n");
        
        scanf("%c%c", &choice, &nl);  //take user choice; nl accounts for newline

        char numin[30];
        char datein[30];  //init user inputs
        char profin[60];

        switch(choice){
            case 'n':
                printf("Enter class number (CSCI ***): ");
                fgets(numin, 30, stdin);                    //user prompt for class num; takes in classnum as numin
                printNum(numin, classes, size); //print
                break;
            case 'd':
                printf("Enter a day combo (MWF or TR): ");
                fgets(datein, 30, stdin);                   //user prompt for days; takes in days as datein
                printf("List of classes for days %s", datein);
                printDate(datein, classes, size);   //print
                break;
            case 'p':
                printf("Enter professor's last name: ");
                fgets(profin, 60, stdin);                   //user prompt for prof; takes in only proflast as profin
                printf("List of classes for Professor %s", profin);
                printProf(profin, classes, size);
                break;
            
        }

    } while (choice != 'q');    //loop until q

    return(0);
}

void makeStruct(char *line[], Class classes[], int size){
    char* number;
    char* title;
    char* proflast;
    char* proffirst;    //init secondary struct vals as strings
    char* seats;
    char* date; 
    char* time;
    for (int i = 0; i < size-1; i++){ //iterates thorgh each index of the struct whilst assigning values w strtok
        number = strtok(line[i], ",");
        strcpy(classes[i].cnumber, number);

        title = strtok(NULL, ",");
        strcpy(classes[i].ctitle, title);

        seats = strtok(NULL, ",");
        seats = strtok(NULL, ",");
        seats = strtok(NULL, ",");
        seats = strtok(NULL, ",");
        strcpy(classes[i].cseats, seats);

        proflast = strtok(NULL, " ");
        strcpy(classes[i].cproflast, proflast);
        proffirst = strtok(NULL, ",");
        strcpy(classes[i].cproffirst, proffirst); 

        date = strtok(NULL, " ");
        strcpy(classes[i].cdate, date);

        time = strtok(NULL, ".");
        strcpy(classes[i].ctime, time);
    }

}
