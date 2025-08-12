#include <stdio.h>
#include <stdlib.h>

void removeElement(int *nums, int *size, int pos) {
    for (int i = pos; i < *size - 1; i++) {
        nums[i] = nums[i + 1];
    }
    (*size)--; // reduce logical size
}

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) return numsSize;

    int *recDupesIndex = (int *)malloc(sizeof(int) * numsSize);
    if (!recDupesIndex) return numsSize; // guard

    int countDup = 0;

    // Record duplicate indices once per value (skip non-first occurrences of same value)
    for (int i = 0; i < numsSize - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip i if it's not the first of its value

        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                recDupesIndex[countDup++] = j;
            } else {
                break; // sorted array: once mismatch occurs, no more duplicates for this i
            }
        }
    }

    // Remove from back to front so earlier removals don't shift later indices
    for (int k = countDup - 1; k >= 0; k--) {
        removeElement(nums, &numsSize, recDupesIndex[k]);
    }

    free(recDupesIndex);
    return numsSize; // new length (number of unique elements)
}

// int main() {
//     int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);

//     int newLength = removeDuplicates(nums, numsSize);

//     printf("New length: %d\n", newLength);
//     printf("Modified array: ");
//     for (int i = 0; i < newLength; i++) {
//         printf("%d ", nums[i]);
//     }
//     printf("\n");
//     return 0;
// }
