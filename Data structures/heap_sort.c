#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = n / 2 - 1; i >= 0; i--) {
        int root = i;
        while (2 * root + 1 < n) {
            int child = 2 * root + 1;
            if (child + 1 < n && arr[child + 1] > arr[child]) {
                child++;
            }
            if (arr[root] < arr[child]) {
                temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
                root = child;
            } else {
                break;
            }
        }
    }

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int root = 0;
        while (2 * root + 1 < i) {
            int child = 2 * root + 1;
            if (child + 1 < i && arr[child + 1] > arr[child]) {
                child++;
            }
            if (arr[root] < arr[child]) {
                temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
                root = child;
            } else {
                break;
            }
        }
    }

    printf("Sorted array (Heap Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
