#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 /*
 1.4 Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2
elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p
&amp; q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT (A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99
 */

void ROTATE_RIGHT(int *arr,int pos,int n){
     int alpha= arr[pos-1];
     for(int i=pos-2;i>=0;i--){
       arr[i+1]=arr[i];
     }
     arr[0]=alpha;
    return ;
}
int main () {
    int n;
    printf("Enter an array A of size N :");
    scanf("%d",&n);
    int arr[n];
    printf("Write down elements of array :");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    printf("Before ROTATE:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int pos=0;
    printf("\nenter pos : ");
    scanf("%d",&pos);
    ROTATE_RIGHT (arr, pos , n);
    printf("\nAfter ROTATE:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}