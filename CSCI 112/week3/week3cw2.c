#include <stdio.h>

int main(void){
    int sum;
    int counter;
    counter = 0;
    
    while (1 == scanf("%d", &sum)){
        counter += sum;
    }
    printf("The sum is %d\n", counter);
return(0);
}
