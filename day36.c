#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int val, int size) {
    if ((rear + 1) % size == front) {
        // queue full
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = val;
}

// Dequeue
void dequeue(int size) {
    if (front == -1) return; // empty

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

// Display
void display(int size) {
    if (front == -1) return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) break;
        i = (i + 1) % size;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x, n);
    }

    // Number of dequeues
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(n);
    }

    // Display
    display(n);

    return 0;
}