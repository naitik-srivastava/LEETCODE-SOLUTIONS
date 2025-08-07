#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int romanToInt(char *s)
{
    int size = strlen(s);
    int map[size];
    for (int i = 0; i < size; i++)
    {
        // printf("%d\n",(int)s[i]);
        if (s[i] == 'I')
        {
            map[i] = 1;
        }
        if (s[i] == 'V')
        {
            map[i] = 5;
        }
        if (s[i] == 'X')
        {
            map[i] = 10;
        }
        if (s[i] == 'L')
        {
            map[i] = 50;
        }
        if (s[i] == 'C')
        {
            map[i] = 100;
        }
        if (s[i] == 'D')
        {
            map[i] = 500;
        }
        if (s[i] == 'M')
        {
            map[i] = 1000;
        }
    }
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d\n", map[i]);
    // }

    
    int original[size];
    memcpy(original, map, sizeof(map)); // copy map[] to original[]

    qsort(original, size, sizeof(int), compare_desc);

    if (size>=3 && map[0] == 5 && map[2] == 5)
    {
        return -1;
    }
    else if (size == 3 && map[0] == map[1] && map[0] == map[2] )
    {
        return map[0] + map[1] + map[2];
    }
    else if (memcmp(original, map, sizeof(original)) == 0)
    {
        int sum = 0;
        for (int k = 0; k < size; k++)
        {
            sum = sum + map[k];
        }
        return sum;
    }
    else if (memcmp(original, map, sizeof(original)) != 0)
    {
        for (int l = 0; l < size - 1; l++)
        {
            if (map[l] < map[l + 1])
            {
                map[l + 1] = map[l + 1] - map[l];
                map[l] = 0;
            }
        }
        int u = 0;
        for (int q = 0; q < size; q++)
        {
            u = u + map[q];
        }
        return u;
    }
    // printf("%d\n",memcmp(original, map, sizeof(original)));
    return 0;
}
