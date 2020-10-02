//Double Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
//Declaring the structures and functions
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node * root = NULL;
int len;
void addend();
void addbegin();
void addafter();
int length();
void display();
void del();
void reverse();
void swap();
//Writing inside the main function
int main()
{
    int choice;
    while(1)
    {
        printf("Double Linked List Operations : \n");
        printf("1. Append\n");
        printf("2. Add at Begin\n");
        printf("3. Add at After\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Reverse\n");
        printf("7. Swap\n");
        printf("8. Delete\n");
        printf("9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            addend();
            break;
        case 2:
            addbegin();
            break;
        case 3:
            addafter();
            break;
        case 4:
            len = length();
            printf("Length of the Double Linked List is : %d\n\n", len);
            break;
        case 5:
            display();
            break;
        case 6:
            reverse();
            break;
        case 7:
            swap();
            break;
        case 8:
            del();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
//This will add element at the end
void addend()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to append : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n\n", temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p = root;
        while(p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}
//This will add the element at the beginning
void addbegin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to insert : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n\n", temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}
//This will add the element at the the certain node
void addafter()
{
    struct node* temp, *p = root, *q;
    int key, i = 1;
    printf("Enter the location where you want to insert : ");
    scanf("%d", &key);
    if(key > len)
    {
        printf("Unable to insert \n\n");
    }
    else
    {
        while(i < key)
        {
            p = p->right;
            i++;
        }
        q = p->right;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter an element to insert : ");
        scanf("%d", &temp->data);
        printf("%d inserted\n\n", temp->data);
        temp->left = NULL;
        temp->right = NULL;
        temp->right = q;
        q->left = temp;
        p->right = temp;
        temp->left = p;
    }
}
//This calculates the length of the list
int length()
{
    struct node* temp = root;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}
//This will traverse the list when it is called
void display()
{
    struct node * temp = root;
    if(root == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->right;
        }
        printf("\n\n");
    }
}
//This will reverse and traverse the list when it is called
void reverse()
{
    struct node* temp = root;
    if(root == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        while(temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->left;
        }
        printf("\n\n");
    }
}
//This will swap the two element in the list
void swap()
{
    struct node *p = root, *q;
    int loc, i = 1, temp;
    printf("Enter location to swap : ");
    scanf("%d", &loc);
    while(i < loc)
    {
        p = p->right;
        i++;
    }
    q = p->right;
    temp = p->data;
    p->data = q->data;
    q->data = temp;
    printf("%d and %d node are swapped successfully\n\n",loc, loc+1);
}
//This will delete the element of the list at the specified position
void del()
{
    struct node* temp;
    int key, i = 1;
    printf("Enter the location of element to delete : ");
    scanf("%d", &key);
    if(key > length())
    {
        printf("Invalid Location to perform delete\n\n");
    }
    else if(key == 1)
    {
        temp = root;
        root = temp->right;
        temp->left = NULL;
        free(temp);
    }
    else if(key == length())
    {
        struct node * temp, *p;
        p = root;
        while(p->right != NULL)
        {
            p = p->right;
        }
        temp = p->left;
        temp->right = NULL;
        free(p);
    }
    else
    {
        struct node *p, *q;
        temp = root;
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

