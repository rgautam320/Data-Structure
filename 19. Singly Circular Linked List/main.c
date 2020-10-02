//Singly Circular Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
//Declaring the structures and functions
struct node
{
    int data;
    struct node * link;
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
//Writing on Main Function
int main()
{
    int choice, len;
    while(1)
    {
        printf("Singly Circular Linked List Operations : \n");
        printf("1. Add at Beginning\n");
        printf("2. Add After\n");
        printf("3. Add End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete After\n");
        printf("6. Delete at End\n");
        printf("7. Length\n");
        printf("8. Display\n");
        printf("9. Quit\n");
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
            len = length();
            printf("The length of the list is : %d\n\n", len+1);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Entry\n");
        }
    }
    return 0;
}
//Writing functions
void addbeg()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to add at beginning : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        struct node* p = root;
        temp->link = root;
        while(p->link != root)
        {
            p = p->link;
        }
        p->link = temp;
        root = temp;
    }
}
void addafter()
{
    struct node* temp, *p;
    int key, i = 1;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to insert : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        printf("Enter position to insert : ");
        scanf("%d", &key);
        if(key > length())
        {
            printf("Invalid Location\n\n");
        }
        else if(key == length())
        {
            struct node *p;
            p = root;
            while(p->link != root)
            {
                p = p->link;
            }
            temp->link = root;
            p->link = temp;
        }
        else
        {
            p = root;
            while(i < key)
            {
                p = p->link;
                i++;
            }
            temp->link = p->link;
            p->link = temp;
        }
    }
}
void addend()
{
    struct node* temp;
    int ele;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number to insert : ");
    scanf("%d", &ele);
    temp->data = ele;
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        struct node *p;
        p = root;
        while(p->link != root)
        {
            p = p->link;
        }
        temp->link = root;
        p->link = temp;
    }
}
void delbeg()
{
    struct node* temp = root;
    if(root == NULL)
    {
        printf("The list is empty\n\n");
    }
    else
    {
        while(temp->link != root)
        {
            temp = temp->link;
        }
        temp->link = root->link;
        free(root);
        root  = temp->link;
    }
}
void delafter()
{
    struct node *temp, *p, *q;
    int key, i = 1;
    printf("Enter position to delete : ");
    scanf("%d", &key);
    if(key == 1)
    {
        while(temp->link != root)
        {
            temp = temp->link;
        }
        temp->link = root->link;
        free(root);
        root  = temp->link;
    }
    else if(key == length())
    {
        while(temp->link != root)
        {
            p = temp;
            temp = temp->link;
        }
        p->link = temp->link;
        free(temp);
    }
    else
    {
        p = root;
        while( i < key)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}
void delend()
{
    struct node* temp = root, *p;
    if(root == NULL)
    {
        printf("The list is empty\n\n");
    }
    else if(temp->link == root)
    {
        root = NULL;
        free(root);
    }
    else
    {
        while(temp->link != root)
        {
            p = temp;
            temp = temp->link;
        }
        p->link = temp->link;
        free(temp);
    }
}
int length()
{
    int count = 0;
    struct node* temp;
    temp = root;
    while(temp->link != root)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void display()
{
    struct node * temp = root;
    if (root == NULL)
    {
        printf("The list is empty\n\n");
    }
    else
    {
        while(temp->link != root)
        {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("%d -> \n\n", temp->data);
    }
}

