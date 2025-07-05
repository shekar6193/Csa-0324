#include <stdio.h>

int tree[100];
int count = 0;

void insert(int key) {
    tree[count++] = key;
    printf("Inserted.\n");
}

void display() {
    int i, j, temp;
    printf("Elements in sorted order: ");
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (tree[i] > tree[j]) {
                temp = tree[i];
                tree[i] = tree[j];
                tree[j] = temp;
            }
        }
    }
    for (i = 0; i < count; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

void search(int key) {
    int i;
    for (i = 0; i < count; i++) {
        if (tree[i] == key) {
            printf("Key found.\n");
            return;
        }
    }
    printf("Key not found.\n");
}

void delete(int key) {
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (tree[i] == key) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < count - 1; i++) {
            tree[i] = tree[i + 1];
        }
        count--;
        printf("Deleted.\n");
    } else {
        printf("Key not found. Cannot delete.\n");
    }
}

int main() {
    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
        } else if (choice == 2) {
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete(key);
        } else if (choice == 3) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
