#include <stdio.h>

int main() {
    int numbers[10];
    int odd[10], even[10];
    int odd_count = 0, even_count = 0;
    
    // Input 10 bilangan dari user
    printf("Masukkan 10 bilangan integer:\n");
    for (int i = 0; i < 10; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &numbers[i]);
        
        // Cek ganjil atau genap
        if (numbers[i] % 2 == 0) {
            even[even_count] = numbers[i];
            even_count++;
        } else {
            odd[odd_count] = numbers[i];
            odd_count++;
        }
    }
    
    // Tampilkan bilangan ganjil
    printf("\nBilangan Ganjil:\n");
    if (odd_count > 0) {
        for (int i = 0; i < odd_count; i++) {
            printf("%d ", odd[i]);
        }
        printf("\n");
    } else {
        printf("Tidak ada bilangan ganjil\n");
    }
    
    // Tampilkan bilangan genap
    printf("\nBilangan Genap:\n");
    if (even_count > 0) {
        for (int i = 0; i < even_count; i++) {
            printf("%d ", even[i]);
        }
        printf("\n");
    } else {
        printf("Tidak ada bilangan genap\n");
    }
    
    return 0;
}
