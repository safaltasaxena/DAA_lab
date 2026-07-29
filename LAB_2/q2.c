#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
2.3 Aim of the program: Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from a file and store the result in a separate file.
Note# Source file name and destination file name taken from command line arguments. The
source file must contain at least 20 pairs of numbers.
Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
Contents of the output disc file “outGcd.dat” as
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
Terminal Input:
$gcc lab2q2.c -o lab2q2
$./lab2q2 inGcd.dat outGcd.dat
Output: Display the gcd stored in the output file outGcd.dat
*/

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("Usage: ./lab2q2 input output");
        return 0;
    }

    FILE *in=fopen(argv[1],"r");
    FILE *out=fopen(argv[2],"w");

    if(in==NULL||out==NULL)
    {
        printf("File Error");
        return 0;
    }

    int a,b;

    while(fscanf(in,"%d%d",&a,&b)==2)
    {
        fprintf(out,"The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    }

    fclose(in);
    fclose(out);

    printf("Results stored successfully.\n");

    return 0;
}