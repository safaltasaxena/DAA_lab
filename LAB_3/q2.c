//binary search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binary_search(int arr[], int l, int h, int key){
    if(l>h){
        printf("Element not found\n");
        return;
    }
    int mid=l+(h-l)/2;
    if(arr[mid]==key){
        printf("Element found at index %d\n", mid);
        return;
    }
    else if(arr[mid]>key){
        binary_search(arr,l,mid-1,key);
    }
    else{
        binary_search(arr,mid+1,h,key);
    }
    return;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in sorted order: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    int key;
    scanf("%d", &key);
    binary_search(arr, 0, n-1, key);
    return 0;
}