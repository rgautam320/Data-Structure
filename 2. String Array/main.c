#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Getting a String
    char ch[100],ch2[100], str;
    int i, temp = 0, dumb=0;

    printf("Enter a String\n");
    gets(ch);
    printf("\nEnter another String\n");
    gets(ch2);

    //Checking for palindrome
    for(i = 0; i< strlen(ch); i++)
    {
        if(ch[i] != ch[strlen(ch)-i-1])
        {
            temp = 1;
            break;
        }
    }

    //Showing the result
    if(temp)
    {
        printf("%s is not palindrome.\n", ch);
    }
    else
    {
        printf("%s is palindrome.\n", ch);
    }

    //Finding the occurrence of character
    printf("Enter a character to check\n");
    scanf("%c", &str);
    for(i = 0; i<strlen(ch); i++)
    {
        if(ch[i] == str)
        {
            printf("%c is found in %d position.\n", str,i);
            break;
        }
    }

    //Comparing two strings
    for(i = 0; i< 6; i++)
    {
        if(ch[i] != ch2[i])
        {
             dumb = 1;
             break;
        }

    }
    if(dumb)
    {
        printf("Strings %s and %s are not equal.", ch, ch2);
    }
    else
    {
        printf("Strings %s and %s are equal.", ch, ch2);
    }
    return 0;
}
