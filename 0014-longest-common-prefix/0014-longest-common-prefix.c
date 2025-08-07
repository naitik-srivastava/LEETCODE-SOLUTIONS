#include <stdio.h>
#include <stdlib.h>

#include <string.h>


char *longestCommonPrefix(char **strs, int strsSize)
{ 
      // Find the minimum length string
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) {
            minLen = len;
        }
    }//we are finding the minimum length string in the array of strings,beca-
    //use the common prefix cannot be longer than the shortest string.
    
    
    char *result= (char*)malloc(sizeof(char)*(minLen + 1));
       int j = 0;
while (j < minLen) {
    char c = strs[0][j];
    for (int i = 1; i < strsSize; i++) {
        if (strs[i][j] != c) {
            result[j] = '\0';
            return result;
        }
    }
    result[j] = c;
    j++;
}
result[j] = '\0';
return result;

    // result[minLen]= '\0';
    // puts(result);
    // return result;
}