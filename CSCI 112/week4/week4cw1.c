#include <stdio.h>

int main(void){
    int num;
    int arr[5];
    printf("Enter a 5 digit number: ");
    scanf("%d", &num);
    
    for (int i = 0; i < 5; ++i){
        arr[i] = num % 10;
        num /= 10;
    }
    //print the array backwards
    for (int i = 4; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return(0);
}

