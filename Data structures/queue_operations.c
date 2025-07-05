#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
int front=-1,rear=-1;
void enqueue(int n){
    if(rear==size-1){
        printf("queue overflow\n");
    }
    else{
        if(front==-1) front=0;
        rear++;
        queue[rear]=n;
        printf("the value is added");
    }
}
void dequeue(){
    if(front>rear||front == -1){
        printf("under flow");
    }
    else{
        front++;
        printf("the first element is deleted");
        if(front>rear) {
        front=rear=-1;
    }
    }
   }
void display(){
    if(front==-1){
        printf("the queue is empty");
    }
    else{
        printf("the elements are displayed below");
        for(int i=front;i<=rear;i++){
            printf("%d",queue[i]);
        }
    printf("\n");}
}
int main(){
    int value,choice;
    while(1){
        printf("\nQueue Operations:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
}}