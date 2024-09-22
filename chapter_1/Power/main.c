#include <stdio.h>

int power(int base, int n);

int main(){
    int i;
    int n = 2;
    for(i = 0; i < 10; ++i){
        printf("%d in power of %d is %d\n", n, i, power(n, i));
    }

    return 0;
}

int power(int base, int n){
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i) p = p * base;
    return p;
}