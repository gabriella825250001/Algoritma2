#include <stdio.h>
int tambah(int a, int b)
{
    return a + b;
}

int kurang(int a, int b)
{
    return a - b;
}

int kali(int a, int b)
{
    return a * b;
}

int bagi(int a, int b)
{
    return a / b;
}

int main()
{
    int x, y;
    char operasi;
    int lanjut = 1;

    while(lanjut)
    {
        printf("Masukkan bilangan pertama: ");
        scanf("%d", &x);
        printf("Masukkan bilangan kedua: ");
        scanf("%d", &y);

        printf("Pilih operasi (+, -, *, /): ");
        scanf(" %c", &operasi);

        if (operasi == '+')
            printf("Hasil: %d\n", tambah(x, y));
        else if (operasi == '-')
            printf("Hasil: %d\n", kurang(x, y));
        else if (operasi == '*')
            printf("Hasil: %d\n", kali(x, y));
        else if (operasi == '/')
        {
            if (y != 0)
                printf("Hasil: %d\n", bagi(x, y));
            else
                printf("Error: tidak bisa dibagi nol\n");
        }
        else
            printf("Operasi tidak dikenal\n");

        printf("Lanjutkan? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);
    }

    return 0;
}
