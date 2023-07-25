#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct _stacknode {
    int value;
    struct _stacknode* next;
};

typedef struct _stacknode stacknode;

typedef struct {
    int size;
    stacknode* top;
} stack;

stack* stack_create(void) {
    return calloc(1, sizeof(stack));
}

void stack_destroy(stack* s) {
    stacknode* n = s -> top;
    while (n != NULL) {
        stacknode* aux = n -> next;
        free(n);
        n = aux;
    }
    free(s);
}

int stack_size(const stack* s) {
    return s -> size;
}

bool stack_is_empty(const stack* s) {
    return stack_size(s) == 0;
}

void stack_push(stack* s, int v) {
    stacknode* new_node = malloc(sizeof(stacknode));
    new_node -> value = v;
    new_node -> next = s -> top;
    s -> top = new_node;
    s -> size++;
}

bool stack_pop(stack* s, int* v) {
    if (s -> size == 0) return false;
    stacknode* old_top = s -> top;
    *v = old_top -> value;
    s -> top = old_top -> next;
    s -> size--;
    free(old_top);
    return true;
}

bool stack_peek(const stack* s, int* v) {
    if(stack_is_empty(s)) return false;
    *v = s -> top -> value;
    return true;
}

void stack_to_array(const stack* s, int array[]) {
    stacknode *node = s->top;
    int pos = 0;
    while(node != NULL) {
        array[pos] = node -> value;
        node = node -> next;
        pos++;
    }
}
