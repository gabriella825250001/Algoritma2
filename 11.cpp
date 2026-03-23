#include <stdio.h>
int main() {
    int m, n, a, b, q, r;
    int x1, y1, x2, y2, x, y, pbb;
    char ulang;

    printf("=== Program PBB (Algoritma Euclidean) ===\n");

    do {
        printf("\nMasukkan nilai m: ");
        scanf("%d", &m);
        printf("Masukkan nilai n: ");
        scanf("%d", &n);

        // Simpan nilai awal
        a = m;
        b = n;

        // Inisialisasi untuk Extended Euclidean
        x1 = 1; y1 = 0;
        x2 = 0; y2 = 1;

        // Algoritma Euclidean + Extended
        while (b != 0) {
            q = a / b;
            r = a % b;

            a = b;
            b = r;

            // Update koefisien x dan y
            int tempX = x1 - q * x2;
            int tempY = y1 - q * y2;
            x1 = x2;
            y1 = y2;
            x2 = tempX;
            y2 = tempY;
        }

        pbb = a;  // hasil terakhir a adalah PBB
        x = x1;
        y = y1;

        // Tampilkan hasil
        printf("\nPBB dari %d dan %d adalah: %d\n", m, n, pbb);
        printf("Kombinasi lanjar: %d(%d) + %d(%d) = %d\n", m, x, n, y, pbb);

        if (pbb == 1) {
            printf("Kedua bilangan %d dan %d adalah relatif prima.\n", m, n);
        }

        printf("\nApakah Anda ingin menghitung lagi? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    printf("\nTerima kasih telah menggunakan Program PBB!\n");
    return 0;
}
