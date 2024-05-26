#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ll_stack {
    element data;
    struct ll_stack *link;
} ll_stack;

int is_empty(ll_stack **top) {
    return *top == NULL;
}

void push(ll_stack **top, element item) {
    ll_stack *temp = (ll_stack *) malloc(sizeof(ll_stack));
    temp->data = item;
    if(is_empty(top)) {
        temp->link = NULL;
    }else {
        temp->link = *top;
    }
    *top = temp;

}

element pop(ll_stack **top) {
    if(is_empty(top) == 1) {
        printf("pop :: stack is empty\n");
        exit(0);
    }
    else {
        int result = (*top)->data;
        ll_stack *temp = *top;
        *top = (*top)->link;
        free(temp);
        return result;
    }
}

element peek(ll_stack *top,int index) {
    if(is_empty(&top) == 1) {
        printf("peek :: stack is empty\n");
        exit(0);
    }

    if(index == 0) {
        return top->data;
    }
    else {
        int i = 0;
        ll_stack *temp = top;
        while(i < index) {
            temp = temp->link;
            i++;
        }

        if(temp == NULL) {
            printf("peek :: out of length\n");
            exit(0);
        }
        return temp->data;
    }
}

void print_stack(ll_stack *top) {
    ll_stack *temp = top;
    printf("STACK :: ");
    while(temp != NULL) {
        printf("[%d] ", temp->data);
        temp = temp->link;
    }
    printf("\n\n");
}

int main() {
    ll_stack *top = NULL;
    printf("after push 20, 10 to stack\n");
    push(&top, 10);
    push(&top, 20);
    print_stack(top);

    printf("after push 5, 15 to stack\n");
    push(&top, 5);
    push(&top, 15);
    print_stack(top);

    printf("PEEK AT 1 : %d\n", peek(top, 1));
    printf("POP %d\n", pop(&top));
    printf("POP %d\n", pop(&top));
    printf("POP %d\n", pop(&top));
    print_stack(top);
    printf("POP %d\n", pop(&top));
    printf("POP %d\n", pop(&top));

}   