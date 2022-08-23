#include <stdio.h>
#include <stdlib.h>

// maxSeqNum alogirthm
void maxSeq(int arr[], int size)
{
    // if size is smaller than 1, return -1
    if (size < 1)
        return;

    int longestSeq[size];
    int longestSeqSize = 0;

    int tempSeq[size];

    for (int i = 0; i < size; i++)
    {
        int tempSeqSize = 0;
        int tempVal = arr[i];
        tempSeq[tempSeqSize++] = arr[i];
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > tempVal)
            {
                tempSeq[tempSeqSize++] = arr[j];
                tempVal = arr[j];
            }
        }

        if (longestSeqSize < tempSeqSize)
        {
            longestSeqSize = tempSeqSize;
            for (int k = 0; k < tempSeqSize; k++)
            {
                longestSeq[k] = tempSeq[k];
            }
        }
    }

    printf("Longestsize %d:", longestSeqSize);
    for (int i = 0; i < longestSeqSize; i++)
    {
        printf("%d ", longestSeq[i]);
    }
    printf("\n");
}

int myAtoi(char *str)
{
    // Initialize result
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    // return result.
    return res;
}

int main()
{
    int arr[] = {3, 10, 7, 9, 4, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSeq(arr, n);

    return 0;
}