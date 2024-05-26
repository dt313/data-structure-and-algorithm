#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

// STACK IMPLEMENT
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

void prime_frac(int number) {
    int i = 2;
    while(number != 1) {
        while(number % i == 0) {
            push(i);
            number = number / i;
        }
        i++;
    }

    printf("Primary Fact ::  ");
    while(is_empty() != 1) {
        printf("%d ", pop());
    }
    printf("\n");
}


int main() {
    int number;
    while(1) {
        printf("Enter number : ");
        scanf("%d", &number);
        prime_frac(number);
    }
}