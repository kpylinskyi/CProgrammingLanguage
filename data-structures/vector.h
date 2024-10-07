#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int *data;    // Pointer to the elements
    int size;     // Current number of elements
    int capacity; // Maximum number of elements that can be stored without resizing
} Vector;

// Function declarations
void vector_init(Vector *v, int capacity);
void vector_push_back(Vector *v, int value);
int vector_pop_back(Vector *v);
void vector_free(Vector *v);
int vector_get(Vector *v, int index);
void vector_swap(Vector *v, int index1, int index2);
void vector_print(Vector *v);

// BUB - Bubble Sort
void vector_bubble_sort(Vector* v);
// SEL - Selection Sort
void vector_selection_sort(Vector* v);
// INS - Insertion Sort
void vector_insertion_sort(Vector* v);
// MER - Merge Sort (recursive implementation)
void vector_merge_sort(Vector* v, int low, int high);
// QUI - Quick Sort (recursive implementation)
// R-Q - Random Quick Sort (recursive implementation)

// COU - Counting Sort,
// RAD - Radix Sort.

#endif // VECTOR_H
