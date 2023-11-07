#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    FILE* fptr = fopen("/public/examples/chap8/strings.txt", "r");
    if (fptr == NULL){
        printf("bad file name\n");
        return(1);
    }

    char *arr[20]; //20 pointers = 20 strings

    int n = 0;
    
    arr[n] = malloc(sizeof(char) * 25);
    while (fscanf(fptr, "%s", arr[n]) == 1){
        ++n;
        arr[n] = malloc(sizeof(char) * 25);
    }
    
    for (int i = 0; i < n; i++){
        printf("%s starts with %c\n", arr[i], arr[i][0]);
    }
    return(0);
}
