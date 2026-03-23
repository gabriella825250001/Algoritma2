#include <stdio.h>
int bil1, bil2;  // global variable

void input()
{
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bil1);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bil2);
}

void tambah()
{
    printf("Hasil: %d\n", bil1 + bil2);
}

void kurang()
{
    printf("Hasil: %d\n", bil1 - bil2);
}

void kali()
{
    printf("Hasil: %d\n", bil1 * bil2);
}

void bagi()
{
    if (bil2 != 0)
        printf("Hasil: %d\n", bil1 / bil2);
    else
        printf("Error: tidak bisa dibagi nol\n");
}

int main()
{
    char operasi;
    int lanjut = 1;

    while (lanjut)
    {
        input();

        printf("Pilih operasi (+, -, *, /): ");
        scanf(" %c", &operasi);

        if (operasi == '+')
            tambah();
        else if (operasi == '-')
            kurang();
        else if (operasi == '*')
            kali();
        else if (operasi == '/')
            bagi();
        else
            printf("Operasi tidak dikenal\n");

        printf("Lanjutkan? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);
    }

    return 0;
}
