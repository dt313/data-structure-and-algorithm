#include<stdio.h>

int fibonacci(int n) {
    if(n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int number;
    printf("Enter the number you want find fibonacci : ");
    scanf("%d", &number);
    printf("Fibonacci number is : %d\n", fibonacci(number));
}