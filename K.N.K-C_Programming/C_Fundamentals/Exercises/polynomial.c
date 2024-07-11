#include <stdio.h>

int main(void){
    int x = 0;
    printf("Enter X: ");
    scanf("%d", &x);
    // int poly = (3 * (x*x*x*x*x)) + (2 * (x*x*x*x)) - (5 * (x*x*x)) - ( x * x) + (7 * x) - 6;    
    int poly = ((((3 * x + 2)* x - 5)* x - 1) * x + 7) * x - 6;

    printf("%d\n", poly);
}