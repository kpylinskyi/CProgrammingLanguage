#include "program_processor.h"
#include <stdio.h>
#include <stdbool.h> 

int current_char, prev_char, current_col;

void process_characters(char *program) {
    int i = 0;
    
    while ((current_char = getchar()) != EOF) {
        if (prev_char == '/' && (current_char == '/' || current_char == '*')) {
            handle_comments();
        } else if (current_char == '\t') {
            handle_tab(program, &i);
        } else {
            if (prev_char != 0 && i < PROGLEN - 1) {
                program[i++] = prev_char;
                if (prev_char == '\n') current_col = 0;
                ++current_col;
            }
            prev_char = current_char;
        }
    }

    if (prev_char != 0 && i < PROGLEN - 1) {
        program[i++] = prev_char;
    }

    program[i] = '\0';
}

void handle_comments() {
    if (prev_char == '/' && current_char == '/') {
        skip_comment(false);
        prev_char = 0; 
    } else if (prev_char == '/' && current_char == '*') {
        skip_comment(true);
        prev_char = 0;
    }
}

void handle_tab(char *program, int *i) {
    int spaces = next_tabstop(current_col);
    for (int j = 0; j < spaces; ++j) {
        if (*i < PROGLEN - 1) {
            program[(*i)++] = ' ';
        }
    }
    current_col += spaces;
}

int next_tabstop(int column) {
    return TABSTOP - (column % TABSTOP);
}

void skip_comment(bool multiline) {
    if (multiline) { 
        // Skip until the end of a multi-line comment "*/"
        while ((current_char = getchar()) != EOF) {
            if (prev_char == '*' && current_char == '/') {
                prev_char = 0; 
                break; 
            }
            prev_char = current_char;
        }
    } else {
        // Skip until the end of a single-line comment (newline '\n')
        while ((current_char = getchar()) != EOF && current_char != '\n') {
            // Do nothing, just skip the characters
        }
        current_col = 0;
    }
}
