//  Write a C program to find Factorial of a given number without using Recursion

#include<stdio.h>
int main(){
    int n,factorial=1,i;
    printf("Enter the number\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        factorial*=i;
    }
    printf("The factorial of %d is %d\n",n,factorial);

}