//Implementation of Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
//Declaring the variables and functions
int front = -1, rear = -1;
int c_queue[CAPACITY];
void ins(int ele);
void del();
void display();
//Writing on main function
int main()
{
    while(1)
    {
        int choice, ele;
        printf("Operations on Circular Queue\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Front : %d\t Rear : %d\t\n", front, rear);
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to insert: ");
            scanf("%d", &ele);
            ins(ele);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Entry\n");
        }
    }
    return 0;
}
void ins(int ele)
{
    if((front == 0 && rear == CAPACITY-1) || (front == rear+1))
    {
        printf("Queue is Full\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if(rear == CAPACITY-1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
    }
    c_queue[rear] = ele;
}
void del()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d deleted.\n", c_queue[front]);
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == CAPACITY -1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    int i = front;
    int j = rear;
    if(front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if(i <= j)
    {
        while(i <= j)
        {
            printf("%d\t", c_queue[i]);
            i++;
        }
    }
    else
    {
        while(i <= CAPACITY-1)
        {
            printf("%d\t", c_queue[i]);
            i++;
        }
        i = 0;
        while(i <= j)
        {
            printf("%d\t", c_queue[i]);
            i++;
        }
    }
    printf("\n");
}
