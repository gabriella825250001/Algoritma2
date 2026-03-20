#include <stdio.h>

int main() {
    float harga, pajak, layanan, total;

    printf("=====================================\n");
    printf("   PROGRAM HITUNG TAGIHAN RESTORAN    \n");
    printf("=====================================\n\n");

    printf("Masukkan harga makanan: ");
    scanf("%f", &harga);

    pajak = harga * 0.11;    // 11% pajak
    layanan = harga * 0.05;  // 5% biaya layanan
    total = harga + pajak + layanan;

    printf("\n-------------------------------------\n");
    printf("| Harga Makanan  : Rp %.2f        |\n", harga);
    printf("| Pajak (11%%)    : Rp %.2f         |\n", pajak);
    printf("| Layanan (5%%)   : Rp %.2f         |\n", layanan);
    printf("-------------------------------------\n");
    printf("| TOTAL TAGIHAN  : Rp %.2f        |\n", total);
    printf("-------------------------------------\n");

    return 0;
}
