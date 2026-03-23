#include <stdio.h>

int main() {
    float jam_per_hari, upah_per_jam, total_upah;

    printf("===========================================\n");
    printf("        PROGRAM HITUNG UPAH PEGAWAI        \n");
    printf("===========================================\n\n");

    printf("Masukkan banyaknya jam kerja per hari : ");
    scanf("%f", &jam_per_hari);

    printf("Masukkan upah per jam (Rp)            : ");
    scanf("%f", &upah_per_jam);

    total_upah = jam_per_hari * upah_per_jam * 7;

    printf("\n-------------------------------------------\n");
    printf("| Jam kerja per hari : %.2f jam          |\n", jam_per_hari);
    printf("| Upah per jam       : Rp %.2f        |\n", upah_per_jam);
    printf("-------------------------------------------\n");
    printf("| Total Upah Minggu  : Rp %.2f      |\n", total_upah);
    printf("-------------------------------------------\n");

    return 0;
}
