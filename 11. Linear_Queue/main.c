//Implementation of Linear Queue
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
//Defining variables
int queue[CAPACITY];
int front = -1, rear = -1;
//Writing on functions
int isEmpty()
{
    if(front == -1 || front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(rear == CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int ch)
{
    if(isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        rear++;
        queue[rear] = ch;
        if(front == -1)
        {
            front++;
        }
        printf("%d enqueued\n",ch);
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d dequeued\n", queue[front]);
        return queue[front++];
    }
}
void peek()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d peeked\n", queue[front]);
    }
}
void traverse()
{
    int i;
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for(i = front; i<=rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
//Writing inside the main function
int main()
{
    while(1)
    {
        int choice;
        int item;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:

            printf("Enter element to push\n");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Entry\n");
        }
    }
    return 0;
}
