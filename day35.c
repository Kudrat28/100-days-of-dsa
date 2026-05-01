#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) return 0; // underflow case

    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while (expr[i] != '\0') {
        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If operand (digit)
        if (isdigit(expr[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            push(&stack, num);
        }
        else {
            // Operator
            int b = pop(&stack);
            int a = pop(&stack);

            int result;

            switch (expr[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char expr[100];

    // Read full line (important)
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);

    printf("%d", result);

    return 0;
}