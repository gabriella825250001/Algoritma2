#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("======================================\n");
    printf("     Program Penjumlahan 1 sampai 20  \n");
    printf("======================================\n");

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    for (int i = 1; i <= 20; i++) {
        sum += i;
    }

    printf("======================================\n");
    printf("Jumlah dari 1 sampai %d adalah %d\n", n, sum);
    printf("======================================\n");

    return 0;
}