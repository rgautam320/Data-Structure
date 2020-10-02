#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Making an Array
    int i, ele, loc, n;
    printf("Enter the length of array\n");
    scanf("%d", &n);
    printf("Enter Array Elements\n");
    int arr[50];
    for(i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Adding an element
    printf("\n Enter element to inset\n");
    scanf("%d", &ele);
    printf("Enter location to insert\n");
    scanf("%d", &loc);
    for(i = n-1; i>=loc; i-- )
    {
        arr[i+1] = arr[i];
    }
    arr[loc] = ele;
    for(i = 0; i<=n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Deleting an element
    int m;
    printf("\nEnter the position of element to delete\n");
    scanf("%d", &m);

    for(i = m; i<n; i++)
    {
        arr[i] = arr[i+1];
    }

    for(i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Traversing in Reverse Order
    printf("\nArray in Reverse Order: \n");
    for(i = n-1; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
