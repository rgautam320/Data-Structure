//Stack Implementation using static array
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5  //Preprocessor macro
int stack[CAPACITY], top=-1;
void push(int);
int pop();
int isFull();
int isEmpty();
void traverse();
void peek();
int main()
{
    //Repeating while loop
    while(1)
    {
        int ch, item;
        printf("1. Push \n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse \n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        //Switching Cases
        switch (ch)
        {
        case 1:
            printf("Enter element to push\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if(item == 0)
            {
                printf("Stack is underflow\n");
            }
            else
            {
                printf("Popped item is %d \n", item);
            }
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
            printf("Invalid Input\n");
        }
    }
    return 0;
}
//Push Function
void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Full \n");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("%d pushed \n", ele);
    }
}
//Pop Function
int pop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}
//isFull Function
int isFull()
{
    if(top == CAPACITY -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//isEmpty Function
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Peek Function
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Peek Element : %d\n", stack[top]);
    }
}
//Traverse Function
void traverse()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int i;
        for(i = 0; i<=top; i++)
        {
            printf("%d \n", stack[i]);
        }
    }
}
