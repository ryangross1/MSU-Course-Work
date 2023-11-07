#include <stdio.h>

/*
 * CSCI112 Lab 1, spring 2022
 * author: Ryan Gross
 *
 * calculates total pricing based on eligibility for a military discount and sales tax
 */

double militaryDiscount(double x);

int main(void){
   double cost;
   char inMil;
   double total;     //init all vars
   double disc;
   double discTotal;
   double tax;
   printf("Cost of Purchase:  \t\t $");
   scanf("%lf", &cost);                   //inputs
   printf("In military (y or n)?  \t\t ");
   scanf(" %c", &inMil); 

   if ((inMil == 'y' || inMil == 'Y') && (cost >= 150)){
      total = militaryDiscount(cost) * 1.05;
      discTotal = militaryDiscount(cost);                 //conditions for discount/total calculation
      disc = cost * 0.15;
      tax = cost * 0.05;
      printf("Military Discount (15%%)\t\t $%.2lf\n", disc);
      printf("Discounted Total\t\t $%.2lf\n", discTotal);
      printf("Sales Tax (5%%)\t\t\t $%.2lf\n", tax);
      printf("Total\t\t\t\t $%.2lf\n", total);
   }
   else if ((inMil == 'y' || inMil == 'Y') && (cost < 150)){
      total = militaryDiscount(cost) * 1.05;
      discTotal = militaryDiscount(cost);
      disc = cost * 0.1;
      tax = cost * 0.05;
      printf("Military Discount (10%%)\t\t $%.2lf\n", disc);
      printf("Discounted Total\t\t $%.2lf\n", discTotal);
      printf("Sales Tax (5%%)\t\t\t $%.2lf\n", tax);
      printf("Total\t\t\t\t $%.2lf\n", total);
   }
   else if (inMil == 'n' || inMil == 'N'){
      total = cost * 1.05;
      tax = cost * 0.05;
      printf("Sales Tax (5%%)\t\t\t $%.2lf\n", tax);
      printf("Total\t\t\t\t $%.2lf\n", total);
   }
   else {
       printf("ERROR please try again.\n");
       return(1);
   }
   return(0);
}

double militaryDiscount(double x){
   double disc;
   if (x >= 150){
    disc = x * 0.85;
   }
   else if (x < 150){                          //calculates miitary discount
    disc = x * 0.9; 
   }
   else {
       printf("ERROR please try again");
   }
   return disc;
}
