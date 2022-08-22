#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <limits.h>
#include <assert.h>
int thirdMax(int* nums, int numsSize) {
    int a = LONG_MIN;
    int b = LONG_MIN;
    int c = LONG_MIN;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > a) {
            c = b;
            b = a;
            a = nums[i];
        }
        else if (a > nums[i] && nums[i] > b) {
            c = b;
            b = nums[i];
        }
        else if (b > nums[i] && nums[i] > c) {
            c = nums[i];
        }
    }
    return c == LONG_MIN ? a : c;
}

int main()
{
    int arr[] = {1,-214};
    int sz = sizeof(arr) / sizeof(arr[1]);
    long ret = thirdMax(arr, sz);
    printf("%d ", ret);
    return 0;
}