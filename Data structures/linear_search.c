//Write a C program to search a number using Linear Search method

#include<stdio.h>
int main(){
    int n,i,num,is_found=1;
    int arr[100];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to be searched\n");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(arr[i]==num){
            is_found=1;
            break;
        } 
    }
   if(is_found){
    printf("The number %d is found at index %d\n",num,i);
   }
   else{
    printf("The number %d is not found\n",num);
   }
}
