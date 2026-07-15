#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*1.1 Aim of the program: Write a program to find out the second smallest and second largest
element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest
*/
int main() {
    int n;
    printf("Write size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Write down elements of array");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    //sort
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
       }
    }
    printf("Second smallest %d and second largest %d",arr[1],arr[n-2]);

    return 0;
}