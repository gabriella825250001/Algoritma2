 #include <stdio.h>

 int main (){
    int panjang;
    int lebar;
    float hasil;
    float keliling;

    printf("hitung persegi \n\n");
    printf("masukan panjang: ");
    scanf("%d", &panjang);
    printf("masukan lebar: ");
    scanf("%d", &lebar);

    hasil = panjang * lebar;
    printf("Luasnya adalah: %.2f\n" ,hasil);
    
    keliling = 2 * (panjang + lebar);
    printf("kelilingnya adalah: %.2f" ,keliling);
 }