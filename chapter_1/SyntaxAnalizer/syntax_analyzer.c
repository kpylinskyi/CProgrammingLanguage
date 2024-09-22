#include "syntax_analyzer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type; // '(', '[', '{', '\'', '"'
    int line;  // Line number of the opening character
} StackElement;

StackElement* stack = NULL;
int stack_size = 0;
int stack_capacity = 0;

void push(char type, int line) {
    if (stack_size >= stack_capacity) {
        stack_capacity = stack_capacity ? stack_capacity * 2 : 4;
        stack = realloc(stack, stack_capacity * sizeof(StackElement));
    }
    stack[stack_size++] = (StackElement){type, line};
}

StackElement pop() {
    return stack[--stack_size];
}

bool is_empty() {
    return stack_size == 0;
}

bool check_rudimentary(char* program) {
    int line = 1;

    for (int i = 0; program[i] != '\0'; ++i) {
        char c = program[i];

        if (c == '\n') ++line;

        // Handle string literals
        if (c == '"' && program[i - 1] != '\\') {
            double_quotes = !double_quotes;
            continue;
        }

        if (c == '\'' && program[i - 1] != '\\') {
            single_quotes = !single_quotes;
            continue;
        }

        // Skip if inside quotes
        if (single_quotes || double_quotes) {
            continue;
        }

        // Handle opening and closing braces, parentheses, and brackets
        switch (c) {
            case '(':
                push('(', line);
                break;
            case ')':
                if (is_empty() || pop().type != '(') {
                    report_error(line, "Extra closing parenthesis");
                }
                break;
            case '[':
                push('[', line);
                break;
            case ']':
                if (is_empty() || pop().type != '[') {
                    report_error(line, "Extra closing bracket");
                }
                break;
            case '{':
                push('{', line);
                break;
            case '}':
                if (is_empty() || pop().type != '{') {
                    report_error(line, "Extra closing brace");
                }
                break;
            default:
                break;
        }
    }

    // After parsing, check for any unmatched opening characters
    while (!is_empty()) {
        StackElement unmatched = pop();
        switch (unmatched.type) {
            case '(': report_error(unmatched.line, "Missing closing parenthesis"); break;
            case '[': report_error(unmatched.line, "Missing closing bracket"); break;
            case '{': report_error(unmatched.line, "Missing closing brace"); break;
            case '\'': report_error(unmatched.line, "Missing closing single quote"); break;
            case '"': report_error(unmatched.line, "Missing closing double quote"); break;
        }
    }

    // Return true if everything is balanced
    return is_empty() && !single_quotes && !double_quotes;
}

void report_error(int line, char* error_type) {
    printf("Syntax error at line %d: %s\n", line, error_type);
}
