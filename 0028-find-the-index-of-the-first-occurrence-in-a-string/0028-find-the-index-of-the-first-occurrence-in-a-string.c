#include <stdio.h>
#include <string.h>
// Function prototype (your implementation should match this)
int strStr(char *haystack, char *needle)
{
    int sh = strlen(haystack);
    int sn = strlen(needle);
    // printf("%d\t%d\n",sh,sn);
    if (sh == 0 || sn == 0 || sh < sn)
        return -1;
    for (int i = 0; i < sh; i++)
    {
        if (haystack[i] == needle[0])
        {
            if (sn == 1)
                return i;
            // if (i == sh - 1)
            //     return i;
    //             char haystack3[] = "missi s sippi";
    //             char needle3[] = "sipp";

            for (int j = 1; j < sn; j++)
            {
                if (i + j < sh && haystack[i + j] == needle[j])
                {
                    if (j == sn - 1)
                        return i;
                }else{break;}
            }
        }
    }
    return -1;
}

