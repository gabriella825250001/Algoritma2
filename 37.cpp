#include <stdio.h>

int main() {
    float harga, diskon, persen, harga_setelah_diskon;

    printf("=====================================\n");
    printf("        PROGRAM HITUNG DISKON        \n");
    printf("=====================================\n\n");

    printf("Masukkan harga barang   : ");
    scanf("%f", &harga);

    printf("Masukkan persen diskon  : ");
    scanf("%f", &persen);

    diskon = harga * (persen / 100);  
    harga_setelah_diskon = harga - diskon;

    printf("\n-------------------------------------\n");
    printf("| Harga Awal        : Rp %.2f   |\n", harga);
    printf("| Diskon (%.0f%%)      : Rp %.2f    |\n", persen, diskon);
    printf("-------------------------------------\n");
    printf("| Harga Setelah     : Rp %.2f    |\n", harga_setelah_diskon);
    printf("-------------------------------------\n");

    return 0;
}


