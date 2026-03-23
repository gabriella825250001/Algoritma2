#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, userGuess, attempts = 0;
    
    srand(time(NULL));
    secretNumber = rand() % 10 + 1; // Angka acak antara 1-10
    
    printf("Tebak angka antara 1-10. Kamu punya 3 kesempatan\n");
    
    do {
        printf("Masukkan tebakanmu: ");
        scanf("%d", &userGuess);
        attempts++;
        
        if (userGuess == secretNumber) {
            printf("Selamat! kamu benar!\n");
            break;
        } else {
            printf("Tebakanmu salah. ");
            if (userGuess > secretNumber) {
                printf("Terlalu besar.\n");
            } else {
                printf("Terlalu kecil.\n");
            }
            if (attempts < 3) {
                printf("Coba lagi Kesempatan tersisa: %d\n", 3 - attempts);
            }
        }
    } while (attempts < 3);
    
    if (attempts == 3 && userGuess != secretNumber) {
        printf("Game Over! Angka yang benar adalah %d\n", secretNumber);
    }
    
    return 0;
}
