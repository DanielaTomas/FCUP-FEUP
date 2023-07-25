#ifndef __stack_h__
#define __stack_h__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _stacknode {
    int value;
    struct _stacknode* next;
} stacknode;

typedef struct {
    int size;
    stacknode* top;
} stack;

stack* stack_create(void);

void stack_destroy(stack* s);

int stack_size(const stack* s);

bool stack_is_empty(const stack* s);

void stack_push(stack* s, int v);

bool stack_pop(stack* s, int* v);

bool stack_peek(const stack* s, int* v);

void stack_to_array(const stack* s, int array[]);

#ifdef __cplusplus
}
#endif

#endif
