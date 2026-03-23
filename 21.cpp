#include <stdio.h>

int main() {
    int usia;
    int nilaiTeori;
    char lulusPraktik; // 'Y' atau 'N'

    printf("=== Cek Kelayakan SIM ===\n");
    printf("Masukkan usia: ");
    scanf("%d", &usia);

    printf("Apakah lulus ujian praktik? (Y/N): ");
    scanf(" %c", &lulusPraktik);

    printf("Masukkan nilai ujian teori: ");
    scanf("%d", &nilaiTeori);

    if (usia >= 16 && (lulusPraktik == 'Y' || lulusPraktik == 'y') && nilaiTeori >= 75) {
        printf("Selamat, Anda layak mendapatkan SIM!\n");
    } else {
        printf("Maaf, Anda belum layak mendapatkan SIM.\n");
    }
    
    return 0;
}
