#include <stdio.h>

#define BIAYA_STANDAR 0.035


float hitungAsuransi(int kode, float nilaiTanggungan, float luas);
void cetakSlip(char nama[], 
               int kode1, float nilai1, float luas1, float biaya1,
               int kode2, float nilai2, float luas2, float biaya2,
               int kode3, float nilai3, float luas3, float biaya3,
               int jumlah, float total);
const char* namaLadang(int kode);

// menghitung biaya asuransi
float hitungAsuransi(int kode, float nilaiTanggungan, float luas) {
    float biayaStandar = BIAYA_STANDAR * nilaiTanggungan * luas;
    float biayaAkhir;

    if (kode >= 1 && kode <= 4)         // kacang kedelai, kentang, bawang merah, cabai
        biayaAkhir = 2.0 * biayaStandar;
    else if (kode >= 5 && kode <= 7)    // padi, singkong, jagung
        biayaAkhir = 1.5 * biayaStandar;
    else                                // lainnya
        biayaAkhir = biayaStandar;

    return biayaAkhir;
}

// menampilkan nama jenis ladang
const char* namaLadang(int kode) {
    switch(kode) {
        case 1: return "Kacang kedelai";
        case 2: return "Kentang";
        case 3: return "Bawang merah";
        case 4: return "Cabai";
        case 5: return "Padi";
        case 6: return "Singkong";
        case 7: return "Jagung";
        default: return "Lainnya";
    }
}

// mencetak slip pembayaran
void cetakSlip(char nama[], 
               int kode1, float nilai1, float luas1, float biaya1,
               int kode2, float nilai2, float luas2, float biaya2,
               int kode3, float nilai3, float luas3, float biaya3,
               int jumlah, float total) {

    printf("\n========================================================\n");
    printf("           SLIP PEMBAYARAN ASURANSI LADANG              \n");
    printf("========================================================\n");
    printf("Nama Petani: %s\n", nama);
    printf("--------------------------------------------------------\n");
    printf("No | Jenis Ladang      | Nilai/ha  | Luas(ha) | Biaya Asuransi\n");
    printf("--------------------------------------------------------\n");

    if (jumlah >= 1)
        printf("1  | %-17s | Rp%-7.0f | %-8.2f | Rp %.2f\n", 
                namaLadang(kode1), nilai1, luas1, biaya1);
    if (jumlah >= 2)
        printf("2  | %-17s | Rp%-7.0f | %-8.2f | Rp %.2f\n", 
                namaLadang(kode2), nilai2, luas2, biaya2);
    if (jumlah >= 3)
        printf("3  | %-17s | Rp%-7.0f | %-8.2f | Rp %.2f\n", 
                namaLadang(kode3), nilai3, luas3, biaya3);

    printf("--------------------------------------------------------\n");
    printf("TOTAL ASURANSI YANG HARUS DIBAYAR: Rp %.2f\n", total);
    printf("========================================================\n");
    printf("Terima kasih atas kepercayaan Anda.\n");
    printf("========================================================\n");
}

// Program Utama 
int main() {
    char nama[50];
    int jumlah;
    int kode1 = 0, kode2 = 0, kode3 = 0;
    float nilai1 = 0, nilai2 = 0, nilai3 = 0;
    float luas1 = 0, luas2 = 0, luas3 = 0;
    float biaya1 = 0, biaya2 = 0, biaya3 = 0;
    float total = 0.0;

    printf("========================================================\n");
    printf("     PROGRAM PERHITUNGAN ASURANSI LADANG PERTANIAN      \n");
    printf("========================================================\n");

    // input nama petani
    printf("Masukkan nama petani (tanpa spasi): ");
    scanf("%s", nama);

    printf("\nKode jenis ladang:\n");
    printf("1. Kacang kedelai\n");
    printf("2. Kentang\n");
    printf("3. Bawang merah\n");
    printf("4. Cabai\n");
    printf("5. Padi\n");
    printf("6. Singkong\n");
    printf("7. Jagung\n");
    printf("8. Lainnya\n");

    printf("\nMasukkan jumlah jenis ladang (maksimum 3): ");
    scanf("%d", &jumlah);

    if (jumlah < 1 || jumlah > 3) {
        printf("Error: jumlah ladang harus antara 1-3!\n");
        return 1;
    }

    if (jumlah >= 1) {
        printf("\nData Ladang ke-1:\n");
        printf("-----------------\n");
        printf("Masukkan kode jenis ladang: ");
        scanf("%d", &kode1);
        printf("Nilai tanggungan per hektar (Rp): ");
        scanf("%f", &nilai1);
        printf("Luas ladang (hektar): ");
        scanf("%f", &luas1);
        biaya1 = hitungAsuransi(kode1, nilai1, luas1);
        total += biaya1;
    }

    if (jumlah >= 2) {
        printf("\nData Ladang ke-2:\n");
        printf("-----------------\n");
        printf("Masukkan kode jenis ladang: ");
        scanf("%d", &kode2);
        printf("Nilai tanggungan per hektar (Rp): ");
        scanf("%f", &nilai2);
        printf("Luas ladang (hektar): ");
        scanf("%f", &luas2);
        biaya2 = hitungAsuransi(kode2, nilai2, luas2);
        total += biaya2;
    }

    if (jumlah >= 3) {
        printf("\nData Ladang ke-3:\n");
        printf("-----------------\n");
        printf("Masukkan kode jenis ladang: ");
        scanf("%d", &kode3);
        printf("Nilai tanggungan per hektar (Rp): ");
        scanf("%f", &nilai3);
        printf("Luas ladang (hektar): ");
        scanf("%f", &luas3);
        biaya3 = hitungAsuransi(kode3, nilai3, luas3);
        total += biaya3;
    }

    // cetak hasil akhir
    cetakSlip(nama, 
              kode1, nilai1, luas1, biaya1,
              kode2, nilai2, luas2, biaya2,
              kode3, nilai3, luas3, biaya3,
              jumlah, total);

    return 0;
}
