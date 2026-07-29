#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
insertion sort
tc-o(N*N)
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
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}