#include <stdio.h>

int main() {
    int X, Y;
    int i, nilai;

    printf("Masukkan nilai X (integer positif): ");
    scanf("%d", &X);
    printf("Masukkan nilai Y (integer): ");
    scanf("%d", &Y);

    printf("Deret numerik: ");
    nilai = Y;
    for (i = 0; i < X; i++) {
        printf("%d ", nilai);
        nilai += X;
    }

    return 0;
}