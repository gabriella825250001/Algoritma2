#include <stdio.h>
int main() {
    int n = 5;  
    int i, j, angka;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        angka = 1;
        for (j = 0; j <= i; j++) {
            printf("%d ", angka);
            angka = angka * (i - j) / (j + 1);  
        }
        printf("\n");
    }
    return 0;
}