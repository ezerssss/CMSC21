#include <stdio.h>

int main(void) {
    int i;
    float x;

    i = 40;
    x = 839.21f;

    // prints i in 4 different ways 
    // normal, 5 spaces right align, 5 spaces left align, 5 spaces right align and 3 digits minimum
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);

    // prints x in 3 different ways 
    // %10.3f = 10 spaces right align with 3 min decimal places
    // %10.3e = 10 spaces right align with 3 min decimal places in exponential form
    // %-10g = 10 spaces left align that could be in exponential or decimal form
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x, x);

    return 0;
}