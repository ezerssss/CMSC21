#include <stdio.h>

int main(void) {
    int days = 0, starting = 0, spaces = 0;

    while (days < 28 || days > 31) {
        printf("Enter number of days in month: ");
        scanf("%d", &days);
    }

    while (starting < 1 || starting > 7) {
        printf("Enter the starting day of the week (1=Sun, 7=Sat): ");
        scanf("%d", &starting);
    }
    printf("\n");

    // Prints the empty spaces
    while (spaces < starting - 1) {
        printf("    ");
        spaces++;
    }

    // Prints the numbers representing the days
    for (int current = 1; current <= days; current++) {
        printf("%2d  ", current);

        // Each line has 7 numbers
        // We also count the empty spaces
        if ((spaces + current) % 7 == 0) {
            printf("\n");
        }
    }

    return 0;
}