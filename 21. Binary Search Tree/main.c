//Implementation of Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
//Declaration of variables and structures
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node * root = NULL;
void insert(int ele);
struct node* del(struct node* root, int ele);
struct node* FindMin(struct node* root);
void traverse_inorder(struct node* root);
void traverse_preorder(struct node* root);
void traverse_postorder(struct node* root);
int search(struct node *root, int ele);
int height(struct node* root);
int main()
{
    while(1)
    {
        int choice, ele;
        printf("<--- Operations on BST --->\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. In order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post order Traversal\n");
        printf("6. Search\n");
        printf("7. Height\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to insert : ");
            scanf("%d", &ele);
            printf("%d successfully inserted.\n\n", ele);
            insert(ele);
            break;
        case 2:
            printf("Enter an element to Delete : ");
            scanf("%d", &ele);
            del(root, ele);
            break;
        case 3:
            traverse_inorder(root);
            printf("\n");
            break;
        case 4:
            traverse_preorder(root);
            printf("\n");
            break;
        case 5:
            traverse_postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter an element to search : ");
            scanf("%d", &ele);
            if(search(root, ele)==1)
            {
                printf("%d found.\n", ele);
            }
            else
            {
                printf("%d not found.\n", ele);
            }
            break;
        case 7:
            printf("Maximum Height : %d\n", height(root));
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    }
    return 0;
}
//Function to insert an element to the tree
void insert(int ele)
{
    struct node* temp, *p, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        q = root;
        while(1)
        {
            p = q;
            if(temp->data < p->data)
            {
                q = q->left;
                if(q == NULL)
                {
                    p->left = temp;
                    return;
                }
            }
            else
            {
                q = q->right;
                if(q == NULL)
                {
                    p->right = temp;
                    return;
                }
            }
        }
    }
}
//Function to delete the node of each stage
struct node* del(struct node *root, int ele)
{
    if(root == NULL)
    {
        printf("Unable to Delete.\n\n");
        return root;
    }
    else if(ele < root->data)
    {
        root->left = del(root->left, ele);
    }
    else if(ele > root->data)
    {
        root->right = del(root->right, ele);
    }
    else
    {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        //Case 2: One Child
        //Element in left
        else if(root->left == NULL)
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        //Element in Right
        else if(root->left == NULL)
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        //Case 3: Node having two Children
        else
        {
            struct node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
}
//To find the minimum value in right sub-tree
struct node* FindMin(struct node* root)
{
    if(root == NULL)
    {
        return root;
    }
    else if(root->left != NULL)
    {
        return FindMin(root->left);
    }
    return root;
}
//To traverse in different manners
void traverse_inorder(struct node* root)
{
    if(root != NULL)
    {
        traverse_inorder(root->left);
        printf("%d\t", root->data);
        traverse_inorder(root->right);
    }
}
void traverse_preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}
void traverse_postorder(struct node* root)
{
    if(root != NULL)
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d\t", root->data);
    }
}
//To search element in the tree
int search(struct node *root, int ele)
{
    struct node *q = root;
    if(q == NULL)
    {
        return 0;
    }
    else if(ele == q->data)
    {
        return 1;
    }
    else if(ele < q->data)
    {
        return search(q->left, ele);
    }
    else
    {
        return search(q->right, ele);
    }
}
int height(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int c1 = height(root->left);
        int c2 = height(root->right);
        if(c1>c2)
        {
            return c1+1;
        }
        else
        {
            return c2+1;
        }
    }
}
