#include<stdio.h>

void move(int n , char from, char to) {
    printf("Move disk %d from stake %c to stake %c \n",n,from,to);
}

void hanoi_tower(int n, char from , char by , char to) {
    if (n == 1)
        move(1, from, to);
    else
    {
        // move 2 disk from  A -> B (intermediate C) 
        hanoi_tower(n - 1, from, to , by);
        // move final disk from A -> C
        move(n, from, to);
        // move 2 disk from B -> C (intermediate A)
        hanoi_tower(n - 1, by, from, to);
    }
}

int main() {

    char a = 'A', b = 'B', c = 'C';

    hanoi_tower(3, a, b, c);
    return 0;
}