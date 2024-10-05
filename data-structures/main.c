#include <stdio.h>
#include "vector.h"

int main() {
    Vector v;
    vector_init(&v, 4);  // Initialize vector with capacity 4

    // Add some elements
    vector_push_back(&v, 29);
    vector_push_back(&v, 10);
    vector_push_back(&v, 14);
    vector_push_back(&v, 37);
    vector_push_back(&v, 14);

    vector_print(&v);
    vector_bubble_sort(&v);
    vector_print(&v);
    // Free the vector memory
    vector_free(&v);

    return 0;
}
