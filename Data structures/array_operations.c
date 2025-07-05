#include <stdio.h>

int main() {
    int arr[100];
    int n, i, pos, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}