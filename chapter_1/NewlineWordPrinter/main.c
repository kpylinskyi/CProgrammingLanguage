#include <stdio.h>

#define INSIDE 1   // State: inside a word
#define OUTSIDE 0  // State: outside a word

int main() {
    int character;
    int word_state = OUTSIDE;  // Keeps track if we're inside a word or not
    int new_line_printed = OUTSIDE;  // Tracks whether a newline has been printed for current word block

    // Process input character by character
    while ((character = getchar()) != EOF) {
        // Check if the character is a space, tab, or newline
        if (character == ' ' || character == '\t' || character == '\n') {
            word_state = OUTSIDE;  // We're not inside a word anymore

            // Print a newline if one hasn't already been printed
            if (!new_line_printed) {
                putchar('\n');
                new_line_printed = INSIDE;
            }
        } else if (word_state == OUTSIDE) {
            // We encountered a new word, so print the character
            putchar(character);
            word_state = INSIDE;    // Now we're inside a word
            new_line_printed = OUTSIDE;  // Reset line tracking since we're in a word
        }
    }

    return 0;
}
