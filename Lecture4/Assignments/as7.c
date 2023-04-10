#include <stdio.h>
#define NUM_DESTINATIONS ((int) (sizeof(road_networks) / sizeof(road_networks[0])))
#define ASCII_A 65

int main(void) {
    int road_networks[][9] = {
       //A  B  C  D  E  F  G  H  I  
        {1, 1, 0, 0, 0, 1, 0, 0, 0}, // A
        {1, 1, 1, 0, 0, 0, 0, 0, 0}, // B
        {0, 1, 1, 0, 1, 1, 0, 0, 1}, // C
        {0, 0, 0, 1, 1, 0, 0, 0, 0}, // D
        {0, 0, 0, 1, 1, 0, 0, 0, 0}, // E
        {0, 0, 1, 0, 0, 1, 0, 0, 0}, // F
        {1, 0, 0, 1, 0, 0, 1, 0, 0}, // G
        {0, 0, 0, 0, 0, 0, 0, 1, 1}, // H
        {0, 0, 0, 0, 0, 0, 0, 1, 1}, // I
    };

    // UPPER LABEL
    printf("  ");
    for (int i = 0; i < NUM_DESTINATIONS; i++) {
        printf("%2c ", ASCII_A + i);
    }
    printf("\n");
    
    for (int i = 0; i < NUM_DESTINATIONS; i++) {
        // SIDE LABEL
        printf("%c ", ASCII_A + i);
        
        for (int j = 0; j < NUM_DESTINATIONS; j++) {
            if (road_networks[i][j] && (j == 2 || j == 3)) {
                printf("[%d]", road_networks[i][j]);
            } else {
                printf("%2d ", road_networks[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    int location;
    printf("Which point are you located? 0 - A, 1 - B, ... 8 - I: ");
    scanf("%d", &location);
    printf("\nAt point: %c", ASCII_A + location);

    switch (location) {
        case 0: case 1: case 2: case 5:
            printf("\nPoint: C arrived to charging station");
            break;
        case 3: case 4: case 6:
            printf("\nPoint: D arrived to charging station");
            break;
        default:
            printf("\nPoint: No charging station reached");
            break;
    }

    return 0;
}