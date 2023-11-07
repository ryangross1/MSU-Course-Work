#include <stdio.h>
#include <stdlib.h>


int main(void){
    int *ip = malloc(sizeof(int));
    *ip = 5;
    double *dp = malloc(sizeof(double));
    *dp = 2.5;
    char *cp = malloc(sizeof(char));
    *cp = 'a';
    

    printf("the address of the pointer to the integer is %p\n", ip);
    printf("the value that the pointer is pointing to is %d\n", *ip);
    free(ip);
    printf("the address of the pointer to the double is %p\n", dp);
    printf("the value that the pointer is pointing to is %lf\n", *dp);
    free(dp);
    printf("the address of the pointer to the char is %p\n", cp);
    printf("the value that the pointer is pointing to is %c\n", *cp);
    free(cp);
    return(0);
}
