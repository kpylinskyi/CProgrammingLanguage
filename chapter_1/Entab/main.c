#include <stdio.h>

#define TABSTOP 8

int next_tabstop(int column) {
    return TABSTOP - (column % TABSTOP);
}

int main(void) {
    int c, spaces = 0, column = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaces;
        } else {
            while (spaces > 0) {
                int tab_stop = next_tabstop(column);
                if (spaces >= tab_stop) {
                    putchar('\t');
                    column += tab_stop;
                    spaces -= tab_stop;
                } else {
                    putchar(' ');
                    ++column;
                    --spaces;
                }
            }

            if (c == '\n') {
                column = 0;
            } else {
                ++column;
            }
            putchar(c);
        }
    }

    return 0;
}
