#include <stdio.h>
#include <string.h>

void displayMenu();
void inputItemNames(char items[][50], int size);
void addStock(int stocks[], int size, char items[][50]);
void reduceStock(int stocks[], int size, char items[][50]);
void displayHistogram(int stocks[], int size, char items[][50]);

int main() {
    char items[5][50];
    int stocks[5] = {0, 0, 0, 0, 0};
    int choice;
    
    printf("=== SISTEM MANAJEMEN GUDANG TOSERBA ===\n\n");
    
    // Input nama barang di setiap rak
    inputItemNames(items, 5);
    
    // Menu utama
    do {
        displayMenu();
        printf("Pilih menu: ");
        scanf("%d", &choice);
        getchar(); // Membersihkan newline
        
        switch(choice) {
            case 1:
                addStock(stocks, 5, items);
                break;
            case 2:
                reduceStock(stocks, 5, items);
                break;
            case 3:
                displayHistogram(stocks, 5, items);
                break;
            case 4:
                printf("\nTerima kasih telah menggunakan sistem gudang!\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n\n");
        }
    } while(choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n========== MENU GUDANG ==========\n");
    printf("1. Tambah Stok\n");
    printf("2. Kurangi Stok\n");
    printf("3. Tampilkan Histogram Stok\n");
    printf("4. Keluar\n");
    printf("=================================\n");
}

void inputItemNames(char items[][50], int size) {
    printf("Masukkan nama barang untuk setiap rak:\n");
    for(int i = 0; i < size; i++) {
        printf("Rak %d: ", i + 1);
        fgets(items[i], 50, stdin);
        items[i][strcspn(items[i], "\n")] = 0; // Hapus newline
    }
    printf("\nNama barang berhasil disimpan!\n");
}

void addStock(int stocks[], int size, char items[][50]) {
    int rack, amount;
    
    printf("\n=== TAMBAH STOK ===\n");
    printf("Pilih rak (1-%d): ", size);
    scanf("%d", &rack);
    
    if(rack < 1 || rack > size) {
        printf("Nomor rak tidak valid!\n");
        return;
    }
    
    printf("Jumlah stok yang ditambahkan: ");
    scanf("%d", &amount);
    
    if(amount < 0) {
        printf("Jumlah tidak boleh negatif!\n");
        return;
    }
    
    stocks[rack - 1] += amount;
    printf("\nStok %s di Rak %d berhasil ditambah %d unit.\n", items[rack - 1], rack, amount);
    printf("Total stok sekarang: %d unit\n", stocks[rack - 1]);
}

void reduceStock(int stocks[], int size, char items[][50]) {
    int rack, amount;
    
    printf("\n=== KURANGI STOK ===\n");
    printf("Pilih rak (1-%d): ", size);
    scanf("%d", &rack);
    
    if(rack < 1 || rack > size) {
        printf("Nomor rak tidak valid!\n");
        return;
    }
    
    printf("Stok saat ini: %d unit\n", stocks[rack - 1]);
    printf("Jumlah stok yang dikurangi: ");
    scanf("%d", &amount);
    
    if(amount < 0) {
        printf("Jumlah tidak boleh negatif!\n");
        return;
    }
    
    if(stocks[rack - 1] - amount < 0) {
        printf("\nGAGAL! Stok tidak mencukupi.\n");
        printf("Stok tersedia: %d unit, diminta: %d unit\n", stocks[rack - 1], amount);
        return;
    }
    
    stocks[rack - 1] -= amount;
    printf("\nStok %s di Rak %d berhasil dikurangi %d unit.\n", items[rack - 1], rack, amount);
    printf("Sisa stok sekarang: %d unit\n", stocks[rack - 1]);
}

void displayHistogram(int stocks[], int size, char items[][50]) {
    printf("\n========== HISTOGRAM STOK GUDANG ==========\n\n");
    
    for(int i = 0; i < size; i++) {
        printf("Rak %d - %-20s [%3d]: ", i + 1, items[i], stocks[i]);
        
        // Tampilkan histogram dengan karakter '#'
        for(int j = 0; j < stocks[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
    
    printf("\n===========================================\n");
}