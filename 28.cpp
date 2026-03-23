#include <stdio.h>

int main() {
    int barisA, kolomA, barisB, kolomB;

    // Input ukuran Matriks A
    printf("Masukkan jumlah baris Matriks A: ");
    scanf("%d", &barisA);
    printf("Masukkan jumlah kolom Matriks A: ");
    scanf("%d", &kolomA);

    // Input ukuran Matriks B
    printf("\nMasukkan jumlah baris Matriks B: ");
    scanf("%d", &barisB);
    printf("Masukkan jumlah kolom Matriks B: ");
    scanf("%d", &kolomB);

    // Cek syarat perkalian
    if (kolomA != barisB) {
        printf("\nMaaf, banyaknya kolom pada Matriks A tidak sama dengan banyaknya baris pada Matriks B.\n");
        printf("Syarat perkalian matriks tidak dipenuhi.\n");
        return 0;
    }

    int A[100][100], B[100][100], C[100][100];

    // Input elemen Matriks A
    printf("\nMasukkan elemen-elemen Matriks A:\n");
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            printf("Elemen baris %d kolom %d: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Input elemen Matriks B
    printf("\nMasukkan elemen-elemen Matriks B:\n");
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            printf("Elemen baris %d kolom %d: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Proses perkalian
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < kolomA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Tampilkan Matriks A
    printf("\nMatriks A (%dx%d):\n", barisA, kolomA);
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    // Tampilkan Matriks B
    printf("\nMatriks B (%dx%d):\n", barisB, kolomB);
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    // Tampilkan hasil perkalian
    printf("\nHasil Perkalian Matriks (A x B) = C (%dx%d):\n", barisA, kolomB);
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
