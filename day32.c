#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if (top == MAX - 1) return; // overflow ignored
    stack[++top] = val;
}

// Pop
void pop() {
    if (top == -1) return; // underflow ignored
    top--;
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}