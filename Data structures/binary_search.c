// Write a C program to search a number using Binary Search method

#include<stdio.h>
int main(){
    int i,n,num,low,mid,high,found=0;
    int arr[100];
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to be searched\n");
    scanf("%d",&num);
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==num){
            found=1;
            break;
        }
        else if(arr[mid]<num){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
if(found){
    printf("The number %d is found at index %d\n",num,mid);
}
else{
    printf("The number %d is not found\n",num);
}
}