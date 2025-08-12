#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
    int k = 0;

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            k++;
            if(k>0 && i==0)return k;
            // if(k==1)return 1;
        }
        else if (s[i] == ' ' && k > 0)
        {
            printf("%d\n", k);

            return k;
        }
    }

    return 0;
    // printf("%d\n", k);
    // return 0;
}

