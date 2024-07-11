#include <stdio.h>

int main(void){

    float loan = 0, interest_rate = 0, monthly_payment = 0;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    // 20000 - 386 + (20000 * 12 / 100 /12)

    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12);
    printf("Balance remaining after first payment: $%.2f\n", loan);

    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12);
    printf("Balance remaining after second payment: $%.2f\n", loan);

    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12);
    printf("Balance remaining after third payment: $%.2f\n", loan);

    return 0;
}