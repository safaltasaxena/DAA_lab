//min max element using merge sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void merge_sort(int arr[], int l, int h,int mid){
    if(l>=h){
       return;
    }
    int n1=mid-l+1;
    int n2=h-mid;
    int left[n1], right[n2];
    for(int i=0; i<n1; i++){
        left[i]=arr[l+i];
    }
    for(int j=0; j<n2; j++){
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
    return;
    
}
void merge(int arr[],int l,int h){
    if (l >= h)
        return;
    int mid=l+(h-l)/2;
    merge(arr,l,mid);
    merge(arr,mid+1,h);
    merge_sort(arr,l,h,mid);
    return;
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    merge(arr, 0, n-1);
    printf("min element: %d\n", arr[0]);
    printf("max element: %d\n", arr[n-1]);
    return 0;
}
