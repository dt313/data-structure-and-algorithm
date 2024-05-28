#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct ll_stack
{
    element data;
    struct ll_stack *link;
} ll_stack;

int is_empty(ll_stack **top)
{
    return *top == NULL;
}

void push(ll_stack **top, element item)
{
    ll_stack *temp = (ll_stack *)malloc(sizeof(ll_stack));
    temp->data = item;
    if (is_empty(top))
    {
        temp->link = NULL;
    }
    else
    {
        temp->link = *top;
    }
    *top = temp;
}

element pop(ll_stack **top)
{
    if (is_empty(top) == 1)
    {
        printf("pop :: stack is empty\n");
        exit(0);
    }
    else
    {
        int result = (*top)->data;
        ll_stack *temp = *top;
        *top = (*top)->link;
        free(temp);
        return result;
    }
}

element peek(ll_stack *top, int index)
{
    if (is_empty(&top) == 1)
    {
        printf("peek :: stack is empty\n");
        exit(0);
    }

    if (index == 0)
    {
        return top->data;
    }
    else
    {
        int i = 0;
        ll_stack *temp = top;
        while (i < index)
        {
            temp = temp->link;
            i++;
        }

        if (temp == NULL)
        {
            printf("peek :: out of length\n");
            exit(0);
        }
        return temp->data;
    }
}

void print_stack(ll_stack *top)
{
    ll_stack *temp = top;
    printf("STACK :: ");
    while (temp != NULL)
    {
        printf("[%d] ", temp->data);
        temp = temp->link;
    }
    printf("\n\n");
}

int is_match(char open, char close)
{
    if (open == '(' && close == ')' ||
        open == '{' && close == '}' ||
        open == '[' && close == ']')
        return 1;
    else
        return 0;
}

int check_balanced(char exp[])
{
    int i = 0;
    ll_stack *top = NULL;
    while (exp[i])
    {
        switch (exp[i])
        {
        case '(':
        case '{':
        case '[':
            push(&top, exp[i]);
            break;

        case ')':
        case '}':
        case ']':
            if (is_empty(&top))
            {
                printf("dấu ngoặc đóng nhiều hơn dấu ngoặc mở\n\n");
                return 0;
            }
            else
            {
                char c = pop(&top);

                if (is_match(c, exp[i]) == 0)
                {
                    printf("dấu ngoặc không match !\n\n");
                    return 0;
                }
            }
            break;
        default:
            break;
        }
        i++;
    }

    if (is_empty(&top) == 1)
    {
        printf("Result : Balanced\n\n");
        return 1;
    }
    else
    {
        printf("dấu ngoặc mở nhiều hơn dấu ngoặc đóng\n\n");
        return 0;
    }
}

int main()
{
    char expression[100];
    while (1)
    {
        printf("Enter expression : ");
        scanf("%s", expression);

        check_balanced(expression);
    }
}