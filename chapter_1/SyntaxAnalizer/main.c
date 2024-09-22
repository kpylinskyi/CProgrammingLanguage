#include <stdio.h>
#include "program_processor.h"
#include "syntax_analyzer.h"

int main(void) {
    char program[PROGLEN];
    prev_char = 0;

    // Process all characters from input
    process_characters(program);

    // Check for rudimentary syntax errors 
    bool has_rudimentary = check_rudimentary(program);

    printf("%d", has_rudimentary);

    return 0;
}
