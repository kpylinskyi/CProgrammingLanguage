#include "file_writer.h"
#include <stdio.h>

void write_output(char *program) {
    FILE *outfile = fopen("out.c", "w");
    if (outfile == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; program[i] != '\0'; ++i) {
        fputc(program[i], outfile);
    }

    fclose(outfile);
}
