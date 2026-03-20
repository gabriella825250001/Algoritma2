#include <stdio.h>

int main() {
    int n;
    printf("Masukkan jumlah bilangan ganjil positif pertama (n): ");
    scanf("%d", &n);

    int jumlah = 0;

    printf("Deret: ");
    for (int i = 1; i <= n; i++) {
        int bilangan_ganjil = 2 * i - 1;  // menghasilkan bilangan ganjil
        printf("%d", bilangan_ganjil);
        jumlah += bilangan_ganjil;

        if (i < n) {
            printf(" + ");
        }
    }

    printf(" = %d\n", jumlah);
    printf("Hasil dengan rumus n^2 = %d\n", n * n);

    return 0;
}
