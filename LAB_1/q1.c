#include <stdio.h>
#include <limits.h>

int main()
{
    FILE *fp = fopen("input1.dat", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    int arr[100], n = 0;

    while (fscanf(fp, "%d", &arr[n]) == 1)
        n++;

    fclose(fp);

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest = %d\n", secondSmallest);
    printf("Second Largest = %d\n", secondLargest);

    return 0;
}