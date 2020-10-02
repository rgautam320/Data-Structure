//Implementation of Queue using Static Memory Allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 5
//Declaring the variables.
int queue[CAPACITY];
int front = 0;
int rear = 0;
int i;
//Inserting an element into the queue
void ins()
{
    if(rear == CAPACITY)
    {
        printf("Queue is Full\n");
    }
    else
    {
        int ele;
        printf("Enter element to Insert\n");
        scanf("%d", &ele);
        queue[rear] = ele;
        rear++;
    }
}
//Deleting the element from first [FIFO]
void del()
{
    if(front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted item is : %d\n",queue[front]);
        for(i = 0; i<rear-1; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }
}
//Printing the elements in queue
void traverse()
{
    if(front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue Elements are : \n");
        for(i = front; i<rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
//Writing on Main Function
int main()
{
    int choice;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            ins();
            break;
        case 2:
            del();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Entry");
        }
    }
    return 0;
}
