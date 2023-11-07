#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double computeArea(double r) {
    double a = PI * pow(r, 2.0);
    return a;
}

int main(void){
    double radius;

    printf("Enter radius of a circle: ");
    scanf("%lf", &radius);

    double area = computeArea(radius);

    printf("The area of a circle with radius %.2lf is %.2lf\n", radius, area);
    return(0);
    }
        
