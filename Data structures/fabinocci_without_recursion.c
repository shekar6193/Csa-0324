// Write a C program to find Fibonacci series without using Recursion

#include<stdio.h>
int main(){
    int n,a=0,b=1,c,i;
    printf("Enter the limit\n");
    scanf("%d",&n);
    while(i<=n){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
        i++;
    }
}