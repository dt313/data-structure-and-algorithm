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

void reverse_stack(ll_stack **top) {
    ll_stack *top2 = NULL;
    ll_stack *top3 = NULL;


    while(*top != NULL) {
        push(&top2, pop(top));
    }

    while(top2 != NULL) {
        push(&top3, pop(&top2));
    }

    while(top3 != NULL) {
        push(top, pop(&top3));
    }

}

int main() {
    ll_stack *top1 = NULL;

    push(&top1, 1);
    push(&top1, 2);
    push(&top1, 3);
    printf("before reverse \n");
    print_stack(top1);
    reverse_stack(&top1);
    printf("atfer reverse \n");
    print_stack(top1);
}