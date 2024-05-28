#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
// int type
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return top == -1;
}

int is_full()
{
    return top == (MAX_STACK_SIZE - 1);
}

void push(element item)
{
    if (is_full() == 1)
    {
        printf("stack is full\n");
    }
    else
    {
        stack[++top] = item;
    }
}

element pop()
{
    if (is_empty() == 1)
    {
        printf("stack is empty\n");
        exit(0);
    }
    else
    {
        return stack[top--];
    }
}

element peek()
{
    if (is_empty() == 1)
    {
        printf("stack is empty\n");
        exit(0);
    }
    else
    {
        return stack[top];
    }
}

void print_stack()
{
    printf("STACK :: ");
    for (int i = 0; i <= top; i++)
    {
        printf("[%c] ", stack[i]);
    }

    printf("\n\n");
}

int get_priority(char operator)
{
    switch (operator)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }

    return -1;
}

void init(char *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{
    int i = 0;
    int j = 0;
    char ch, top_operator;
    init(postfix, MAX_STACK_SIZE);
    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (is_empty() != 1 && get_priority(ch) <= get_priority(peek()))
            {
                postfix[j++] = pop();
            }
            push(ch);
            break;
        case '(':
            push(infix[i]);
            break;
        case ')':
            top_operator = pop();
            while (top_operator != '(')
            {
                postfix[j++] = top_operator;
                top_operator = pop();
            }
            break;

        default:
            postfix[j++] = infix[i];
        }
        // print_stack();
    }

    while (is_empty() != 1)
    {
        postfix[j++] = pop();
    }
}

int postfix_calc(char *postfix) {
    int operand1, operand2;
    int ch;
    int len = strlen(postfix);
    int result;
    for (int i = 0; i < len; i++)
    {
        ch = postfix[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            operand1 = pop();
            operand2 = pop();

            switch (ch)
            {
            case '+':
                push(operand2 + operand1);
                break;
            case '-':
                push(operand2 - operand1);
                break;
            case '*':
                push(operand2 * operand1);
                break;
            case '/':
                push(operand2 / operand1);
                break;
            default:
                printf("not operator");
            }
        }
        else
        {
            push((int)(ch - '0'));
        }
    }
    return pop();
}

int main()
{
    char infix[MAX_STACK_SIZE];
    char *postfix = (char *)malloc(sizeof(char) * MAX_STACK_SIZE);

    while (1)
    {
        printf("Enter infix expression : ");
        scanf("%s", infix);
        printf(" INFIX -> %s\n", infix);
        infix_to_postfix(infix, postfix);
        printf(" POSTFIX -> %s\n", postfix);
        int result = postfix_calc(postfix);
        printf(" RESULT -> %d\n", result);
    }
}