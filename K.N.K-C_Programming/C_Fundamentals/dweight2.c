/* Computes the dimensional weight of a 
   box from input provided by the user */

#include <stdio.h>

#define INCHES_PER_POUND 166

int main(void){
    int height = 0, length = 0, width = 0, volume = 0, weight = 0;
    
    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length: of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);

    volume = height * length * width;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}