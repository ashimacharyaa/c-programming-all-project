#include <stdio.h>
#include <string.h>

void main()
{
    int i, j, l;
    char s1[30], c;

    printf("Enter string: ");
    gets(s1); // Note: gets() is unsafe and deprecated. Use fgets() in real applications.

    l = strlen(s1);

    // Reverse the string using two-pointer approach
    for(i = 0, j = l - 1; i < j; i++, j--)
    {
        c = s1[i];
        s1[i] = s1[j];
        s1[j] = c;
    }

    printf("Reversed string: %s\n", s1);
}
