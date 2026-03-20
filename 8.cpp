#include <stdio.h>

int main(){
    float sisi;
    float luas_permukaan;
    float volume;

    printf("===== Hitung Kubus ======\n\n");

    printf("Masukan panjang sisi kubus: ");
    scanf("%f", &sisi);

    luas_permukaan = 6 * (sisi * sisi);
    printf("Luas permukaan kubus adalah: %.2f\n", luas_permukaan);

    volume = sisi * sisi * sisi;
    printf("Volume kubus adalah; %.2f\n", volume);

}