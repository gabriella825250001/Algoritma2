#include <stdio.h>

int main() {
    int n = 5;
    for (int k = 1; k <= n; k++) {

        
        for (int s = 1; s <= n - k + 1; s++) {
            printf("*");
        }
    
        printf("%d\n", k * k + 1);
    }
    return 0;
}