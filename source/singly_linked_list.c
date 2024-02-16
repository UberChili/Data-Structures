#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int x;
    struct node* next;
} node_t;


typedef struct list {
    node_t* head;
    int length;
} List;


/* List functions */
void list_init(List* l) {
    l -> head = NULL;
    l -> length = 0;
}

int get(List *l, int index) {
    if (index >= l->length) {
        printf("List index out of range\n");
        return -1;
    }

    int i = 0;
    node_t* aux = l->head;
    if (aux == NULL) {
        printf("List is empty\n");
        return -1;
    }
    while (aux != NULL) {
        if (i == index) {
            return aux->x;
        }
        else {
            i++;
            aux = aux->next;
        }
    }
    return -1;
}

int remove_element(List *l, int index) {
    if (index >= l->length) {
        printf("List index out of range\n");
        return 0;
    }

    int i = 0;
    node_t* aux = l->head;
    if (aux == NULL) {
        printf("List is empty\n");
        return 0;
    }
    while (aux != NULL) {
        if (i + 1 == index && aux->next != NULL) {
            node_t* to_delete = aux->next;
            aux->next = aux->next->next;
            free(to_delete);
            l->length--;
            return 1;
        }
        else {
            i++;
            aux = aux->next;
        }
    }
    return 0;
}

void push_front(List *l, int val) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp -> x = val;
    temp -> next = NULL;

    /* printf("x = %d\n", temp -> x); */

    if (l -> head == NULL) {
        l -> head = temp;
        l -> length = 1;
    }
    else {
        temp -> next = l -> head;
        l -> head = temp;
        l -> length++;
    }
}

void push_back(List *l, int val) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp -> x = val;
    temp -> next = NULL;

    if (l -> head == NULL) {
        l -> head = temp;
        l -> length = 1;
    }
    else {
        node_t* aux = l -> head;

        while (aux != NULL) {
            if (aux -> next == NULL) {
                aux -> next = temp;
                l -> length++;
                break;
            }
            else {
                aux = aux -> next;
            }
        }
    }
}

void print_list(List* l) {
    node_t* aux = l -> head;

    if (aux == NULL) {
        printf("[]\n");
    }
    else {
        printf("[");
        while (aux != NULL) {
            if (aux->next == NULL) {
                printf("%d", aux->x);
                break;
            }
            else {
                printf("%d, ", aux->x);
                aux = aux -> next;
            }
        }
        printf("]\n");
    }
}

int main(void) {
    printf("Hello\n");

    List my_list;
    list_init(&my_list);
    push_front(&my_list, 1);
    push_front(&my_list, 2);
    push_front(&my_list, 3);
    push_back(&my_list, 0);
    push_back(&my_list, 1);
    push_back(&my_list, 2);
    push_back(&my_list, 3);
    print_list(&my_list);
    printf("Element at index %d = [%d]\n", 0, get(&my_list, 0));
    printf("Element at index %d = [%d]\n", 1, get(&my_list, 1));
    printf("Element at index %d = [%d]\n", 3, get(&my_list, 3));
    printf("Element at index %d = [%d]\n", 6, get(&my_list, 6));
    printf("Attemptint to remove element at index %d\n", 3);
    remove_element(&my_list, 3);
    print_list(&my_list);
    printf("Attemptint to remove element at index %d\n", 1);
    remove_element(&my_list, 1);
    print_list(&my_list);

    return 0;
}
