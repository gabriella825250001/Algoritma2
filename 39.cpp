#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ROWS 15
#define COLS 6
#define SEAT_LABELS "ABCDEF"
#define KURSI_FILE "Kursi.txt"
#define HARGA_FILE "Harga.txt"
#define BAGASI_FILE "Bagasi.txt"

#define ADMIN_USER "admin"
#define ADMIN_PASS "admin123"

const char EMPTY_SEAT = '_';
const char BOOKED_SEAT = 'X';

int price_first = 1500000;
int price_business = 1000000;
int price_economy = 600000;
int bagasi_A = 100000;
int bagasi_B = 175000;
int bagasi_C = 300000;

char seats[ROWS][COLS];

long long total_pendapatan_maskapai = 0;

typedef struct {
    char nama_pemesan[100];
    int total_bayar;
    char metode_bayar[20];
    time_t waktu_pemesanan;
} PembayaranData;

PembayaranData pembayaran_terakhir;

void initialize_defaults_files() {
    FILE *f;
    f = fopen(HARGA_FILE, "r");
    if (f == NULL) {
        f = fopen(HARGA_FILE, "w");
        if (f) {
            fprintf(f, "%d\n%d\n%d\n", price_first, price_business, price_economy);
            fclose(f);
        }
    } else {
        if (fscanf(f, "%d %d %d", &price_first, &price_business, &price_economy) != 3) {
            rewind(f);
            fscanf(f, "%d\n%d\n%d\n", &price_first, &price_business, &price_economy);
        }
        fclose(f);
    }

    f = fopen(BAGASI_FILE, "r");
    if (f == NULL) {
        f = fopen(BAGASI_FILE, "w");
        if (f) {
            fprintf(f, "%d\n%d\n%d\n", bagasi_A, bagasi_B, bagasi_C);
            fclose(f);
        }
    } else {
        if (fscanf(f, "%d %d %d", &bagasi_A, &bagasi_B, &bagasi_C) != 3) {
            rewind(f);
            fscanf(f, "%d\n%d\n%d\n", &bagasi_A, &bagasi_B, &bagasi_C);
        }
        fclose(f);
    }
}

void load_seats_from_file() {
    FILE *f = fopen(KURSI_FILE, "r");
    if (!f) {
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                seats[r][c] = EMPTY_SEAT;
        f = fopen(KURSI_FILE, "w");
        if (f) {
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    fputc(seats[r][c], f);
                    if (c < COLS-1) fputc(' ', f);
                }
                fputc('\n', f);
            }
            fclose(f);
        }
        return;
    }
    char line[256];
    int r = 0;
    while (fgets(line, sizeof(line), f) && r < ROWS) {
        int c = 0;
        char *p = line;
        while (*p && c < COLS) {
            if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') { p++; continue; }
            seats[r][c] = *p;
            c++;
            p++;
        }
        for (; c < COLS; c++) seats[r][c] = EMPTY_SEAT;
        r++;
    }
    for (; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            seats[r][c] = EMPTY_SEAT;
    fclose(f);
}

void save_seats_to_file() {
    FILE *f = fopen(KURSI_FILE, "w");
    if (!f) {
        printf("Gagal menyimpan ke %s\n", KURSI_FILE);
        return;
    }
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            fputc(seats[r][c], f);
            if (c < COLS-1) fputc(' ', f);
        }
        fputc('\n', f);
    }
    fclose(f);
}

void print_header() {
    printf("\n===== Denah Kursi (Baris 1-%d, Kolom A-F) =====\n", ROWS);
    printf("           A B C D E F\n");
    printf("----------------------\n");
}            

void display_seating_chart() {
    print_header();
    for (int r = 0; r < ROWS; r++) {
        printf("Baris %2d | ", r+1);
        for (int c = 0; c < COLS; c++) {
            printf("%c ", seats[r][c]);
        }
        printf("\n");
    }
    printf("Note: %c kosong, %c terisi tanpa bagasi, A/B/C = terisi dengan pilihan bagasi\n", EMPTY_SEAT, BOOKED_SEAT);
}

int seat_index_from_letter(char letter) {
    char L = toupper((unsigned char)letter);
    const char *p = strchr(SEAT_LABELS, L);
    if (!p) return -1;
    return (int)(p - SEAT_LABELS);
}

int class_of_row(int row) {
    if (row >= 1 && row <= 2) return 1;
    if (row >= 3 && row <= 5) return 2;
    return 3;
}

int price_of_class(int cls) {
    if (cls == 1) return price_first;
    if (cls == 2) return price_business;
    return price_economy;
}

void search_seat_info() {
    int row;
    char seatchar;
    printf("Masukkan nomor baris (1-%d): ", ROWS);
    if (scanf("%d", &row) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }
    printf("Masukkan kolom baris (A-F): ");
    while ((seatchar = getchar()) == '\n' || seatchar == '\r');
    while (getchar()!='\n');
    int col = seat_index_from_letter(seatchar);
    if (row < 1 || row > ROWS || col < 0 || col >= COLS) {
        printf("Baris atau huruf kursi tidak valid.\n");
        return;
    }
    char status = seats[row-1][col];
    if (status == EMPTY_SEAT) printf("Kursi %d%c masih kosong.\n", row, toupper(seatchar));
    else if (status == BOOKED_SEAT) printf("Kursi %d%c sudah dipesan (tanpa bagasi).\n", row, toupper(seatchar));
    else printf("Kursi %d%c sudah dipesan dengan bagasi tipe '%c'.\n", row, toupper(seatchar), status);
}

int count_empty_in_class(int cls) {
    int start = (cls == 1) ? 1 : (cls == 2 ? 3 : 6);
    int end = (cls == 1) ? 2 : (cls == 2 ? 5 : 15);
    int cnt = 0;
    for (int r = start; r <= end; r++) {
        for (int c = 0; c < COLS; c++)
            if (seats[r-1][c] == EMPTY_SEAT) cnt++;
    }
    return cnt;
}

void recommend_seats(int cls, int qty) {
    int start = (cls == 1) ? 1 : (cls == 2 ? 3 : 6);
    int end = (cls == 1) ? 2 : (cls == 2 ? 5 : 15);
    int found = 0;
    printf("Rekomendasi kursi terbaik (kelas %d):\n", cls);
    for (int r = start; r <= end && found < qty; r++) {
        for (int c = 0; c < COLS && found < qty; c++) {
            if (seats[r-1][c] == EMPTY_SEAT) {
                printf(" - %d%c\n", r, SEAT_LABELS[c]);
                found++;
            }
        }
    }
    if (found < qty) {
        printf("Hanya ditemukan %d kursi kosong pada kelas ini.\n", found);
    }
}

void process_payment(int total_bayar, char *nama_pemesan) {
    char metode[20];
    int nominal;
    
    printf("\n=== PROSES PEMBAYARAN ===\n");
    printf("Total yang harus dibayar: Rp %d\n", total_bayar);
    
    while(1) {
        printf("Metode Pembayaran (Cash/Debit/QRIS/Ewallet): ");
        scanf("%s", metode);
        
        printf("Masukkan nominal pembayaran: Rp ");
        if (scanf("%d", &nominal) != 1) {
            printf("Input tidak valid!\n");
            while(getchar()!='\n');
            continue;
        }
        
        if (nominal < total_bayar) {
            printf("Nominal pembayaran kurang! Kurang: Rp %d\n", total_bayar - nominal);
            printf("Silakan masukkan nominal yang sesuai.\n");
        } else {
            if (nominal > total_bayar) {
                printf("Kembalian: Rp %d\n", nominal - total_bayar);
            }
            printf("Pembayaran berhasil!\n");
            break;
        }
    }
    
    strcpy(pembayaran_terakhir.nama_pemesan, nama_pemesan);
    pembayaran_terakhir.total_bayar = total_bayar;
    strcpy(pembayaran_terakhir.metode_bayar, metode);
    pembayaran_terakhir.waktu_pemesanan = time(NULL);
    
    total_pendapatan_maskapai += total_bayar;
}

void print_struk(char *nama_pemesan, int booked, int seat_rows[], int seat_cols[], 
                char bagasi_choice[], int total_price, int cls) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    printf("\n");
    printf("========================================================\n");
    printf("=                      STRUK PEMESANAN                 =\n");
    printf("========================================================\n");
    printf("Nama Pemesan       : %s\n", nama_pemesan);
    printf("Banyak Pemesanan   : %d tiket\n", booked);
    printf("Kelas Penerbangan  : %s\n", 
           cls == 1 ? "First Class" : cls == 2 ? "Business Class" : "Economy Class");
    printf("Waktu Pemesanan    : %02d-%02d-%04d %02d:%02d:%02d\n",
           t->tm_mday, t->tm_mon+1, t->tm_year+1900,
           t->tm_hour, t->tm_min, t->tm_sec);
    
    printf("--------------------------------------------------------\n");
    printf("DETAIL KURSI:\n");
    
    for (int i = 0; i < booked; i++) {
        int r = seat_rows[i], c = seat_cols[i];
        int clsrow = class_of_row(r+1);
        int p = price_of_class(clsrow);
        int extra = 0;
        char bag = bagasi_choice[i];
        
        if (bag == 'A') extra = bagasi_A;
        else if (bag == 'B') extra = bagasi_B;
        else if (bag == 'C') extra = bagasi_C;
        
        printf(" - Kursi %d%c | Harga: Rp %d | Bagasi: %c (Rp %d)\n",
               r+1, SEAT_LABELS[c], p, (bag=='0' ? '-' : bag), extra);
    }
    
    printf("--------------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN   : Rp %d\n", total_price);
    printf("========================================================\n");
    printf("=  TERIMA KASIH TELAH MEMESAN TIKET PESAWAT UNTAR AIR  =\n");
    printf("========================================================\n");
}

void booking_flow() {
    char nama_pemesan[100];
    int qty;
    
    while(getchar()!='\n');
    printf("Masukkan Nama Pemesan: ");
    fgets(nama_pemesan, sizeof(nama_pemesan), stdin);
    nama_pemesan[strcspn(nama_pemesan, "\n")] = 0;
    
    printf("Berapa banyak tiket yang ingin dipesan? ");
    if (scanf("%d", &qty) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }
    if (qty <= 0) { printf("Jumlah tiket harus > 0.\n"); return; }
    
    printf("Pilih kelas (1 = First Class, 2 = Business Class, 3 = Economy Class): ");
    int cls; 
    if (scanf("%d", &cls) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }
    if (cls < 1 || cls > 3) { printf("Kelas tidak valid.\n"); return; }

    int available = count_empty_in_class(cls);
    if (qty > available) { 
        printf("Error: Jumlah tiket (%d) lebih besar dari kursi kosong pada kelas ini (%d).\n", qty, available); 
        return; 
    }

    int booked = 0;
    int total_price = 0;
    int seat_rows[ROWS], seat_cols[ROWS];
    char bagasi_choice[ROWS];
    
    for (int i = 0; i < qty; i++) {
        int row; char schar;
        printf("Masukkan data tiket ke-%d\n", i+1);
        printf(" - Nomor baris: ");
        if (scanf("%d", &row) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); i--; continue; }
        printf(" - Huruf kursi (A-F): ");
        while ((schar = getchar()) == '\n' || schar == '\r');
        while (getchar()!='\n');
        int col = seat_index_from_letter(schar);
        if (row < 1 || row > ROWS || col < 0 || col >= COLS) { 
            printf("Baris atau huruf kursi tidak valid.\n"); i--; continue; 
        }
        if (class_of_row(row) != cls) { 
            printf("Baris %d tidak sesuai dengan kelas yang dipilih.\n", row); i--; continue; 
        }
        if (seats[row-1][col] != EMPTY_SEAT) { 
            printf("Kursi %d%c sudah terisi.\n", row, toupper(schar)); i--; continue; 
        }

        printf("Apakah ingin menambah bagasi? (0=tidak, A=0-5kg, B=>5-10kg, C=>10-20kg): ");
        char bag = '\0';
        char temp;
        while ((temp = getchar()) == '\n' || temp == '\r');
        bag = toupper((unsigned char)temp);
        while (getchar()!='\n');
        int extra = 0;
        if (bag == 'A') extra = bagasi_A;
        else if (bag == 'B') extra = bagasi_B;
        else if (bag == 'C') extra = bagasi_C;
        else if (bag == '0' || bag == 'N') { bag = '0'; extra = 0; }
        else { 
            printf("Pilihan bagasi tidak dikenali, dianggap tanpa bagasi.\n");
            bag = '0';
            extra = 0;
        }

        seat_rows[booked] = row-1;
        seat_cols[booked] = col;
        bagasi_choice[booked] = bag;
        total_price += price_of_class(cls) + extra;
        booked++;
    }

    printf("Konfirmasi pemesanan %d tiket? (Y/N): ", booked);
    char conf;
    while ((conf = getchar()) == '\n' || conf == '\r');
    while (getchar()!='\n');
    if (toupper((unsigned char)conf) != 'Y') {
        printf("Pemesanan dibatalkan.\n");
        return;
    }

    process_payment(total_price, nama_pemesan);

    for (int i = 0; i < booked; i++) {
        int r = seat_rows[i], c = seat_cols[i];
        char bag = bagasi_choice[i];
        if (bag == 'A' || bag == 'B' || bag == 'C') seats[r][c] = bag;
        else seats[r][c] = BOOKED_SEAT;
    }
    save_seats_to_file();

    print_struk(nama_pemesan, booked, seat_rows, seat_cols, bagasi_choice, total_price, cls);
    
    printf("\nPemesanan berhasil! Kembali ke menu utama...\n");
}

void cancel_booking() {
    int row; char seatchar;
    printf("Masukkan nomor baris untuk dibatalkan: ");
    if (scanf("%d", &row) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }
    printf("Masukkan huruf kursi (A-F): ");
    while ((seatchar = getchar()) == '\n' || seatchar == '\r');
    while (getchar()!='\n');
    int col = seat_index_from_letter(seatchar);
    if (row < 1 || row > ROWS || col < 0 || col >= COLS) {
        printf("Baris atau huruf kursi tidak valid.\n"); return;
    }
    if (seats[row-1][col] == EMPTY_SEAT) {
        printf("Kursi %d%c kosong, pembatalan tidak dapat dilakukan.\n", row, toupper(seatchar)); return;
    }
    
    int cls = class_of_row(row);
    int harga_kursi = price_of_class(cls);
    int harga_bagasi = 0;
    char status = seats[row-1][col];
    if (status == 'A') harga_bagasi = bagasi_A;
    else if (status == 'B') harga_bagasi = bagasi_B;
    else if (status == 'C') harga_bagasi = bagasi_C;
    int total_refund = harga_kursi + harga_bagasi;
    
    printf("Konfirmasi pembatalan kursi %d%c ? (Y/N): ", row, toupper(seatchar));
    char conf;
    while ((conf = getchar()) == '\n' || conf == '\r');
    while (getchar()!='\n');
    if (toupper((unsigned char)conf) == 'Y') {
        seats[row-1][col] = EMPTY_SEAT;
        save_seats_to_file();
        
        total_pendapatan_maskapai -= total_refund;
        
        printf("\n=== PEMBATALAN BERHASIL ===\n");
        printf("Rp. %d telah dikembalikan dengan metode %s\n", 
               total_refund, pembayaran_terakhir.metode_bayar);
        printf("Kursi %d%c berhasil dibatalkan.\n", row, toupper(seatchar));
        
        printf("\nDenah kursi terkini setelah pembatalan:\n");
        display_seating_chart();
    } else {
        printf("Pembatalan dibatalkan.\n");
    }
}

void statistics_and_revenue() {
    int total = ROWS * COLS;
    int kosong = 0, terisi = 0;
    int class_total[4] = {0,0,0,0};
    int class_filled[4] = {0,0,0,0};

    for (int r=0;r<ROWS;r++) {
        int cls = class_of_row(r+1);
        for (int c=0;c<COLS;c++) {
            class_total[cls]++;
            char s = seats[r][c];
            if (s == EMPTY_SEAT) { kosong++; }
            else {
                terisi++;
                class_filled[cls]++;
            }
        }
    }

    printf("\n==== Statistik Kursi & Pendapatan ====\n");
    printf("Total kursi: %d\n", total);
    printf("Kursi kosong: %d\n", kosong);
    printf("Kursi terisi: %d\n", terisi);
    for (int cls=1; cls<=3; cls++) {
        double perc = (class_total[cls] == 0) ? 0.0 : ((double)class_filled[cls] / class_total[cls]) * 100.0;
        printf(" - Kelas %s: %d / %d terisi (%.2f%%)\n", 
               (cls==1?"Utama (First)":(cls==2?"Bisnis (Business)":"Ekonomi (Economy)")), 
               class_filled[cls], class_total[cls], perc);
    }
    printf("Total pendapatan saat ini: Rp %lld\n", total_pendapatan_maskapai);
    printf("------------------------------------------------------\n");
}

void reset_data() {
    char user[64], pass[64];
    printf("Login admin untuk reset data.\nUsername: ");
    if (scanf("%63s", user) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }
    printf("Password: ");
    if (scanf("%63s", pass) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); return; }

    if (strcmp(user, ADMIN_USER) == 0 && strcmp(pass, ADMIN_PASS) == 0) {
        long long pendapatan_sebelum = total_pendapatan_maskapai;
        
        for (int r=0;r<ROWS;r++)
            for (int c=0;c<COLS;c++)
                seats[r][c] = EMPTY_SEAT;
        save_seats_to_file();
        
        total_pendapatan_maskapai = 0;
        
        printf("\n=== RESET DATA BERHASIL ===\n");
        printf("Pendapatan sebelum reset: Rp %lld\n", pendapatan_sebelum);
        printf("Pendapatan setelah reset: Rp %lld\n", total_pendapatan_maskapai);
        printf("Semua data kursi telah direset.\n");
        
        printf("\nDenah kursi terkini setelah reset:\n");
        display_seating_chart();
    } else {
        printf("Login admin gagal.\n");
    }
}

void print_menu() {
    printf("\n======================================================\n");
    printf("=                   Maskapai UNTAR AIR               =\n");
    printf("======================================================\n");
    printf("1. Tampilkan seluruh denah kursi\n");
    printf("2. Mencari info kursi tertentu\n");
    printf("3. Pemesanan Kursi\n");
    printf("   a. Membatalkan Pemesanan\n");
    printf("   b. Rekomendasi Kursi Terbaik\n");
    printf("   c. Statistik Kursi & Total Pendapatan\n");
    printf("4. Reset Data (admin)\n");
    printf("5. Keluar\n");
    printf("Pilih (angka 1-5 atau huruf sub-menu): ");
}

int main() {
    printf("==============================================================================================\n");
    printf("=                         Pemesanan Tiket Pesawat Maskapai UNTAR AIR                         =\n");
    printf("=  Kel 6 | Felicia Rivera (825250003), Gabriella Tan (825250001), Jolin Vioenty (825250025)  =\n");
    printf("==============================================================================================\n");
    printf("Hai, Selamat datang di UNTAR AIR! Yuk, pesan tiket pesawatmu sekarang melalui menu dibawah ini.\n");
    initialize_defaults_files();
    load_seats_from_file();

    for (int r=0;r<ROWS;r++) {
        int cls = class_of_row(r+1);
        for (int c=0;c<COLS;c++) {
            char s = seats[r][c];
            if (s != EMPTY_SEAT) {
                total_pendapatan_maskapai += price_of_class(cls);
                if (s == 'A') total_pendapatan_maskapai += bagasi_A;
                else if (s == 'B') total_pendapatan_maskapai += bagasi_B;
                else if (s == 'C') total_pendapatan_maskapai += bagasi_C;
            }
        }
    }

    int running = 1;
    while (running) {
        print_menu();
        char choice;
        while ((choice = getchar()) == '\n' || choice == '\r');
        while (getchar()!='\n');
        
        if (choice == '1') display_seating_chart();
        else if (choice == '2') search_seat_info();
        else if (choice == '3') booking_flow();
        else if (choice == '4') reset_data();
        else if (choice == '5') { printf("Terima Kasih telah berkunjung ke program maskapai UNTAR AIR!\n"); running = 0; }
        else if (choice == 'a' || choice == 'A') cancel_booking();
        else if (choice == 'b' || choice == 'B') {
            int cls, qty;
            printf("Masukkan kelas pilihan (1=First,2=Business,3=Economy): ");
            if (scanf("%d", &cls) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); continue; }
            printf("Berapa banyak kursi yang ingin direkomendasikan? ");
            if (scanf("%d", &qty) != 1) { while(getchar()!='\n'); printf("Input salah.\n"); continue; }
            while(getchar()!='\n');
            if (cls < 1 || cls > 3) { printf("Kelas tidak valid.\n"); continue; }
            recommend_seats(cls, qty);
        }
        else if (choice == 'c' || choice == 'C') statistics_and_revenue();
        else {
            printf("Pilihan tidak dikenal. Mohon pilih menu yang tersedia.\n");
        }
    }

    return 0;
}