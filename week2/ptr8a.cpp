#include <stdio.h>
#include <string.h> // Library string
#define PANJANG 20 // Menggunakan define untuk konstanta


int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char nama1[PANJANG] = "DEWI SARTIKA"; 
    char nama2[PANJANG] = "SULTAN HASANUDDIN";
    char namaX[PANJANG]; 
    /* semua char disini memiliki ukuran sebanyak PANJANG yang telah di define di atas yaitu sebanyak 20
    sehingga jumlah elemen dari array char diatas adalah 20*/
    puts("Nama semula : ");
    printf("Nama 1 --> %s\n", nama1);
    printf("Nama 2 --> %s\n", nama2);
    /* Pertukaran string */
    /* funtion strcpy adalah function yang berfungsi untuk mengcopy string */
    strcpy(namaX, nama1); // Mengcopy isi string dari nama1 ke namaX 
    strcpy(nama1, nama2); // Mengcopy isi string dari nama2 ke nama1
    strcpy(nama2, namaX); // Mengcopy isi string dari namaX ke nama2
    puts("Nama sekarang : ");
    printf("Nama 1 --> %s\n", nama1);
    printf("Nama 2 --> %s\n", nama2);
return 0;
}