#include<stdio.h>
int greatest_common_divisor(int a, int b) {
    if(b == 0) return a;
    else return greatest_common_divisor(b, a%b);
}

int main() {
    int number1;
    int number2;
    printf("Enter two number you want find greatest common divisor\n");
    printf("Number 1 : ");
    scanf("%d", &number1);
    printf("Number 2 : ");
    scanf("%d", &number2);
    printf("Greatest common divisor number is : %d\n", greatest_common_divisor(number1, number2));
}