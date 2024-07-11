#include <stdio.h>

int main(void){
    float money = 0;
    printf("Enter An Amount: ");
    scanf("%f", &money);

    printf("With Tax Added: $%.2f\n", money * 1.05f); 
    
    return 0;
}