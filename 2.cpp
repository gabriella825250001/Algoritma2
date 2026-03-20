#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("=========================================\n");
    printf("     KONVERSI SUHU CELSIUS KE FAHRENHEIT  \n");
    printf("=========================================\n\n");

    printf("Masukkan suhu dalam Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("\n-----------------------------------------\n");
    printf("|  %.2f derajat celcius  =  %.2f derajat fahrenheit  |\n", celsius, fahrenheit);
    printf("-----------------------------------------\n");

    return 0;
}