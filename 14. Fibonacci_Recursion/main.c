//Fibonacci Series using Recursion
#include <stdio.h>
#include <stdlib.h>
//Defining Fibonacci function
int fibonacci(int term)
{
    if(term<2)
        {
            return term;
        }
    return fibonacci(term-1) + fibonacci(term-2);
}
int main()
{
    int i,n;
    printf("Enter number of terms in Fibonacci Series\n");
    scanf("%d", &n);
    printf("Fibonacci Series till %d terms : \n", n);
    for(i = 0; i<n; i++)
    {
        printf("%d\t", fibonacci(i));
    }
    return 0;
}

