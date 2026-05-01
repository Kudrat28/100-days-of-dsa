#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level-order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = createNode(arr[i]);
            queue[++rear] = curr->left;
            i++;
        }

        // Right child
        if (i < n) {
            curr->right = createNode(arr[i]);
            queue[++rear] = curr->right;
            i++;
        }
    }

    return root;
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check CBT
int isComplete(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total) return 0;

    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}