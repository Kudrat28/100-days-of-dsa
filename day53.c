#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue node for BFS (node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[++rear] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[++rear] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode q[200];
    int front = 0, rear = -1;

    // Store results
    int hdMap[200][200]; // simple storage
    int count[200] = {0};

    int offset = 100; // to handle negative indices

    // Start BFS
    q[++rear] = (struct QNode){root, 0};

    while (front <= rear) {
        struct QNode temp = q[front++];

        int hd = temp.hd + offset;

        // Store node
        hdMap[hd][count[hd]++] = temp.node->data;

        if (temp.node->left)
            q[++rear] = (struct QNode){temp.node->left, temp.hd - 1};

        if (temp.node->right)
            q[++rear] = (struct QNode){temp.node->right, temp.hd + 1};
    }

    // Print result
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", hdMap[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}