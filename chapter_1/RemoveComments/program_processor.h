#ifndef PROGRAM_PROCESSOR_H
#define PROGRAM_PROCESSOR_H

#include <stdbool.h>

#define TABSTOP 8
#define PROGLEN 10000

extern int current_char, prev_char, current_col;

void process_characters(char *program);
void handle_comments();
void handle_tab(char *program, int *i);
int next_tabstop(int column);
void skip_comment(bool multiline);

#endif
