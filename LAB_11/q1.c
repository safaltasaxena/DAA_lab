#include <stdio.h>

int main()
{
    int n, key;
    int a[100];
    int low, high, mid;
    int result = -1;
    int comparisons = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if (a[mid] == key)
        {
            result = mid;
            high = mid - 1;   // Continue searching on left side
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (result != -1)
    {
        printf("%d found at index position %d\n", key, result);
        printf("Number of comparisons: %d\n", comparisons);
    }
    else
    {
        printf("%d not found\n", key);
        printf("Number of comparisons: %d\n", comparisons);
    }

    return 0;
}