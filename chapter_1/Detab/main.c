#include <stdio.h>

#define TABSTOP 8

int spaces_to_next_tabstop(int current_col){
    return TABSTOP - (current_col % TABSTOP);
}

int main(void){
    int c, col;
    col = 0;

    while ((c = getchar()) != EOF){
        if(c == '\t'){
            int spaces = spaces_to_next_tabstop(col);

            for(int i = 0; i < spaces; ++i){
                putchar('_');
                ++col;
            }
        } else {
            putchar(c);
            ++col;

            if (c == '\n') col = 0;
        }
    }

    return 0;
}