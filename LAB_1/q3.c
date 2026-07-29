#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
1.3 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.

a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.

Input:
Enter how many numbers you want to read from file: 15
Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10
*/

int main()
{
    FILE *fp=fopen("input3.dat","r");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    int arr[100];
    int n=0;

    while(fscanf(fp,"%d",&arr[n])==1)
        n++;

    fclose(fp);

    printf("Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");

    int duplicate=0;
    int maxCount=0;
    int mostRepeat=arr[0];

    for(int i=0;i<n;i++)
    {
        int count=1;

        int first=1;

        for(int k=0;k<i;k++)
            if(arr[k]==arr[i])
                first=0;

        if(!first)
            continue;

        for(int j=i+1;j<n;j++)
            if(arr[i]==arr[j])
                count++;

        if(count>1)
            duplicate++;

        if(count>maxCount)
        {
            maxCount=count;
            mostRepeat=arr[i];
        }
    }

    printf("Duplicate values = %d\n",duplicate);
    printf("Most repeating = %d\n",mostRepeat);

    return 0;
}