/* Implementation of a Stack using something like a dynamic array */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct dynamic_array {
    size_t* elems;
    size_t length;
    size_t capacity;
} Stack;


void stack_init(Stack* stack, size_t capacity);


void stack_init(Stack* stack, size_t capacity) {
    stack -> elems = malloc(capacity * sizeof(int));
    if (stack->elems == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    stack->length = 0;
    stack->capacity = capacity;
}


bool stack_empty(Stack* stack) {
    if (stack->elems == NULL && stack->length == 0)
        return true;
    else
        return false;
}


int main(void) {

    Stack* stack;
    stack_init(&stack, 5);

    return 0;
}
