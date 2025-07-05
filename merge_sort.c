#include <stdio.h>

int main() {
    int arr[100], n;
    int i, size, left_start;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int temp[100];

    for (size = 1; size < n; size = 2 * size) {
        for (left_start = 0; left_start < n; left_start += 2 * size) {
            int mid = left_start + size - 1;
            int right_end = left_start + 2 * size - 1;
            if (mid >= n)
                continue;
            if (right_end >= n)
                right_end = n - 1;

            int i = left_start;
            int j = mid + 1;
            int k = left_start;

            while (i <= mid && j <= right_end) {
                if (arr[i] <= arr[j]) {
                    temp[k] = arr[i];
                    i++;
                } else {
                    temp[k] = arr[j];
                    j++;
                }
                k++;
            }
            while (i <= mid) {
                temp[k] = arr[i];
                i++;
                k++;
            }
            while (j <= right_end) {
                temp[k] = arr[j];
                j++;
                k++;
            }

            for (i = left_start; i <= right_end; i++) {
                arr[i] = temp[i];
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
