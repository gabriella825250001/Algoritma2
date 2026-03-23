#include <stdio.h>
int main() {
    int i, j;
    int left = 7, right = 10;
    int lompatkiri = 8; 
    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("%d %d\n", left, right);
        left += lompatkiri;
        lompatkiri += (i - 1); 
        right += (i * 2 - 2); 
    }
    return 0;
}