#include <stdio.h>

int main(void){
    //open the input file
    FILE* fptr = fopen("/public/examples/chap7/wed_2-9_in.txt", "r");
    if (fptr == NULL){
        //print an error msg and exit or return(1)
        printf("ERROR you goofed\n");
        return(1);
    }

    //declare 2 dimensional array
    int arr[6][8];
    int num;
    int i = 0, j = 0;
    while(fscanf(fptr, "%d", &num) == 1){
        
        //put the number in the array
        if (num != 0){
            arr[i][j++] = num;
        }    
        else {
            arr[i++][j] = num;
            j = 0;
        }
    }
    fclose(fptr);
    
    int total_rows = i;
    int sum = 0;
    for (int i = 0; i < total_rows; i++){
        for (int j = 0; j < 8; j++){
            if (arr[i][j] != 0){
                sum += arr[i][j];
            }
            else {
                printf("Sum is: %d\n", sum);
                sum = 0;
                break;
            }
        }
    }
    return(0);
}
