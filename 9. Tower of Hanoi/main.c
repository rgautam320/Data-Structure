//Program to solve tower of Hanoi using Recursion
#include <stdio.h>
#include <stdlib.h>
//Making a function
void tower_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_hanoi(n-1, aux_rod, to_rod, from_rod);
}
int main()
{
    int n;
    printf("Enter the number of Disk : ");
    scanf("%d", &n);
    printf("\n******** The solution is ******** \n\n");
    tower_hanoi(n, 'A', 'B', 'C');
    return 0;
}
