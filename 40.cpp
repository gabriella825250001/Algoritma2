#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

// Global variable
char adminUser[20] = "admin";
char adminPass[20] = "12345";

int posisi1 = 0;
int posisi2 = 0;
int giliran = 1;
int board[SIZE + 1];

// Fungsi login admin
void loginAdmin() {
    char user[20], pass[20];
    printf("=== LOGIN ADMIN ===\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    // menggunakan strcmp untuk perbandingan string
    if (strcmp(adminUser, user) == 0 && strcmp(adminPass, pass) == 0) {
        printf("Login berhasil!\n");
    } else {
        printf("Login gagal! Username atau password salah.\n");
    }
}

// Inisialisasi papan (tangga & ular)
void initBoard() {
    int i;
    for (i = 1; i <= SIZE; i++) {
        board[i] = 0;
    }
    // tangga
    board[3] = 22;
    board[5] = 8;
    board[11] = 26;
    board[20] = 29;
    // ular
    board[27] = 1;
    board[21] = 9;
    board[17] = 4;
    board[19] = 7;
}

// Fungsi lempar dadu
int lemparDadu() {
    return (rand() % 6) + 1;
}

// Fungsi main game (1 giliran)
void mainkanGiliran() {
    int dadu, *posisi;
    if (giliran == 1)
        posisi = &posisi1;
    else
        posisi = &posisi2;

    printf("\nGiliran Player %d\n", giliran);
    printf("Tekan ENTER untuk melempar dadu...");
    getchar(); // buang enter sisa dari scanf sebelumnya
    getchar(); // tunggu enter dari user

    dadu = lemparDadu();
    printf("Dadu: %d\n", dadu);

    *posisi += dadu;
    if (*posisi > SIZE) *posisi = SIZE;

    if (board[*posisi] != 0) {
        if (board[*posisi] > *posisi)
            printf("Naik tangga dari %d ke %d!\n", *posisi, board[*posisi]);
        else
            printf("Turun ular dari %d ke %d!\n", *posisi, board[*posisi]);
        *posisi = board[*posisi];
    }

    printf("Posisi Player 1: %d | Player 2: %d\n", posisi1, posisi2);

    if (*posisi >= SIZE) {
        printf("Player %d MENANG!!!\n", giliran);
        posisi1 = 0;
        posisi2 = 0;
        giliran = 1;
        return;
    }

    if (giliran == 1) giliran = 2;
    else giliran = 1;
}

// Simpan game ke file
void simpanData() {
    FILE *f = fopen("save.txt", "w");
    if (f == NULL) {
        printf("Gagal menyimpan data!\n");
        return;
    }
    fprintf(f, "%d %d %d\n", posisi1, posisi2, giliran);
    fclose(f);
    printf("Data berhasil disimpan ke save.txt!\n");
}

// Load game dari file
void muatData() {
    FILE *f = fopen("save.txt", "r");
    if (f == NULL) {
        printf("Tidak ada file save.txt!\n");
        return;
    }
    fscanf(f, "%d %d %d", &posisi1, &posisi2, &giliran);
    fclose(f);
    printf("Data berhasil dimuat!\n");
    printf("Posisi Player 1: %d | Player 2: %d | Giliran: %d\n", posisi1, posisi2, giliran);
}

// Menu utama
void menu() {
    int pilih = 0;
    while (pilih != 6) {
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Login Admin\n");
        printf("2. Mulai Game Baru\n");
        printf("3. Lanjutkan Game\n");
        printf("4. Simpan Game\n");
        printf("5. Mainkan Giliran\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: loginAdmin(); break;
            case 2: initBoard(); posisi1 = posisi2 = 0; giliran = 1; printf("Game baru dimulai!\n"); break;
            case 3: muatData(); break;
            case 4: simpanData(); break;
            case 5: mainkanGiliran(); break;
            case 6: printf("Keluar program.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    menu();
    return 0;
}