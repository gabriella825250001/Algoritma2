#include <stdio.h>
int main() {
    int mod, nilai, hasil;
    char ulang;
    printf("=== Program Modulo Sederhana ===\n");
    do {
        printf("\nMasukkan nilai modulus: ");
        scanf("%d", &mod);

        printf("Masukkan nilai yang ingin dimodulokan: ");
        scanf("%d", &nilai);

        hasil = nilai % mod;

        printf("\n%d mod %d = %d\n", nilai, mod, hasil);

        printf("\nApakah Anda ingin menghitung lagi? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    printf("\nTerima kasih telah menggunakan Program Modulo!\n");
    return 0;
}