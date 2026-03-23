#include <stdio.h>
#include <stdlib.h>
int main() {
    int bilangan[5];
    int maksimal = 0;
    int max_dari_file;
    
    printf("Masukkan 5 bilangan integer:\n");
    for(int i = 0; i < 5; i++) {
        printf("Bilangan ke-%d: ", i+1);
        scanf("%d", &bilangan[i]);
    }
    
    printf("\nKe-5 bilangan yang dimasukkan:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", bilangan[i]);
    }
    
    maksimal = bilangan[0];
    for(int i = 1; i < 5; i++) {
        if(bilangan[i] > maksimal) {
            maksimal = bilangan[i];
        }
    }
    printf("\n\nNilai maksimal dari array: %d\n", maksimal);
    
    // Membaca file MaxValue.txt
    FILE *file = fopen("MaxValue.txt", "r");
    if(file != NULL) {
        fscanf(file, "%d", &max_dari_file);
        fclose(file);
        printf("Nilai maksimal dari file: %d\n", max_dari_file);
        
    
        if(maksimal > max_dari_file) {
            file = fopen("MaxValue.txt", "w");
            fprintf(file, "%d", maksimal);
            fclose(file);
            printf("Nilai dalam file telah digantikan dengan nilai maksimal yang baru: %d\n", maksimal);
        } else {
            printf("Nilai dalam file tidak berubah.\n");
        }
    } else {
        // Jika file tidak ada, buat file baru
        file = fopen("MaxValue.txt", "w");
        fprintf(file, "%d", maksimal);
        fclose(file);
        printf("File MaxValue.txt dibuat dengan nilai maksimal: %d\n", maksimal);
    }
    
    return 0;
}