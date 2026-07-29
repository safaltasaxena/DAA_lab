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

void binary(int n)
{
    if(n>1)
        binary(n/2);

    printf("%d",n%2);
}

void binaryFile(FILE *fp,int n)
{
    if(n>1)
        binaryFile(fp,n/2);

    fprintf(fp,"%d",n%2);
}

int main(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Usage: ./q1 n input output\n");
        return 0;
    }

    int limit=atoi(argv[1]);

    FILE *in=fopen(argv[2],"r");
    FILE *out=fopen(argv[3],"w");

    if(in==NULL||out==NULL)
    {
        printf("File Error");
        return 0;
    }

    int x,count=0;

    while(count<limit && fscanf(in,"%d",&x)==1)
    {
        fprintf(out,"Binary of %d = ",x);
        binaryFile(out,x);
        fprintf(out,"\n");

        printf("%d -> ",x);
        binary(x);
        printf("\n");

        count++;
    }

    fclose(in);
    fclose(out);

    return 0;
}