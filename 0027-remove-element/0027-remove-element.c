int removeElement(int *nums, int numsSize, int val)
{
    // nums={3,2,2,3,4,3};
    // int stack[numsSize+1];
    int countVal = 0;
    int top = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[++top] = nums[i];
        }
        else
        {
            countVal++;
        }
    }
    // for (int j = 0; j <= top; j++)
    // {
    //     nums[j] = stack[j];
    // }
    //    free(stack);
   return numsSize - countVal;
} 
