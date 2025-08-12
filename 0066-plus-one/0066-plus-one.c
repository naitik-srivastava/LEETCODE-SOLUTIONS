#include <stdio.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *mallocDigits = (int *)malloc(sizeof(int) * (digitsSize + 1));
    
    for (int i = 0; i < digitsSize; i++)
    {
        mallocDigits[i] = digits[i];
    }
    for (int j = digitsSize - 1; j >= 0; j--)
    {
        if (digits[j] < 9 && digits[j] >= 0)
        {
            mallocDigits[j]++;
            *returnSize = digitsSize;
            return mallocDigits;
        }
        else if (j > 0)
        {
            if (digits[j - 1] != 9)
            {
                mallocDigits[j] = 0;
                mallocDigits[j - 1]++;
                *returnSize = digitsSize;
                return mallocDigits;
            }
            else if (j > 1 && j-2>=0)
            {
                mallocDigits[j] = 0;
                mallocDigits[j - 1] = 0;
                if (mallocDigits[j - 2] >= 0 && mallocDigits[j - 2] < 9)
                {
                    // mallocDigits[j - 2]++;
                }
                else
                {
                    mallocDigits[j - 2] = 1;
                }

                // mallocDigits[digitsSize] = 0;
                *returnSize = digitsSize + 1;
            }
        }
    }



     mallocDigits[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        mallocDigits[i] = 0;
    }
    *returnSize = digitsSize + 1;
    
    return mallocDigits;

}

