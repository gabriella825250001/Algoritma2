#include <stdio.h>

int main() {
    float pengeluaran_harian, total_pengeluaran, hari;

    printf("============================================\n");
    printf("       PROGRAM HITUNG PENGELUARAN BULANAN   \n");
    printf("============================================\n\n");

    printf("Masukkan pengeluaran harian (Rp) : ");
    scanf("%f", &pengeluaran_harian);

    printf("Masukkan jumlah hari dalam sebulan: ");
    scanf("%f", &hari);

    total_pengeluaran = pengeluaran_harian * hari;

    printf("\n--------------------------------------------\n");
    printf("| Pengeluaran Harian : Rp %.2f        |\n", pengeluaran_harian);
    printf("| Jumlah Hari        : %.0f hari             |\n", hari);
    printf("--------------------------------------------\n");
    printf("| TOTAL BULANAN      : Rp %.2f       |\n", total_pengeluaran);
    printf("--------------------------------------------\n");

    return 0;
}
