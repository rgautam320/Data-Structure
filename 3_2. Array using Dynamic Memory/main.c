/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Different Operations on Matrix (Two Dimensions Array using Dynamic Memory)
#include <stdio.h>
#include <stdlib.h>
/*At first, we are declaring the functions which performs addition,
subtraction and multiplication. As these functions are not returning
anything and taking anything, they have been declared as void.*/
void addition(void);
void subtraction(void);
void multiplication(void);
/*We need three arrays to perform our actions so that we have declared
three arrays in which array A and array B take input from the users and
after calculation, the result will be stored in array C*/
int **A, **B, **C, i, j, k, m, n, sum = 0;
int main()
{
    //We are defining the size of arrays here
    printf("Enter Number of Rows : ");
    scanf("%d", &m);
    //Allocating memory dynamically using malloc function
    A = (int **)malloc(m * sizeof(int));
    B = (int **)malloc(m * sizeof(int));
    C = (int **)malloc(m * sizeof(int));

    printf("Enter Number of Columns : ");
    scanf("%d", &n);

    for(i = 0; i < m; i++)
    {
        A[i] = (int *)malloc(n * sizeof(int *));
        B[i] = (int *)malloc(n * sizeof(int *));
        C[i] = (int *)malloc(n * sizeof(int *));
    }
    /*Taking the values for first array.
    We use nested for loop and scan the values for array.*/
    printf("Enter Array Element for First Matrix : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter data in [%d][%d] : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    /*We are printing the first array here using two nested for loop.*/
    printf("The first array is : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    /*Taking the values for second array.
    We use nested for loop and scan the values for array.*/
    printf("Enter Array Element for Second Matrix : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter data in [%d][%d] : ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    /*We are printing the second array here using two nested for loop.*/
    printf("The second array is : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    /*To show the options infinite times, we have used while(1)*/
    while(1)
    {
        //To choose actions, choice variable has declared.
        int choice;
        printf("<-- Options -->\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        //Using switch, we will perform our desire action
        switch(choice)
        {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            //Multiplication is done only when m is equal to n.
            if(m == n)
            {
               multiplication();
            }
            else
            {
                printf("Multiplication Error\n");
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
        }
    }
    return 0;
}
/*We add two arrays and store the result into matrix C.
The function addition is used to perform this action.
Then we print the resultant matrix using two nested for loop.*/
void addition()
{
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    //Printing the resultant array C using nested two for loop.
    printf("The Addition of Two Arrays : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}
/*We subtract array B from array A and store the result into matrix C.
The function subtraction is used to perform this action.
Then we print the resultant matrix using two nested for loop.*/
void subtraction()
{
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    //Printing the resultant array C using nested two for loop.
    printf("The Subtraction of Two Arrays : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}
/*We perform multiplication of two arrays and store the result in matrix C.
The function multiplication is used to perform this action.
Then we print the resultant matrix using two nested for loop.*/
void multiplication()
{
    for(i = 0; i < m; i++)
    {
        for(j=0; j < m; j++)
        {
            for(k = 0; k < m; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            sum  = 0;
        }
    }
    //Printing the resultant array C using nested two for loop.
    printf("The Multiplication of Two Arrays : \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}
