#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK 100

typedef int element;
typedef struct stack
{
    char name[10];
    element data[MAX_STACK];
    int top;   
} stack;

int is_empty(stack *s) {
    return s->top == -1;
}

int is_full(stack *s) {
    return s->top == (MAX_STACK - 1);
}

void push(stack *s, element value) {
    if(is_full(s) == 1) {
        printf("stack is full\n");
    }else {
        s->data[++s->top] = value;
    }
}

element pop(stack *s) {
    if(is_empty(s) == 1) {
        printf("stack is empty");
        exit(0);
    }

    return s->data[s->top--];
}

void print_stack(stack s) {
    printf("%s :: ", s.name);
    for (int i = 0; i <= s.top; i++)
    {
        printf("[ %d ] " , s.data[i]);
    }
    printf("\n\n");
}

stack create_stack(char *name) {
    stack new_s;
    strcpy(new_s.name, name);
    new_s.top = -1;
    return new_s;
}

int main() {
    stack s1 = create_stack("S1");
    stack s2 = create_stack("S2");
    printf("after push 1,2,3 to stack S1\n");
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    print_stack(s1);

    printf("after push 3,2,1 to stack S2\n");
    push(&s2,3);
    push(&s2,2);
    push(&s2,1);
    print_stack(s2);

    printf("after pop 2 times from stack S2\n");
    printf("POP %d\n", pop(&s2));
    printf("POP %d\n", pop(&s2));
    print_stack(s2);

    printf("after pop 2 times from stack S1\n");
    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));
    print_stack(s1);

    printf("after pop 1 times from stack S2\n");
    printf("POP %d\n", pop(&s2));
    print_stack(s2);

    printf("after pop 2 times from stack S1\n");
    printf("POP %d\n", pop(&s1));
    printf("POP %d\n", pop(&s1));
    print_stack(s1);
}
