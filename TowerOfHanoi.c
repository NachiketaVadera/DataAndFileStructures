#include <stdio.h>

void move(int, char, char, char);

int main() {
        int number;
        printf("Enter the numberber of disks: \n");
        scanf("%d", &number);
        printf("Resultant sequence for %d disks is:\n", number);
        move(number, 'A', 'C', 'B');
        return 0;
}
void move(int number, char from, char to, char via) {
        if (number == 1) {
                printf("Move disk 1 from peg %c to peg %c\n", from, to);
                return;
        }
        move(number - 1, from, via, to);
        printf("Move disk %d from peg %c to peg %c\n", number, from, to);
        move(number - 1, via, to, from);
}
