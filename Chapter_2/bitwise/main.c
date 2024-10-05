#include <stdio.h>
#include "main.h"

int getbits(unsigned char num){
    return sizeof(num) * 8; 
}

char* printbinary(unsigned char num) {
    int i, bits;
    static char binary[9]; 
    bits = getbits(num);

    for (i = 0; i < bits; i++) {
        binary[bits - i - 1] = '0' + getbit(num, i);
    }
    
    binary[bits] = '\0';
    
    return binary;
}

int lsb(unsigned char num){
    return num & 1; 
}

int msb(unsigned char num){
    int bits = getbits(num);
    return (num >> (bits - 1)) & 1;
}

char getbit(unsigned char num, int n){
    return (num >> n) & 1;
}

int setbit(unsigned char num, int n){
    return (1 << n) | num;
}

int clearbit(unsigned char num, int n){
    return num & ~(1 << n);
}

int togglebit(unsigned char num, int n){
    return num ^ (1 << num);
}

int hosb(unsigned char num){
    int i, bits, highest;
    bits = getbits(num);
    highest = 0;
    for (i = 0; i < bits; ++i){
        if(num & (1 << i)) highest = i;
    }

    return highest;
}

int losb(unsigned char num) {
    int i, bits, lowest;
    bits = getbits(num);
    lowest = -1;  

    for (i = 0; i < bits; ++i) {
        if (num & (1 << i)) {
            lowest = i; 
            break;       
        }
    }

    return lowest; 
}

int tzeros(unsigned char num){
    int i, bits, count;
    bits = getbits(num);
    count = 0;
    for (i = 0; i < bits; ++i){
        if((num & (1 << i)) == 0) ++count;
        else break;
    }
    return count;
}

int lzeros(unsigned char num){
    int i, bits, count;
    bits = getbits(num);
    count = 0;
    for (i = bits - 1; i >= 0; --i){
        if((num & (1 << i)) == 0) ++count;
        else break;
    }
    return count;
}

int flip(unsigned char num){
    return ~num;
}

int main(void){
    int i, bits;
    bits = getbits(0); 
    printf("unsigned char, %d bits\n", bits);
    printf("b10\tb2\t\tflip b10\tflip b2lsb\tmsb\thosb\tlosb\ttzeros\tlzeros\n");
    for (i = 0; i < (1 << bits); ++i){
        printf("%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", 
        i, printbinary(i), flip(i), printbinary(flip(i)), lsb(i), msb(i), hosb(i), losb(i), tzeros(i), lzeros(i));
    }

    printf("%d->%d\n", 6, setbit(6, 0));
    printf("%d->%d\n", 7, clearbit(7, 2));

    return 0;
}
