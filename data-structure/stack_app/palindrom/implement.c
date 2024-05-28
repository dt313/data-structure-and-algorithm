#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef char element;
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
        printf("[%c] ", stack[i]);
    }

    printf("\n\n");
}

int check_palindrom(char str[]) {
    int i = 0;

    while(str[i] && str[i] != 'X') {
        push(str[i]);
        i++;
    }
    i++;
    while(str[i]) { // final of string is `\0`
        if(is_empty() || str[i] != pop()) {
            printf("not pilandrom\n");
            return 0;
        }
        i++;
    } 

    printf("pilandrom\n");
    return 1;
}


int main() {
    char *str;
    while(1) {
        printf("Enter string : ");
        scanf("%s", str);
        check_palindrom(str);
    }



}