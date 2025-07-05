#include <stdio.h>

int main() {
    int arr[100];
    int n, i, stack[100], top = -1;
    int low, high, pivot, temp;
    int left, right;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    low = 0;
    high = n - 1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = arr[low];
        left = low + 1;
        right = high;

        while (left <= right) {
            while (left <= high && arr[left] <= pivot) left++;
            while (arr[right] > pivot) right--;

            if (left < right) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }

        temp = arr[low];
        arr[low] = arr[right];
        arr[right] = temp;

        if (right - 1 > low) {
            stack[++top] = low;
            stack[++top] = right - 1;
        }

        if (right + 1 < high) {
            stack[++top] = right + 1;
            stack[++top] = high;
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
