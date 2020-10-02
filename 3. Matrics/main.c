#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10][10], i,j,k, arr2[10][10],arr3[10][10], sum=0;

    //Reading first matrix
    printf("Read first 3x3 matrix\n");
    for(i = 0; i<3; i++)
    {

        for(j = 0; j<3; j++)
        {
            printf("Element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The first matrix is : \n");
    for(i = 0; i<3; i++)
    {
        printf("\n");
        for(j = 0; j<3; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }

    //Reading second Matrix
    printf("Read second 3x3 matrix\n");
    for(i = 0; i<3; i++)
    {

        for(j = 0; j<3; j++)
        {
            printf("Element - [%d],[%d] : ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("The second matrix is : \n");
    for(i = 0; i<3; i++)
    {
        printf("\n");
        for(j = 0; j<3; j++)
        {
            printf("%d ", arr2[i][j]);
        }
    }
    printf("\n");


    //Multiplication Logic
    for(i = 0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {

            for(k = 0; k<=2; k++)
            {
                sum = sum + arr[i][k] * arr2[k][j];
            }
            arr3[i][j] = sum;
            sum  = 0;
        }
    }

    //Printing the result
    printf("The result is : \n");
    for(i = 0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {

            printf("%d \t", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
