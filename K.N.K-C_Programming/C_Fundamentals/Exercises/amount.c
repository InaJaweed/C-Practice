#include <stdio.h>

int main(){
    int dollar = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);

    int dollar20 = dollar / 20;
    dollar = dollar - dollar20 * 20;

    int dollar10 = dollar / 10;
    dollar = dollar - dollar10 * 10;

    int dollar5 = dollar / 5;
    dollar = dollar - dollar5 * 5;

    int dollar1 = dollar / 1;
    dollar = dollar - dollar1 * 1;

    printf("$20 bills: %d\n", dollar20);
    printf("$10 bills: %d\n", dollar10);
    printf("$5 bills: %d\n", dollar5);
    printf("$1 bills: %d\n", dollar1);

    return 0;
}