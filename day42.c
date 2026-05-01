#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Stack push
void push(int x) {
    stack[++top] = x;
}

// Stack pop
int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue → stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue indices
    front = 0;
    rear = -1;

    // Step 2: Move stack → queue
    while (top != -1) {
        enqueue(pop());
    }

    // Output
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}