// Write a C program to find Odd or Even number from a given set of numbers

#include<stdio.h>
int main(){
    int arr[100],n,i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            printf("%d is a even number\n",arr[i]);
        }
        else{
            printf("%d is a odd number\n",arr[i]);
        }
    }
}