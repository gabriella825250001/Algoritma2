#include <stdio.h>

int main() {
    char lampu;

    printf("=== Simulator Lampu Lalu Lintas ===\n");
    printf("Masukkan kode lampu (M = Merah, K = Kuning, H = Hijau): ");
    scanf(" %c", &lampu);

    if (lampu == 'M' || lampu == 'm') {
        printf("Berhenti\n");
    } else if (lampu == 'K' || lampu == 'k') {
        printf("Pelan-Pelan\n");
    } else if (lampu == 'H' || lampu == 'h') {
        printf("Jalan\n");
    } else {
        printf("Kode tidak valid!\n");
    }
    
    return 0;
}