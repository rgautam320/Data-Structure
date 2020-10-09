/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Implementation of Stack using Linked List
#include <stdio.h>
#include <stdlib.h>
//Defining the structures, variables and functions
struct node
{
    int data;
    struct node* link;
};
struct node* top;
void push();
void pop();
void peek();
void traverse();
//Writing on main function
int main()
{
    int choice;
    while(1)
    {
        printf("Stack Operations : \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
void push()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to push : ");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
}
void pop()
{
    struct node* temp;
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        printf("%d deleted.\n", temp->data);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}
void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("%d\n", top->data);
    }
}
void traverse()
{
    struct node* temp;
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
