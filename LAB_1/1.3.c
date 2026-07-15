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
int main () {
    int n;
    printf("Enter how many numbers you want to read from file :");
    scanf("%d",&n);
    int arr[n];
    printf("Write down elements of array :");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    int max=0,val=-1,tot=0;
    printf("Total number of duplicate values =");
    for(int i=0;i<n;i++){
        int key=arr[i];
        int freq=0;
        int seen=0;
        int check=arr[i];
        for(int k=0;k<i;k++){
                if(check==arr[k]){
                    seen=1;
                    break;
                }
            }
        if(seen==1)continue;
        for(int j=0;j<n;j++){

            if(key==arr[j])freq++;
            if(max<freq){
                max=freq;
                val=key;
            }
        }
        if(freq>=2)tot++;
    }
    printf("%d\n ",tot);
    printf("The most repeating element in the array = %d",val);

    return 0;
}