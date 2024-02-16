#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int x;
    struct node* next;
} node_t;


// A Stack points to a top node and holds a length
typedef struct stack {
    node_t* top;
    size_t length;
} Stack;


void init_stack(Stack* stack);
bool stack_empty(Stack* stack);
void push(Stack* stack, int val);
int pop(Stack* stack);
void print_stack(Stack* stack);


// Initialized the stack
void init_stack(Stack* stack) {
    stack -> top = NULL;
    stack -> length = 0;
}


// Checks if Stack is empty
bool stack_empty(Stack* stack) {
    if (stack->top == NULL) {
        return true;
    } else {
        return false;
    }
}


// Pushes an element into the stack, creating a new node, placing it accordingly and pointing to it
void push(Stack* stack, int val) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Error. Memory allocation failed.\n");
        free(node);
        return;
    }
    node->next = NULL;
    node->x = val;

    if (stack->top == NULL) {
        stack->top = node;
        stack->length++;
    }
    else {
        node->next = stack->top;
        stack->top = node;
        stack->length++;
    }
}


// Pops the top, removes it and frees it
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Underflow.\n");
        return -1;
    }
    int value = stack->top->x;
    node_t* node_to_del = stack->top;
    stack->top = node_to_del->next;
    stack->length--;
    free(node_to_del);
    return value;
}


// Pretty prints the stack
void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("[ ]\n");
        return;
    }

    node_t* ptr = stack->top;
    printf("[");
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            printf("%d", ptr->x);
            break;
        }
        else {
            printf("%d, ", ptr->x);
            ptr = ptr->next;
        }
    }
    printf("]\n");
}


// Frees the stack node by node
void free_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        return;
    }
    else {
        node_t* ptr = stack->top;
        while (ptr != NULL) {
            node_t* to_del = ptr;
            ptr = ptr->next;
            free(to_del);
            to_del->x = 0;
            to_del->next = NULL;
        }
        stack->top = NULL;
    }
}


int main(void) {

    Stack stack;
    init_stack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    print_stack(&stack);
    printf("Poppin...\n");
    pop(&stack);
    pop(&stack);
    pop(&stack);
    print_stack(&stack);
    printf("Pushin...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    print_stack(&stack);


    free_stack(&stack);
    return 0;
}
