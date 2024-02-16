#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct dynamic_array {
    size_t* elems;
    size_t length;
    size_t capacity;
} array_t;


void array_init(array_t* a, size_t capacity);
size_t getSize(array_t* a);
size_t getCapacity(array_t* a);
int get(array_t *a, int index);
void set(array_t *a, int index, int val);
void push_back(array_t* a, int val);
int popback(array_t* a);
void print_arr(array_t* a);
void resize(array_t* a);
void free_arr(array_t* a);


void array_init(array_t* a, size_t capacity) {
    a -> elems = malloc(capacity * sizeof(int));
    if (a->elems == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    a -> length = 0;
    a -> capacity = capacity;
}

size_t getSize(array_t* a) {
    return  a->length;
}

size_t getCapacity(array_t* a) {
    return a->capacity;
}

int get(array_t *a, int index) {
    if (index < 0 || index >= a->length) {
        printf("Error: Array index out of range.\n");
        return -1;
    }
    else {
        return a->elems[index];
    }
}

void set(array_t *a, int index, int val) {
    if (index < 0 || index >= a->length) {
        printf("Error: Array index out of range.\n");
        return;
    }
    a->elems[index] = val;
}

void push_back(array_t* a, int val) {
    if (a->length >= a->capacity) {
        resize(a);
    }
    printf("Capacity: %zu, length: %zu\n", a->capacity, a->length);
    a->elems[a->length] = val;
    a->length++;
}

int popback(array_t* a) {
    if (a->elems == NULL) {
        printf("Error: Array is empty.\n");
        return -1;
    }
    int val = a->elems[a->length - 1];
    a->elems[a->length - 1] = 0;
    a->length--;
    return val;
}

void print_arr(array_t* a) {
    if (a == NULL || a->length == 0) {
        printf("[ ]\n");
        return;
    }

    printf("[");
    for (size_t i = 0, n = a->length; i < n; i++) {
        printf("%zu", a->elems[i]);
        if (i < a->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void resize(array_t* a) {
    size_t* elems = malloc(2 * (a->capacity * sizeof(int)));
    if (elems == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    a->capacity = 2 * a->capacity;

    /* memcpy(a->elems, elems, a->capacity); */
    for (size_t i = 0, n = a->length; i < n; i++) {
        elems[i] = a->elems[i];
    }
    free(a->elems);
    a->elems = elems;
}

void free_arr(array_t* a) {
    free(a->elems);
    a->elems = NULL;
    a->capacity = 0;
    a->length = 0;
}


int main(void) {

    array_t array;
    array_init(&array, 5);
    push_back(&array, 5);
    print_arr(&array);
    push_back(&array, 4);
    print_arr(&array);
    push_back(&array, 3);
    print_arr(&array);
    push_back(&array, 2);
    print_arr(&array);
    push_back(&array, 1);
    print_arr(&array);
    push_back(&array, 0);
    print_arr(&array);
    push_back(&array, 100);
    print_arr(&array);
    push_back(&array, 200);
    print_arr(&array);
    set(&array, 6, 10);
    print_arr(&array);
    set(&array, 7, 20);
    print_arr(&array);
    set(&array, 8, 30);
    push_back(&array, 30);
    print_arr(&array);
    popback(&array);
    print_arr(&array);
    /* int item_to_get = 4; */
    /* printf("array[%d] = %d\n", item_to_get, get(&array, item_to_get)); */
    printf("Size: %zu, Capacity:%zu\n", getSize(&array) , getCapacity(&array));

    free_arr(&array);
    return 0;
}
