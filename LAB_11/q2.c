#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n, int *comparisons)
{
    int i, j, key;

    *comparisons = 0;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0)
        {
            (*comparisons)++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
            {
                break;
            }
        }

        a[j + 1] = key;
    }
}

int main()
{
    int choice;
    int a[500];
    int n = 0;
    int comparisons;
    char inputFile[30], outputFile[30];

    FILE *in, *out;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            strcpy(inputFile, "inAsce.dat");
            strcpy(outputFile, "outInsAsce.dat");
            break;

        case 2:
            strcpy(inputFile, "inDesc.dat");
            strcpy(outputFile, "outInsDesc.dat");
            break;

        case 3:
            strcpy(inputFile, "inRand.dat");
            strcpy(outputFile, "outInsRand.dat");
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    in = fopen(inputFile, "r");

    if (in == NULL)
    {
        printf("Unable to open input file.\n");
        return 1;
    }

    while (fscanf(in, "%d", &a[n]) == 1)
    {
        n++;

        if (n == 500)
            break;
    }

    fclose(in);

    printf("\nBefore Sorting: Content of the input file\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    insertionSort(a, n, &comparisons);

    out = fopen(outputFile, "w");

    if (out == NULL)
    {
        printf("Unable to create output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        fprintf(out, "%d ", a[i]);

    fclose(out);

    printf("\nAfter Sorting: Content of the output file\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    printf("Number of Comparisons: %d\n", comparisons);

    if (choice == 1)
        printf("Scenario: Best-case\n");
    else if (choice == 2)
        printf("Scenario: Worst-case\n");
    else
        printf("Scenario: Average-case\n");

    return 0;
}