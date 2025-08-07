int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
 int* result= (int*)malloc(sizeof(int)*2);
 *returnSize = 2;
 for(int i=0;i<numsSize;i++)
 {
  for(int j=i+1;j<numsSize;j++)
  {
  if(nums[i]+nums[j]==target)
    {
        // printf("%d\n",target);
    //   printf("%d and %d\n",i,j);
      result[0]=i;
      result[1]=j;
      return result;
    
     break;
    }
  }
 }
     free(result);
    *returnSize = 0;
    return NULL;

}
