#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node *link;
} node;

node * insert(node *head, float coeff, int exp) {
    node *temp;
    node *new_node = (node *)malloc(sizeof(node));

    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->link = NULL;

    if(head == NULL || exp > head->exp) {
        new_node->link = head;
        head = new_node;
    }
    else {
        temp = head;
        while(temp->link != NULL && temp->link->exp >= exp) {
            temp = temp->link;
        }
        // Calculate if having the same exp
        if(temp->exp == exp) {
            temp->coeff += coeff;
            return head;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }

    return head;

}

node *create(node* head) {
    int n, i;
    float coeff;
    int expo;

    printf("Enter number of term : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d : ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d : ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff,expo);
    }

    return head;
}

void print_poly(node *head) {
    node *temp = head;

    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->link != NULL) {
            printf(" + ");
        }
        temp = temp->link;
    }

    printf("\n\n");
}



node *add(node *head1, node *head2) {
    node *result = NULL;
    node *temp1 = head1;
    node *temp2 = head2;


    while(temp1 != NULL && temp2 != NULL ) {
        if(temp1->exp == temp2->exp) {
            result = insert(result, (temp1->coeff + temp2->coeff), temp1->exp);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if(temp1->exp > temp2->exp) {
            result = insert(result, temp1->coeff, temp1->exp);
            temp1 = temp1->link;
        }else {
            result = insert(result, temp2->coeff, temp2->exp);
            temp2 = temp2->link;
        }
    }

    while(temp1 != NULL) {
        result = insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->link;
    }

     while(temp2 != NULL) {
        result = insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->link;
    }

    return result;
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    printf("==== Make the first polynomial ====\n");
    head1 = create(head1);
    print_poly(head1);

    printf("==== Make the second polynomial ====\n");
    head2 = create(head2);
    print_poly(head2);

    printf("==== Polynomial addtion ====\n");
    head3 = add(head1,head2);
    print_poly(head3);
}


