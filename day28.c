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

// Insert at end (circular)
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode; // point to itself
        return newNode;
    }

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Print circular list
void printCLL(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // stop when back to head
}

int main() {
    int n, x;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    // Output
    printCLL(head);

    return 0;
}