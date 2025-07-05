#include <stdio.h>

int tree[100];
int n;

void inorder(int i) {
    if (i >= n || tree[i] == -1)
        return;

    inorder(2 * i + 1);     
    printf("%d ", tree[i]); 
    inorder(2 * i + 2);     
}

void preorder(int i) {
    if (i >= n || tree[i] == -1)
        return;

    printf("%d ", tree[i]); 
    preorder(2 * i + 1); 
    preorder(2 * i + 2); 
}

void postorder(int i) {
    if (i >= n || tree[i] == -1)
        return;

    postorder(2 * i + 1);
    postorder(2 * i + 2); 
    printf("%d ", tree[i]);
}

int main() {
    int i;
    printf("Enter number of nodes in tree: ");
    scanf("%d", &n);

    printf("Enter tree elements in level order (-1 for NULL):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("Inorder traversal: ");
    inorder(0);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(0);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(0);
    printf("\n");

    return 0;
}
