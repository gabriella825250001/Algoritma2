#include <stdio.h>
int main() {
    int i, j;
    char ch = 'A';
    for (i = 1; i <= 4; i++) {
        // cetak spasi biar rata kanan
        for (j = 1; j <= 4 - i; j++) {
            printf("  "); 
        }
        for (j = 1; j <= i; j++) {
            printf("%c ", ch++);
        }
        printf("\n");
    }
    return 0;
}