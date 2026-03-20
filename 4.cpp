#include <stdio.h>

int main() {
    int n;
    printf("Masukkan bilangan bulat positif n: ");
    scanf("%d", &n);

    int jumlah = 0;

    printf("Deret: ");
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        jumlah += i; // Menjumlahkan manual dengan loop
        if (i < n) {
            printf(" + ");
        }
    }

    printf(" = %d\n", jumlah);

    return 0;
}