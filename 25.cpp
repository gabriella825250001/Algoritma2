#include <stdio.h>

int main() {
    float temp[7];
    float sum = 0.0;
    float avg, min, max;
    
    // Input temperatur untuk 7 hari
    printf("Masukkan temperatur selama 7 hari:\n");
    for (int i = 0; i < 7; i++) {
        printf("Hari ke-%d: ", i + 1);
        scanf("%f", &temp[i]);
        sum += temp[i];
    }
    
    // Hitung rata-rata
    avg = sum / 7;
    
    // Cari suhu paling dingin dan paling panas
    min = temp[0];
    max = temp[0];
    
    for (int i = 1; i < 7; i++) {
        if (temp[i] < min) {
            min = temp[i];
        }
        if (temp[i] > max) {
            max = temp[i];
        }
    }
    
    // Tampilkan hasil
    printf("\n=== HASIL ANALISIS TEMPERATUR ===\n");
    printf("Suhu rata-rata: %.2f derajat\n", avg);
    printf("Suhu paling dingin: %.2f derajat\n", min);
    printf("Suhu paling panas: %.2f derajat\n", max);
    
    return 0;
}
