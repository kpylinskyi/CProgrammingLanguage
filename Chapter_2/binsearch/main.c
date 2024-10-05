#include <stdio.h>

int binsearch(int x, int v[], int n){
    int high, low, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if (x < v[mid]) low = mid;
        else low = mid + 1;
    }

    return x == v[low] ? low : -1; 
}

int main(){
    int v[] = {0, 1, 2, 3, 4, 5};
    printf("%d", binsearch(2, v, 6));

    return 0;
}