#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
void push(int n){
    if(top>=max-1){
        printf("Stack Overflow! Cannot push %d\n",n);

    }
    else{
        top++;
        stack[top]=n;
        printf("%d pushed onto the stack.\n",n);
    }

}
void pop(){
    if(top<0){
        printf("the stack is empty");
    }
    else{
        printf("Popped element: %d\n", stack[top]);
        top--;
    }

}
void peek() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}
void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice,value;
    while(1){
         printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("enter the value to be pushed");
            scanf("%d",&value);
            push(value);
            break;
             case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");

        }
    }
}