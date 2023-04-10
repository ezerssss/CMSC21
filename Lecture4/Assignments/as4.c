#include <stdio.h>

int main(void) {
    int result;
    
    printf("TABLE OF POWERS OF TWO\n\n");
    printf(" n\t   2 to the n\n");
    printf("---\t---------------\n");

    for (int n = 0; n < 11; n++) {
        result = 1;

        for (int i = 0; i < n; i++) {
            result *= 2;
        }

        printf(" %d\t     %d\n", n, result);
    }

    return 0;
}