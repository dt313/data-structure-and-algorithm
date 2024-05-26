#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct stack_type {
    element *data; // store item
    int capacity; // store size of data array
    int top;
} stack_type;


int is_empty(stack_type *stack) {
    return stack->top == -1;
}

int is_full(stack_type *stack) {
    return stack->top == (stack->capacity - 1);
}

void push(stack_type *stack, element item) {
    if(is_full(stack) == 1) {
        printf("stack is full\n");
        printf("REALLOC ..... \n");

        stack->capacity *= 2;
        stack->data = (element *)realloc(stack->data,stack->capacity * sizeof(element));
        printf("after realloc :: CAPACITY OF DATA : %d\n", stack->capacity);
    }

    stack->data[++stack->top] = item;
}

element pop(stack_type *stack) {
    if(is_empty(stack) == 1) {
        printf("stack is empty\n");
        exit(0);
    }else {
        return stack->data[stack->top--];
    }
}

element peek(stack_type *stack, int index) {
    if(is_empty(stack) == 1) {
        printf("stack is empty\n");
        exit(0);
    }else {
        return stack->data[index];
    }

}

void print_stack(stack_type *stack) {
    printf("STACK :: ");
    for(int i = 0; i <= stack->top; i++) {
        printf("[%d] ", stack->data[i]);
    } 
    printf("\n\n");
}

stack_type init(int size) {
    stack_type tmp;
    tmp.capacity = size;
    tmp.data = (element *) malloc(sizeof(element) * size);
    tmp.top = -1;
    return tmp;
}

int main() {
    stack_type s1 = init(2);
    printf("INIT STACK WITH CAPACITY  = %d\n",s1.capacity);
    printf("after push 1 ,2 to stack\n");
    push(&s1, 1);
    push(&s1, 2);
    print_stack(&s1);

    printf("after push 3 to stack\n");
    push(&s1, 3);
    print_stack(&s1);

    printf("after push 4 ,5 to stack\n");
    push(&s1, 4);
    push(&s1, 5);
    print_stack(&s1);

    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));
    print_stack(&s1);
    printf("PEEK %d\n", peek(&s1,0));
    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));


}