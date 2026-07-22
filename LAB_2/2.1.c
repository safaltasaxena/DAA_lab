#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
2.1 Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file.
Note# Read the value of ‘n’, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file.
Give the contents of the input disc file “inDec.dat” as
30 75 2564 …
Contents of the output disc file “outBin.dat” as
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat
Output: Content of the first ‘n’ decimal and their equivalent binary numbers*/
void fnc(int num){
    if(num>0){
        fnc(num/2);
        printf("%d",num%2);
    }
}
int  main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The binary equivalent of the numbers are:\n");
    for(int i=0;i<n;i++){
        printf("The binary equivalent of %d is ",arr[i]);
        fnc(arr[i]);
        printf("\n");
    }
    return 0;

}