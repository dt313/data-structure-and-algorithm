#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;



int is_empty(ListNode *head) {
    return head == NULL;
}

int size(ListNode *head) {
    ListNode *temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->link;
        count++;
    }
    return count;   
}

void print_list_node(ListNode **head) {
    printf("=== List Node ===\n");

    if(is_empty(*head) == 1) {
        printf("empty list \n\n");
    }
    int i = 0;
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp = *head;
    while(temp != NULL) {
        printf("(%d : %d) -> ", ++i, temp->data);
        temp=temp->link;
    }

    printf("\n\n");
}


void insert_first(element value, ListNode **head) {
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->data = value;
    temp->link = *head;
    *head = temp;
}


void insert_last(element value, ListNode **head) {
    ListNode *pre = *head;
    while(pre->link != NULL) {
        pre = pre->link;
    }
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->data = value;
    temp->link = NULL;

    pre->link = temp;

}


void insert(ListNode **head, int value, ListNode **pre) {
     ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
     temp->data = value;
     temp->link = (*pre)->link;
     (*pre)->link =temp;
}


void delete_first(ListNode **head) {
    if(is_empty(*head) == 1) {
        printf("empty list\n");
        return ;
    }
    else {
        ListNode *temp = *head;
        *head = temp->link;
        free(temp);
    }
}

void delete(ListNode **head, ListNode **pre) {

    if(is_empty(*head) == 1) {
        printf("empty list\n");
        return ;
    }

    ListNode *temp = (*pre)->link;
    (*pre)->link = temp->link;
    free(temp);
    
}

void delete_last(ListNode **head) {
    if(is_empty(*head) == 1) {
        printf("empty list\n");
        return;
    }

    ListNode *temp = *head;
    ListNode *pre = (ListNode *) malloc(sizeof(ListNode));

    while(temp->link != NULL) {
        if(temp->link->link == NULL) {
            pre = temp;
        }
        temp = temp->link;
       
    }
        
    pre->link = NULL;
    free(temp);
    
    
}

ListNode *get_node_by_data(ListNode *head, element data) {
     if(is_empty(head) == 1) {
        printf("empty list\n");
        return NULL;
    }

    ListNode *temp = head;

    while(temp != NULL) {
        if(temp->data == data) break;
        temp = temp->link;
    }

    return temp;
}


ListNode *get_node_by_index(ListNode *head, int index) {
    if(is_empty(head) == 1) {
        printf("empty list\n");
        return NULL;
    }

    if(index == 0) {
        printf("index starts from 1 ");
        return NULL;
    }

    ListNode *temp = head;
    for(int i = 0; i < index -1;i++) {
        if(temp == NULL) return NULL;
        temp=temp->link;
    }

    return temp;
}

void reset(ListNode **head) {
    *head = NULL;
}



int main() {
    ListNode *head = NULL;
    ListNode *node = NULL;

    printf("after insert first(10,5,0)\n");

    insert_first(10,&head);
    insert_first(5,&head);
    insert_first(0,&head);
    print_list_node(&head);

    ListNode *a = get_node_by_index(head, 1);
    printf("after insert by pre node (index = 1, data = 1)\n");
    insert(&head,1,&a);
    print_list_node(&head);
    printf("after insert last (20)\n");
    insert_last(20, &head);
    print_list_node(&head);

    printf("after delele first\n");
    delete_first(&head);
    print_list_node(&head);

    printf("after delele by pre node (data = 5)\n");
    a = get_node_by_data(head, 5);
    delete(&head, &a);
    print_list_node(&head);

    printf("after delele last \n");
    delete_last(&head);
    print_list_node(&head);

    printf("get node by value (5)\n");
    a = get_node_by_data(head, 5);
    printf("Node is %d\n\n", a->data);

    printf("get node by index (1)\n");
    a = get_node_by_index(head, 1);
    printf("Node is %d\n\n", a->data);

    printf("Size of listnode : %d\n\n", size(head));

    printf("after reset list\n");
    reset(&head);
    print_list_node(&head);

    printf("Size of listnode : %d\n\n", size(head));



    return 0;
}