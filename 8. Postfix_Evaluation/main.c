//Program to evaluate postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define CAPACITY 50
//Defining top and other variables
int top = -1;
int stack[CAPACITY];
char postfix_expression[CAPACITY];
void push(int ch);
int pop();
int isEmpty();
int evaluation();
//Writing on Main Function
int main()
{
    int final_answer;
    printf("Enter Expression to Evaluate : \n");
    scanf("%s", postfix_expression);
    final_answer = evaluation();
    printf("Evaluation of Postfix Expression : %d", final_answer);
    return 0;
}
void push(int ch)
{
    if(top > CAPACITY)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return stack[top--];
    }
}
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
int evaluation()
{
    int x, y, temp, value, i;
    for(i = 0; i<strlen(postfix_expression); i++)
    {
        if(postfix_expression[i] <= '9' && postfix_expression[i]>= '0')
        {
            push(postfix_expression[i]-'0');
        }
        else
        {
            x = pop();
            y = pop();
            switch(postfix_expression[i])
            {
            case '+':
                temp = y+x;
                break;
            case '-':
                temp = y-x;
                break;
            case '*':
                temp = y*x;
                break;
            case '/':
                temp = y/x;
                break;
            case '%':
                temp = y%x;
                break;
            case '^':
                temp = pow(y,x);
                break;
            default:
                printf("Invalid\n");
            }
            push(temp);
        }
    }
    value = pop();
    return value;
}
