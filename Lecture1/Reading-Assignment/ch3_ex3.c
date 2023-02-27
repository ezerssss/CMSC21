#include <stdio.h>

int main(void) {
    int num1, denom1, num2, denom2, result_num, result_denom; 

    printf ("Enter first fraction: ");
    scanf("%d/ %d", &num1, &denom1);

    printf ("Enter second fraction: ");
    scanf("%d/ %d", &num2, &denom2);

    // multiplying the numerators with the opposite denominators ensures that 
    // both the numerators are a factor of the denominators
    result_num = num1 * denom2 + num2 * denom1;

    // easiest way to get the common factor is by multiplying the denominators
    result_denom = denom1 * denom2;

    // the resulting fraction is not always in the simplest form
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}