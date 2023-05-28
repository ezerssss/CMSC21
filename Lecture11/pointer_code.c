#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void scan_word(int occurrences[26]);
bool is_anagram(int occurrences1[26], int occurrences2[26]);

int main(void) {
    // these arrays represent the letters used and how much they're used
    int occurrences1[26] = {0}, occurrences2[26] = {0};

    printf("Enter first word: ");
    scan_word(occurrences1);

    printf("Enter second word: ");
    scan_word(occurrences2);

    // directly put the function call in the if statement since the function returns a bool
    if (is_anagram(occurrences1, occurrences2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}   

void scan_word(int* occurrences) {
    char c;
    while ((c = getchar()) != '\n') {
        // ensures only letters are recorded
        if (isalpha(c)) {
            // use toupper to handle both upper and lowercase letters
            (*(occurrences + (toupper(c) - 'A')))++;
        }
    }
}

// accepts two arrays representing the two words
bool is_anagram(int* occurrences1, int* occurrences2) {
    // loops through all of the possible letters
    for (int i = 0; i < 26; i++) {
        // checks if there's a difference in the occurrences of the letters
        if (*(occurrences1 + i) != *(occurrences2 + i)) {
            // if there is, return false and breaks the loop and kills the function
            return false;
        }
    }

    // this means that it passed the loop meaning all of the occurrences are the same
    return true;
}