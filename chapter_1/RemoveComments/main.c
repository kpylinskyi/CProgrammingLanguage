#include "program_processor.h"
#include "file_writer.h"

int main(void) {
    char program[PROGLEN];
    prev_char = 0;

    // Process all characters from input
    process_characters(program);

    // Write the processed output to the file
    write_output(program);

    return 0;
}
