#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* tmp = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int i = 0;
    *returnSize = digitsSize + 1;
    for (i = digitsSize - 1; i >= 0; --i)
    {
        tmp[i + 1] = digits[i];
    }
    tmp[0] = 0;
    for (i = digitsSize; i >= 0; --i)
    {
        tmp[i] = (tmp[i] + 1) % 10;
        if (tmp[i] == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (tmp[0] == 0)
    {
        *returnSize = digitsSize;
        for (i = 0; i < digitsSize; ++i)
        {
            tmp[i] = tmp[i + 1];
        }
        tmp[i] = '\0';
    }
    return tmp;
}


int main()
{
    int arr[] = { 9,9,9,9,9,9,9,9,9 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int n = 0;
    int* pa = plusOne(arr, sz, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(pa+i));
    }
    printf("\n");
	return 0;
}