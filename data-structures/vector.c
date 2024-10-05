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
        int temp = v->data[index1];
        v->data[index1] = v->data[index2];
        v->data[index2] = temp;
    }
}

void vector_print(Vector *v){
    int i;
    printf("[");
    for (i = 0; i < v->size; ++i){
        printf(" %d", v->data[i]);
    }
    printf(" ]\n");
}

void vector_bubble_sort(Vector* v){
    int i;
    bool swapped;
    do {
        swapped = false;
        for (i = 1; i < v->size; ++i){
            if (v->data[i - 1] > v->data[i]){
                vector_swap(v, i - 1, i);
                swapped = true;
            }
        }
    } while (swapped);
}