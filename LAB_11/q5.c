#include <stdio.h>

int greedy1(int n)
{
    int steps = 0;

    printf("Reduction sequence:\n");
    printf("%d", n);

    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n - 1;
        }

        printf(" -> %d", n);
        steps++;
    }

    printf("\n");

    return steps;
}

int main()
{
    int n;
    int steps;

    printf("Enter n: ");
    scanf("%d", &n);

    steps = greedy1(n);

    printf("Number of steps: %d\n", steps);

    return 0;
}