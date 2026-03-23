#include <stdio.h>

int main() {
    int sks, semester, skpi;
    float ipk;
    char lulus_skripsi, tulisan_ilmiah, sertifikasi;
    int alasan_count = 0;

    printf("============================================================\n");
    printf("         PROGRAM CEK KELULUSAN MAHASISWA UNTAR\n");
    printf("============================================================\n\n");

    printf("Masukkan jumlah SKS: ");
    scanf("%d", &sks);

    printf("Masukkan IPK: ");
    scanf("%f", &ipk);

    printf("Masukkan lama masa studi (semester): ");
    scanf("%d", &semester);

    printf("Apakah lulus skripsi? (y/n): ");
    scanf(" %c", &lulus_skripsi);

    printf("Apakah memiliki tulisan ilmiah? (y/n): ");
    scanf(" %c", &tulisan_ilmiah);

    printf("Masukkan poin SKPI: ");
    scanf("%d", &skpi);

    printf("Apakah memiliki sertifikasi? (y/n): ");
    scanf(" %c", &sertifikasi);

    printf("\n============================================================\n");
    printf("                     HASIL EVALUASI\n");
    printf("============================================================\n");

    // Menggunakan ternary untuk set flag awal
    int lulus = (sks >= 144) ? 1 : 0;
    if (lulus == 0) {
        printf("Tidak lulus karena SKS kurang dari 144.\n");
        alasan_count++;
    }

    // Nested if untuk cek IPK dan semester
    if (ipk >= 2.4) {
        if (semester <= 16) {
            lulus = (lulus == 1) ? 1 : 0; 
        } else {
            printf("Tidak lulus karena masa studi lebih dari 16 semester.\n");
            alasan_count++;
            lulus = 0;
        }
    } else {
        printf("Tidak lulus karena IPK kurang dari 2.4.\n");
        alasan_count++;
        lulus = 0;
    }

    // Switch untuk cek lulus skripsi
    switch (lulus_skripsi) {
        case 'y':
        case 'Y':
            break;
        case 'n':
        case 'N':
            printf("Tidak lulus karena belum lulus skripsi.\n");
            alasan_count++;
            lulus = 0;
            break;
        default:
            printf("Input tidak valid untuk skripsi, dianggap tidak lulus.\n");
            alasan_count++;
            lulus = 0;
    }

    // If untuk tulisan ilmiah
    if (tulisan_ilmiah == 'y' || tulisan_ilmiah == 'Y') {
        // Lanjut
    } else {
        printf("Tidak lulus karena belum memiliki tulisan ilmiah.\n");
        alasan_count++;
        lulus = 0;
    }

    // Else if untuk SKPI
    if (skpi >= 150) {
        // Lanjut
    } else if (skpi < 150) {
        printf("Tidak lulus karena poin SKPI kurang dari 150.\n");
        alasan_count++;
        lulus = 0;
    } else {
        lulus = 0;
    }

    // If else untuk sertifikasi
    if (sertifikasi == 'y' || sertifikasi == 'Y') {
        // Lanjut
    } else if (sertifikasi == 'n' || sertifikasi == 'N') {
        printf("Tidak lulus karena belum memiliki sertifikasi.\n");
        alasan_count++;
        lulus = 0;
    } else {
        printf("Input tidak valid untuk sertifikasi, dianggap tidak lulus.\n");
        alasan_count++;
        lulus = 0;
    }

    printf("------------------------------------------------------------\n");
    // If else if else untuk kesimpulan akhir
    if (alasan_count == 0 && lulus == 1) {
        printf("Selamat, Anda LULUS!\n");
    } else if (alasan_count > 0) {
        printf("Anda TIDAK lulus karena %d alasan di atas.\n", alasan_count);
    } else {
        printf("Terjadi kesalahan dalam pengecekan.\n");
    }
    printf("============================================================\n");
    
    return 0;
}


