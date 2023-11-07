#include <stdio.h>

//program takes user input for a multi-digit number, sums the digits, and determines if the sum is divisible
//by 9

int math(int x);


int main(void){
   int num;
   int sum;
   printf("Enter a number to check (0 to end): ");
   scanf("%d", &num);
   if (num != 0){
   //save off user input as an array of integers
       sum = math(num);
       if (sum % 9 == 0){
            printf("Since %d is divisible by 9, %d is divisible by 9\n", sum, num);
       }
       else {
            printf("Since %d is not divisible by 9, %d is not divisible by 9\n", sum, num);
       }
   }
   else {
        printf("\n");
        return(0);
   }
} 


int math(int x){
    int sum = 0;
    int digit[7];
    int i = 0;
    while (x > 9){        
        digit[i] = x % 10;
        sum += digit[i];
        x /= 10;
        i++;
     }
     digit[i] = x;
     sum += digit[i];
    for (int j = i; j > 0; j--){ 
        printf("%d + ", digit[j]);
    }
    printf("%d = %d\n", digit[0], sum);
    return(sum);
}
