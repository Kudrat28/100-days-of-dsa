#include <stdio.h>

int main() {
    int n, pos;
    
    // Input size
    scanf("%d", &n);
    
    int a[n];
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Input position (1-based)
    scanf("%d", &pos);
    
    // Check valid position
    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }
    
    // Convert to 0-based index
    int index = pos - 1;
    
    // Shift elements left
    for(int i = index; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    
    // Reduce size
    n--;
    
    // Print updated array
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
