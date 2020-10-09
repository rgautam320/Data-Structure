/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Single Linked list Operations
#include <stdio.h>
#include <stdlib.h>
//Declaring the functions
void addend(void);
void addbegin(void);
void addafter(void);
int length(void);
void display(void);
int search(int value);
void del(void);
void delval(int value);
void dellist(void);
void swap(void);
void reverse(void);
//Declaring the Global variables/structures
struct node
{
    int data;
    struct node* link;
};
struct node* root = NULL;
int len;
//The main function
int main()
{
    int choice, value;
    while(1)
    {
        printf("Single Linked List Operations : \n");
        printf("1. Add at End\n");
        printf("2. Add at Begin\n");
        printf("3. Add at After\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Delete\n");
        printf("8. Delete Value\n");
        printf("9. Swap\n");
        printf("10. Reverse\n");
        printf("11. Delete List\n");
        printf("12. Quit\n");
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
            length();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Enter a value to search : ");
            scanf("%d", &value);
            if(search(value) == 1)
            {
                printf("%d found in the list.\n\n", value);
            }
            else
            {
                printf("%d not found in the list.\n\n", value);
            }
            break;
        case 7:
            del();
            break;
        case 8:
            printf("Enter the value to delete : ");
            scanf("%d", &value);
            delval(value);
            break;
        case 9:
            swap();
            break;
        case 10:
            reverse();
            break;
        case 11:
            dellist();
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("Invalid Entry\n");
        }
    }
    return 0;
}
//Add at end
void addend()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n\n", temp->data);
    temp->link = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void addbegin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a node to insert : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n", temp->data);
    temp->link = root;
    root = temp;
}
void addafter()
{
    struct node* temp, * p;
    int key, i = 1;
    printf("Enter location : ");
    scanf("%d", &key);
    len = length();
    if(key > len)
    {
        printf("Unable to insert\n");
        printf("The list is having only %d nodes.\n", len);
    }
    else
    {
        p = root;
        while(i < key)
        {
            p = p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter a node to insert : ");
        scanf("%d", &temp->data);
        printf("%d inserted.\n", temp->data);
        temp->link = p->link;
        p->link = temp;
    }
}
int length()
{
    int count = 0;
    struct node* temp;
    temp = root;
    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    printf("The length of the linked list is : %d\n\n", count);
    return count;
}
void display()
{
    struct node* temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}
int search(int value)
{
    struct node *p = root;
    while(p != NULL)
    {
        if(p->data == value)
        {
            return 1;
        }
        else
        {
            p = p->link;
        }
    }
    return 0;
}
void del()
{
    struct node* temp;
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    if(key > length())
    {
        printf("Invalid Location\n");
    }
    else if(key == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node* p = root, *q;
        int i = 1;
        while(i < key - 1)
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
void delval(int value)
{
    struct node* temp, *p = root, *q;
    q = root->link;
    if(root->data == value)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else if(search(value) == 1)
    {
        while(q->data != value)
        {
            p = p->link;
            q = p->link;
        }
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    else
    {
        printf("Value not found in the list.\n\n");
    }
}
void swap()
{
    struct node *p = root, *q, *r;
    int i = 1, loc;
    printf("Enter location to swap : ");
    scanf("%d", &loc);
    while(i<loc-1)
    {
        p = p->link;
        i++;
    }
    q = p->link;
    r = q->link;
    q->link = r->link;
    r->link = q;
    p->link = r;
    printf("%d node and %d node swapped successfully.\n", loc, loc+1);
}
void reverse()
{
    struct node *p, *q;
    int i=0, j, k, temp;
    len = length();
    p = q = root;
    j = len-1;
    while(i<j)
    {
        k = 0;
        while(k<j)
        {
            q = q->link;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        q = root;
        p = p->link;
        printf("Reversed successfully.\n\n");
    }
}
void dellist()
{
    struct node *temp = root, *p;
    while(temp != NULL)
    {
        p = temp->link;
        free(temp);
        temp = p;
    }
    printf("All the elements in the list deleted successfully.\n\n");
    root = NULL;
}
