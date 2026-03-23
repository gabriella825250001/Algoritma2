#include <stdio.h>
int main() {
    int i, j;
    int pattern[5] = {5, 3, 1, 3, 5};
    int max = 5; 
    for (i = 0; i < 5; i++) {
        // cetak spasi biar rata tengah
        for (j = 0; j < (max - pattern[i]) / 2; j++) {
            printf(" ");
        }
        for (j = 0; j < pattern[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}