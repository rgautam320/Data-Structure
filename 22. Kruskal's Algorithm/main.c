/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

// Kruskal's Algorithm Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int i, j, k, m = 1, n, a, b;
int min, mincost = 0, cost[9][9], parent[9];
int find(int i);
int uni(int i, int j);
int main()
{
    printf("Implementation of Kruskal's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Getting the adjacency matrix
    printf("\nEnter the cost adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j<= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i == j)
            {
                cost[i][j] = 0;
            }
            else if(cost[i][j]==0)
            {
                cost[i][j] = 999;
            }
        }
    }
    // This will print the matrix
    printf("The Adjacency Matrix is:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    printf("The edges of Minimum Cost Spanning Tree are: ");
    while(m < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if(uni(find(a), find(b)))
        {
            printf("\n%d. edge (%d, %d) = %d\n", m++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}
int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
