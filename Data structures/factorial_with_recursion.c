// Write a C program to find Factorial of a given number using Recursion

#include<stdio.h>
int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*fact(n-1);
}
int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
   printf("The factorial of %d is %d\n",n,fact(n));
}