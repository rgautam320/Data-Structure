//Implementation of Double Ended Queue
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 6
//Defining variables
int queue[CAPACITY];
int front = -1, rear = -1;
//Writing on functions
int isEmpty()
{
    if(front == rear)
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
    if(rear == CAPACITY-1 || front == -CAPACITY || rear+(-front)==CAPACITY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueueF(int ch)
{
    if(isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        queue[front] = ch;
        printf("%d enqueued\n",queue[front]);
        front--;
    }
}
void enqueueR(int ch)
{
    if(isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        queue[++rear] = ch;
        printf("%d enqueued\n",queue[rear]);
    }
}
int dequeueF()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ++front;
        printf("%d dequeued\n", queue[front]);
    }
    return queue[front];
}
int dequeueR()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d dequeued\n", queue[rear]);
    }
    return queue[rear--];
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
        for(i = front+1; i<=rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
void length()
{
    int i, j=0;
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for(i = front+1; i<=rear; i++)
        {
            j++;
        }
        printf("Length : %d\n", j);
    }
}
//Writing inside the main function
int main()
{
    while(1)
    {
        int choice;
        int item;
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Traverse\n");
        printf("6. Length\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter element to push in Front\n");
            scanf("%d", &item);
            enqueueF(item);
            break;
        case 2:
            printf("Enter element to push in Rear\n");
            scanf("%d", &item);
            enqueueR(item);
            break;
        case 3:
            dequeueF();
            break;
        case 4:
            dequeueR();
            break;
        case 5:
            traverse();
            break;
        case 6:
            length();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Entry\n");
        }
        //Printing the value of Front and Rear to understand the code
        printf("Front: %d \t Rear: %d\n", front, rear);
    }
    return 0;
}
