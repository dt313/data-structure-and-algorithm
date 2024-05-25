#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct
{
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

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

void print_stack()
{
    printf("==== STACK ==== \n");

    for (int i = 0; i <= top; i++)
    {
        printf("[ %d , %s , %s ] ", stack[i].student_no, stack[i].name, stack[i].address);
    }
    printf("\n\n");

}

element create_student(int std_no, char *name, char *address)
{
    element new_std;
    new_std.student_no = std_no;
    if (sizeof(name) > MAX_STRING || sizeof(address) > MAX_STRING)
    {
        printf("string overflow\n");
    }
    else
    {

        strcpy(new_std.name, name);
        strcpy(new_std.address, address);
        return new_std;
    }
}
int main()
{
    element new_std1 = create_student(1, "Nam", "HCM");
    element new_std2 = create_student(2, "Hung", "HN");
    element new_std3 = create_student(3, "Hoa", "DN");
    element std;
    printf("after push 3 student\n");
    push(new_std1);
    push(new_std2);
    push(new_std3);

    print_stack();

    printf("after pop\n");
    std = pop();
    printf("%d : Name[ %s ], address [ %s ]\n", std.student_no, std.name, std.address);
    print_stack();

    printf("after pop\n");
    std = pop();
    printf("%d : Name[ %s ], address [ %s ]\n", std.student_no, std.name, std.address);
    print_stack();

    printf("after pop\n");
    std = pop();
    printf("%d : Name[ %s ], address [ %s ]\n", std.student_no, std.name, std.address);
    print_stack();

    printf("after pop\n");
    std = pop();
    printf("%d : Name[ %s ], address [ %s ]\n", std.student_no, std.name, std.address);
    print_stack();
}