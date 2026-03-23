#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM 100
#define MAX_NAMA 50

typedef struct {
    char nama[MAX_NAMA];
    int jumlah;
} Item;

void tampilkanMenu() {
    printf("\n=== SHOPPING LIST MANAGER ===\n");
    printf("1. Tambah Item\n");
    printf("2. Tampilkan Shopping List\n");
    printf("3. Keluar\n");
    printf("Pilih menu (1-3): ");
}

void simpanKeFile(Item list[], int jumlah) {
    FILE *file = fopen("shopping_list.txt", "w");
    if(file != NULL) {
        for(int i = 0; i < jumlah; i++) {
            fprintf(file, "%s;%d\n", list[i].nama, list[i].jumlah);
        }
        fclose(file);
    }
}

int bacaDariFile(Item list[]) {
    FILE *file = fopen("shopping_list.txt", "r");
    int jumlah = 0;
    
    if(file != NULL) {
        while(fscanf(file, "%[^;];%d\n", list[jumlah].nama, &list[jumlah].jumlah) != EOF) {
            jumlah++;
            if(jumlah >= MAX_ITEM) break;
        }
        fclose(file);
    }
    return jumlah;
}

int tambahItem(Item list[], int jumlah) {
    if(jumlah >= MAX_ITEM) {
        printf("Shopping list sudah penuh!\n");
        return jumlah;
    }
    
    printf("\n--- Tambah Item Baru ---\n");
    printf("Nama item: ");
    scanf(" %[^\n]", list[jumlah].nama);
    printf("Jumlah: ");
    scanf("%d", &list[jumlah].jumlah);
    
    printf("Item '%s' sebanyak %d berhasil ditambahkan!\n", list[jumlah].nama, list[jumlah].jumlah);
    return jumlah + 1;
}

void tampilkanList(Item list[], int jumlah) {
    printf("\n--- SHOPPING LIST ---\n");
    if(jumlah == 0) {
        printf("Shopping list kosong.\n");
        return;
    }
    
    printf("No.  Nama Item\t\tJumlah\n");
    printf("--------------------------------\n");
    for(int i = 0; i < jumlah; i++) {
        printf("%-4d %-20s %-10d\n", i+1, list[i].nama, list[i].jumlah);
    }
    printf("Total item: %d\n", jumlah);
}

int main() {
    Item shoppingList[MAX_ITEM];
    int jumlahItem = 0;
    int pilihan;
    
    jumlahItem = bacaDariFile(shoppingList);
    printf("Data shopping list berhasil dimuat dari file.\n");
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
                jumlahItem = tambahItem(shoppingList, jumlahItem);
                simpanKeFile(shoppingList, jumlahItem);
                break;
            case 2:
                tampilkanList(shoppingList, jumlahItem);
                break;
            case 3:
                printf("Terima kasih!.\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan pilih 1-3.\n");
        }
    } while(pilihan != 3);
    
    return 0;
}