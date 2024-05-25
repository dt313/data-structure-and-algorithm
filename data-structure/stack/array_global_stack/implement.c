#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == (MAX_STACK_SIZE - 1);
}

void push(element item) {
    if(is_full() == 1) {
        printf("stack is full\n");
    }
    else {
        stack[++top] = item;
    }

}

element pop() {
    if(is_empty() == 1) {
        printf("stack is empty\n");
        exit(0);
    }
    else {
        return stack[top--];
    }
}

void print_stack() {
    printf("STACK :: ");
    for(int i = 0; i <= top; i++) {
        printf("[%d] ", stack[i]);
    }

    printf("\n\n");
}

int main() {
    printf("after push 10, 5, 20\n");
    push(10);
    push(5);
    push(20);
    print_stack();

    printf("after pop \n");
    element item = pop();
    printf("Item is %d\n", item);
    print_stack();

    printf("after pop \n");
    item = pop();
    printf("Item is %d\n", item);
    print_stack();

    printf("after pop \n");
    item = pop();
    printf("Item is %d\n", item);
    print_stack();


    printf("after pop \n");
    item = pop();

}