#include <stdio.h>
int main() {
    int i, j, num = 1;
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) { // baris genap -> urut naik
            for (j = 1; j <= 5; j++) {
                printf("%d ", num++);
            }
        } else { // baris ganjil -> urut turun
            int temp = num + 4;
            for (j = 0; j < 5; j++) {
                printf("%d ", temp--);
                num++;
            }
        }
        printf("\n");
    }
    return 0;
}