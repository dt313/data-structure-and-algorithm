#include<stdio.h>
#include<stdlib.h>

typedef int element;
// circle linked list
typedef struct ListNode {
    element data;
    struct ListNode *link; 
} ListNode;

int is_empty(ListNode *head) {
    return head == NULL;
}

int size(ListNode *head) {
    if(head == NULL) return 0;

    ListNode *temp = head->link;
    if(temp == head) return 1;

    int count = 1;
    while(temp != head) {
        count++;
        temp = temp->link;
    }
    return count;   
}

void print_list_node(ListNode *head) {
    printf("=== List Node ===\n");

    if(is_empty(head) == 1) {
        printf("empty list \n\n");
        return;
    }

    ListNode *temp = head->link;
    int i = 0;
    while(temp != head) {
    
        printf("(%d : %d) -> ", ++i, temp->data);
        temp=temp->link;
    }
    printf("(%d : %d)", ++i, temp->data);

    printf("\n\n");
}



ListNode *insert_first(ListNode *head, element val) {
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->data = val;
    if(head == NULL){
        head = temp;
        temp->link = head;
    }
    else {
        temp->link = head->link;
        head->link = temp;
    }
    return head;
}

ListNode *insert_last(ListNode *head, element val) {
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->data = val;

    if(head == NULL){
        head = temp;
        temp->link = head;
        
    }
    else {
        temp->link = head->link;
        head->link = temp;
        head = temp;
    }
    return head;
}

ListNode *delete_first(ListNode *head) {
    if(is_empty(head) == 1) {
        printf("can not delete - empty list");
        return head; 
    }

    ListNode *temp = head->link;
    head->link = temp->link;
    free(temp);
    return head;
}

ListNode *delete_last(ListNode *head) {
    if(is_empty(head) == 1) {
        printf("can not delete - empty list");
        return head; 
    }

    ListNode *temp = head->link;
    if(temp == head) {
        free(head);
        head = NULL;
        return head;
    }

    // find pre last node
    while(temp->link != head) {
        temp = temp->link;
    }

    temp->link = head->link;
    free(head);
    head = temp;
    return head;
}

ListNode *get_node_by_index(ListNode *head, int index) {
    if(index == 0) {
        printf("index starts from 1\n");
        return NULL;
    }
    if(is_empty(head) == 1) {
        printf("can not get node - empty list\n");
        return NULL;
    }
    if(index > size(head)) {
        printf("can not get node - out of lenght\n");
        return NULL;
    }

    ListNode *temp = head->link;
    for(int i = 0; i < index - 1; i++) {
        temp = temp->link;
    }

    return temp;
}



int main() {
    ListNode *head = NULL;
    printf("size of list : %d\n\n", size(head));
    printf("after insert first : 10 , 5\n");
    head = insert_first(head,10);
    head = insert_first(head,5);
    print_list_node(head);

    printf("after insert last : 20 \n");
    head = insert_last(head,20);
    print_list_node(head);

    printf("after delete first \n");
    head = delete_first(head);
    print_list_node(head);


    printf("after delete last \n");
    head = delete_last(head);
    print_list_node(head);

    printf("size of list : %d\n\n", size(head));

    printf("after insert first : 50 , 70\n");
    head = insert_first(head,50);
    head = insert_first(head,70);
    print_list_node(head);

    printf("get node by index 1\n");
    ListNode *node = get_node_by_index(head,1);
    printf("Node : %d\n", node->data);

    return 0;
}