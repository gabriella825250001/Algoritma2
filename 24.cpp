#include <stdio.h>  

int main() {  
    int tinggi = 3;  
    
    // Bagian atas diamond (baris 1-3)
    for (int i = 1; i <= tinggi; i++) {  
        for (int j = 1; j <= (tinggi - i); j++) {  
            printf(" ");  
        }
        for (int k = 1; k <= (2 * i - 1); k++) {  
            printf("*");  
        }
        printf("\n");  
    }
    
    // Bagian bawah diamond (baris 4-5)
    for (int i = tinggi - 1; i >= 1; i--) { 
        for (int j = 1; j <= (tinggi - i); j++) {  
            printf(" ");  
        }
        for (int k = 1; k <= (2 * i - 1); k++) {  
            printf("*");  
        }
        printf("\n");  
    }
    return 0;  
}