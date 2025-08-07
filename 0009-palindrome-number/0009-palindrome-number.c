#include<stdio.h>
#include <math.h>

int CountDigits(int x)
{
    int count = 0;
    if(x == 0)
    {
        return 1;
    }
    if(x < 0)
    {
        x = -x;
    }
    while(x > 0){
        x = x / 10;
        count++;
    }
    return count;
}

int isPalindrome(int x) {
    if(x < 0)return 0; // handle negative numbers
    int digits = CountDigits(x);
    int arr[digits];
    int temp = x;
    // Extract digits from right to left
    for(int i = digits - 1; i >= 0; i--) {
        arr[i] = temp % 10;
        temp = temp / 10;
    }
    // Print digits
    for(int i = 0; i < digits; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    // Palindrome check
    int is_palindrome = 1;
    for(int i = 0; i < digits / 2; i++) {
        if(arr[i] != arr[digits - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    return is_palindrome;
}

