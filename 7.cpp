 #include <stdio.h>
 #define PI 3.14

int main() {
    float jari2;
    float luas;
    float keliling;

    printf("====== Hitung Lingkaran =====\n\n");

    printf("Masukan jari-jari: ");
    scanf("%f", &jari2);

    luas = PI * jari2;
    printf("Luas lingkaran adalah: %.2f\n",luas);

    keliling = 2 * PI * jari2;
    printf("Keliling lingkaran adalah: %.2f\n", keliling);
    
}