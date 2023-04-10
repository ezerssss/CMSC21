#include <stdio.h>

int main(void) {
    int i;

    i = 11;
    // while loop (a)
    while (i < 10) {
        printf("i: %d\n", i);
        i++;
    }

    i = 11;
    // for loop (b)
    for (; i < 10;) {
        printf("i: %d\n", i);
        i++;
    }

    i = 11;
    // do-while loop (c)
    do {
        printf("i: %d\n", i);
        i++;
    } while (i < 10);

    return 0;
}