#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

void vector_init(Vector *v, int capacity) {
    v->data = (int*) malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_resize(Vector *v, int new_capacity) {
    printf("Vector resize from %d to %d\n", v->capacity, new_capacity);
    v->data = (int*) realloc(v->data, new_capacity * sizeof(int));
    v->capacity = new_capacity;
}

void vector_push_back(Vector *v, int value) {
    printf("Pushing back %d\n", value);
    if (v->size >= v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    v->data[v->size] = value;
    v->size++;
}

int vector_pop_back(Vector *v) {
    if (v->size > 0) {
        int last_element = v->data[v->size - 1];
        printf("Poping back %d\n", last_element);
        v->size--;
        if (v->size > 0 && v->size < v->capacity / 4) {
            vector_resize(v, v->capacity / 2);
        }
        return last_element;
    } else {
        printf("Vector is empty, cannot pop.\n");
        return -1;
    }
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int vector_get(Vector *v, int index){
    if (index >= 0 && index < v->size) {
        return v->data[index];
    } else {
        printf("Index %d is out of bounds. Valid range is 0 to %d.\n", index, v->size - 1);
        return -1;
    }
}

void vector_swap(Vector *v, int index1, int index2){
    if (index1 >= 0 && index1 < v->size && index2 >= 0 && index2 < v->size){
        if (v->data[index1] == v->data[index2]) return;
        
        int temp = v->data[index1];
        v->data[index1] = v->data[index2];
        v->data[index2] = temp;
    }
}

int vector_min(Vector *v, int from, int to){
    int min, mi, i;
    min = v->data[from];

    for(i = from + 1; i < to; ++i){
        if(v->data[i] < min){
            min = v->data[i];
            mi = i;
        }
    }

    return mi;
}

int vector_max(Vector *v, int from, int to){
    int max, mi, i;
    max = v->data[from];

    for(i = from + 1; i > to; ++i){
        if(v->data[i] > max){
            max = v->data[i];
            mi = i;
        }
    }

    return mi;
}

void vector_print(Vector *v){
    int i;
    printf("[");
    for (i = 0; i < v->size; ++i){
        printf(" %d", v->data[i]);
    }
    printf(" ]\n");
}

// Comparison-based Sorting Algorithms:
// BUB
void vector_bubble_sort(Vector* v){
    int n, i;
    for(n = v->size; n > 0; --n){
        for(i = 0; i < n-1; ++i){
            if(v->data[i] > v->data[i+1])
                vector_swap(v, i, i+1);
        }
    }
}

// SEL
void vector_selection_sort(Vector* v){
    int i, mi;
    for(i = 0; i < v->size - 1; ++i){
        mi = vector_min(v, i, v->size);
        vector_swap(v, i, mi);
    }
}

// INS
void vector_insertion_sort(Vector* v) {
    int i, j, x;
    for (i = 1; i < v->size; ++i) {
        x = v->data[i];
        j = i - 1;

        while (j >= 0 && v->data[j] > x) {
            v->data[j + 1] = v->data[j];
            j--;
        }
        v->data[j + 1] = x;
    }
}

// MER
void vector_merge(Vector* v, int low, int mid, int high) {
    int n, k, left, right, subarrIdx;
    n = high - low + 1;   // Total number of elements to merge
    left = low;           // Pointer to the left subarray (low to mid)
    right = mid + 1;      // Pointer to the right subarray (mid+1 to high)
    subarrIdx = 0;        // Index for the temporary merged array

    int subarr[n];        // Temporary array to store the merged result

    // Merge the two subarrays
    while (left <= mid && right <= high) 
        subarr[subarrIdx++] = v->data[left] <= v->data[right] ? v->data[left++] : v->data[right++];

    // Copy any remaining elements from the left subarray
    while (left <= mid) 
        subarr[subarrIdx++] = v->data[left++];

    // Copy any remaining elements from the right subarray
    while (right <= high) 
        subarr[subarrIdx++] = v->data[right++];

    // Copy the merged elements back into the original array
    for (k = 0; k < n; ++k) 
        v->data[low + k] = subarr[k];
}


void vector_merge_sort(Vector* v, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort the first half
        vector_merge_sort(v, low, mid);

        // Recursively sort the second half
        vector_merge_sort(v, mid + 1, high);

        // Merge the two halves
        vector_merge(v, low, mid, high);
    }
}
