//Conversion of Infix Expression into Prefix Expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 100
//Defining variables
int top = -1;
char stack[CAPACITY];
//Defining Methods
void push(char item)
{
    if(top>= CAPACITY-1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
char pop()
{
    char item;
    item = stack[top];
    top--;
    return(item);
}
int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
//Writing on Main Function
int main()
{
    char infix[CAPACITY], prefix[CAPACITY], tempo[CAPACITY], item, temp;
    int i = 0, j = 0, k = 0, l = 0;
    printf("Enter an Infix Expression to Convert into Prefix : ");
    gets(tempo);
    for(k = strlen(tempo)-1; k>=0; k--)
    {
        infix[l] = tempo[k];
        l++;
    }
    while(infix[i]!='\0')
    {
        item = infix[i];
        if(item == ')')
        {
            push(item);
        }
        else if((item >= 'A' && item <= 'Z') || (item >= 'a' && item <= 'z'))
        {
            prefix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            temp = pop();
            while(is_operator(temp) == 1 && precedence(temp) >= precedence(item))
            {
                prefix[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(item);
        }
        else if(item == '(')
        {
            temp = pop();
            while(temp != ')')
            {
                prefix[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            printf("Invalid Expression\n");
        }
        i++;
    }
    while(top > -1)
    {
        prefix[j] = pop();
        j++;
    }
    printf("Arithmetic Expression in Prefix form is : ");
    for(i = strlen(prefix)-1; i>= 0 ; i--)
    {
        printf("%c", prefix[i]);
    }
    return 0;
}
