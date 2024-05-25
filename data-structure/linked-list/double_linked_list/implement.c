#include <stdio.h>
#include <stdlib.h>

// Double linked list
typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *llink; // previous node
    struct ListNode *rlink; // next node
} ListNode;

int is_empty(ListNode *head)
{
    return head == NULL;
}

int size(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->rlink;
        count++;
    }
    return count;
}

void print_list_node(ListNode *head)
{
    printf("=== List Node ===\n");

    if (is_empty(head) == 1)
    {
        printf("empty list \n\n");
        return;
    }
    int i = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("(%d : %d) -> ", ++i, temp->data);
        temp = temp->rlink;
    }
    printf("\n\n");
}

ListNode *insert_first(ListNode *head, element value)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = value;
    if (head == NULL)
    {
        temp->llink = NULL;
        temp->rlink = NULL;
        head = temp;
        return head;
    }

    temp->llink = NULL;
    temp->rlink = head;
    head->llink = temp;
    head = temp;
    return head;
}

ListNode *insert_last(ListNode *head, element value)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    ListNode *pre = head;

    while (pre->rlink != NULL)
    {
        pre = pre->rlink;
    }

    temp->llink = pre;
    temp->data = value;
    temp->rlink = NULL;
    pre->rlink = temp;
    return head;
}

void insert(ListNode *before, element value)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = value;
    temp->llink = before;

    if (before->rlink == NULL)
    {
        before->rlink = temp;
        temp->rlink = NULL;
    }
    else
    {
        temp->rlink = before->rlink;
        before->rlink->llink = temp;
        before->rlink = temp;
    }
}

ListNode *delete_first(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *temp = head;
    head = temp->rlink;
    head->llink = NULL;

    free(temp);
    return head;
}

ListNode *delete_last(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *pre = head;
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));

    while (pre->rlink->rlink != NULL)
    {
        pre = pre->rlink;
    }

    pre->rlink = NULL;
    temp = pre->rlink;
    free(temp);
    return head;
}

void delete(ListNode *before){
    if (before->rlink == NULL)
    {
        printf("no behind node\n");
    }
    else
    {

        ListNode *removed = before->rlink;
        // final node
        if (removed->rlink == NULL)
        {
            free(removed);
            before->rlink = NULL;
        }
        else
        { // not final node
            before->rlink = removed->rlink;
            removed->rlink->llink = before;
            free(removed);
        }
    }
}

ListNode *get_node_by_index(ListNode *head,int index)
{
    if (index == 0)
    {
        printf("index starts from 1\n");
        return NULL;
    }
    if (is_empty(head) == 1)
    {
        printf("can not get node - empty list\n");
        return NULL;
    }
    if (index > size(head))
    {
        printf("can not get node - out of lenght\n");
        return NULL;
    }

    ListNode *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->rlink;
    }

    return temp;
}

int main()
{

    // init
    ListNode *head = NULL;

    printf("after insert first : 5, 10, 15 \n");
    head = insert_first(head, 5);
    head = insert_first(head, 10);
    head = insert_first(head, 15);
    print_list_node(head);

    printf("after insert last : 20 \n");
    head = insert_last(head, 20);
    print_list_node(head);

    printf("after insert behind 15 : 40 \n");
    insert(head, 40);
    print_list_node(head);

    printf("after insert behind 40  : 50 \n");
    insert(head->rlink, 50);
    print_list_node(head);

    printf("after delete first \n");
    head = delete_first(head);
    print_list_node(head);

    printf("after delete last \n");
    head = delete_last(head);
    print_list_node(head);

    printf("after delete node behind 50 \n");
    delete (head->rlink);
    print_list_node(head);

    printf("get node by index 2 \n");
    ListNode *a = get_node_by_index(head, 2);
    printf("[%d] <-- [%d] --> [%d]\n\n",a->llink->data, a->data, a->rlink->data);
    return 0;
}