#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    // Tum implement karoge
    for (int i = 1; i < numsSize; i++)
    {   if(target==nums[0])return 0;
        if (nums[i] == target)
        {
            return i;
        }
        if (nums[i-1] < target && target < nums[i])
        {
            return i;
        }
    }
    if (target > nums[numsSize - 1])
    {
        return numsSize;
    }
    else
    {
        return 0;
    }
}

