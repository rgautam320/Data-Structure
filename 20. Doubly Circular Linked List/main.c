//Implementation of Doubly Circular Linked List
#include <stdio.h>
#include <stdlib.h>
//Declaring the variables and functions
struct node
{
    int data;
    struct node *left, *right;
};
struct node* root;
void addbeg(void);
void addafter(void);
void addend(void);
void delbeg(void);
void delafter(void);
void delend(void);
int length(void);
void display(void);
int main()
{
    int choice;
    while(1)
    {
        printf("Doubly Circular Linked List Operations : \n");
        printf("1. Add at Beginning\n");
        printf("2. Add After\n");
        printf("3. Add End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete After\n");
        printf("6. Delete End\n");
        printf("7. Length\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            addbeg();
            break;
        case 2:
            addafter();
            break;
        case 3:
            addend();
            break;
        case 4:
            delbeg();
            break;
        case 5:
            delafter();
            break;
        case 6:
            delend();
            break;
        case 7:
            printf("The length of the list is : %d\n\n", length());
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    }
    return 0;
}
void addbeg()
{
    struct node * temp, *p = root;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to insert : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        temp->right = temp;
        temp->left = temp;
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        while(p->right != root)
        {
            p = p->right;
        }
        root = temp;
        p->right = root;
        temp->left = p;
    }
}
void addafter()
{
    struct node* temp, *p = root, *q;
    int key, i = 1;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to insert : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    printf("Enter Position to Insert : ");
    scanf("%d", &key);
    if(key > length())
    {
        printf("Invalid Location\n\n");
    }
    else if(key == length())
    {
        while(p->right != root)
        {
            p = p->right;
        }
        p->right = temp;
        root->left = temp;
        temp->right = root;
        temp->left = p;
    }
    else
    {
        while(i < key)
        {
            p = p->right;
            i++;
        }
        q = p->right;
        temp->right = q;
        q->left = temp;
        p->right = temp;
        temp->left = p;
    }
}
void addend()
{
    struct node* temp, *p = root;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to insert : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        temp->right = temp;
        temp->left = temp;
        root = temp;
    }
    else
    {
        while(p->right != root)
        {
            p = p->right;
        }
        p->right = temp;
        root->left = temp;
        temp->right = root;
        temp->left = p;
    }
}
void delbeg()
{
    struct node * temp = root, *p = root;
    while(p->right != root)
    {
        p = p->right;
    }
    temp = temp->right;
    p->right = temp;
    temp->left = p;
    root = temp;
    free(temp);
}
void delafter()
{
    struct node* temp = root, *p = root, *q;
    int key, i = 0;
    printf("Enter the location of element to delete : ");
    scanf("%d", &key);
    if(key > length())
    {
        printf("Invalid Location to perform delete\n\n");
    }
    else if(key == 1)
    {
        while(p->right != root)
        {
            p = p->right;
        }
        temp = temp->right;
        p->right = temp;
        temp->left = p;
        root = temp;
        free(temp);
    }
    else if(key == length())
    {
        while(p->right != root)
        {
            p = p->right;
        }
        temp = p->left;
        temp->right = root;
        free(p);
    }
    else
    {
        while(i < key)
        {
            temp = temp->right;
            i++;
        }
        q = temp->right;
        p = temp->left;
        p->right = q;
        q->left = p;
        free(temp);
    }
}
void delend()
{
    struct node* temp, *p = root;
    while(p->right != root)
    {
        p = p->right;
    }
    temp = p->left;
    temp->right = root;
    free(p);
}
int length()
{
    int count = 1;
    struct node * temp = root;
    while(temp->right != root)
    {
        count++;
        temp = temp->right;
    }
    return count;
}
void display()
{
    struct node * temp = root;
    if(root == NULL)
    {
        printf("The list is Empty\n\n");
    }
    else
    {
        while(temp->right != root)
        {
            printf("<-- %d -->", temp->data);
            temp = temp->right;
        }
        printf("<-- %d -->", temp->data);
        printf("\n\n");
    }
}
