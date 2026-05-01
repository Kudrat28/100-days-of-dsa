#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    // Case 1: key at head
    if (curr != NULL && curr->data == key) {
        head = curr->next;
        free(curr);
        return head;
    }

    // Traverse list
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key found
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, key;
    struct Node* head = NULL;

    // Input list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    // Key to delete
    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}
