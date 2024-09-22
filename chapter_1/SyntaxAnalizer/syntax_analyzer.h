#ifndef SYNTAX_ANALYZER_H
#define SYNTAX_ANALYZER_H

#include <stdbool.h>

extern int parentheses, brackets, braces;
bool single_quotes, double_quotes;

bool check_rudimentary(char* program);
void report_error(int line, char* error_type);

#endif