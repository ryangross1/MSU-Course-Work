#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "class.h"

void printNum(char *numin, Class classes[], int size){ //print one class given number
    for (int i = 0; i<size-1; i++){
        if (strncmp(numin, classes[i].cnumber, 8) == 0){  //iterates through struct and prints based on compare result (same for all three methods)
            printf("%-35s %-25s %-10s %-15s %-15s %-5s %-5s",  classes[i].ctitle, classes[i].cnumber, classes[i].cproflast, classes[i].cproffirst, classes[i].cseats, classes[i].cdate, classes[i].ctime); 
       }
    }
}

void printDate(char *datein, Class classes[], int size){ //print all classes of a certain day combo
    for (int i = 0; i<size-1; i++){
        if (strncmp(datein, classes[i].cdate, strlen(datein)-1) == 0){ 
            printf("%-35s %-25s %-10s %-15s %-15s %-5s %-5s",  classes[i].ctitle, classes[i].cnumber, classes[i].cproflast, classes[i].cproffirst, classes[i].cseats, classes[i].cdate, classes[i].ctime);
        }
    }
}

void printProf(char *profin, Class classes[], int size){ //print all classes of one prof
    for (int i = 0; i<size-1; i++){
        if (strncmp(profin, classes[i].cproflast, strlen(profin)-1) == 0){
            printf("%-35s %-25s %-10s %-15s %-15s %-5s %-5s",  classes[i].ctitle, classes[i].cnumber, classes[i].cproflast, classes[i].cproffirst, classes[i].cseats, classes[i].cdate, classes[i].ctime);
        }
    }
}
