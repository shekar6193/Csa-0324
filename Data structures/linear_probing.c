#include <stdio.h>

int main() {
    int size, i, choice, key, hash, pos, table[100];

    printf("Enter size of hash table: ");
    scanf("%d", &size);

    // Initialize table
    for (i = 0; i < size; i++) {
        table[i] = -1;
    }

    do {
        printf("\n*** Hash Table Menu ***\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to insert: ");
            scanf("%d", &key);

            hash = key % size;
            pos = hash;

            // Linear probing
            while (table[pos] != -1) {
                pos = (pos + 1) % size;
                if (pos == hash) {
                    printf("Hash table is full. Cannot insert.\n");
                    break;
                }
            }

            if (table[pos] == -1) {
                table[pos] = key;
                printf("Key inserted at position %d.\n", pos);
            }
        }
        else if (choice == 2) {
            printf("Hash table contents:\n");
            for (i = 0; i < size; i++) {
                if (table[i] == -1)
                    printf("[%d] : Empty\n", i);
                else
                    printf("[%d] : %d\n", i, table[i]);
            }
        }
        else if (choice == 3) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
