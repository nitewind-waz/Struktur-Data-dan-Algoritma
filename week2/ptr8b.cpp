#include <stdio.h>


int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char *nama1 = "DEWI SARTIKA";
char *nama2 = "SULTAN HASANUDDIN";
char *namaX;
puts("Nama semula : ");
printf("Nama 1 --> %s\n", nama1);
printf("Nama 2 --> %s\n", nama2);
/* Penukaran string yang ditunjuk oleh pointer nama1 dan nama2 */

// Pertukaran disini tidak memerlukan function-function dari library string.h seperti strcpy()
namaX = nama1;
nama1 = nama2;
nama2 = namaX;

puts("Nama sekarang : ");
printf("Nama 1 --> %s\n", nama1);
printf("Nama 2 --> %s\n", nama2);
return 0;
}
/* -------------------------------------------------- */
/* File Program : PTR9.CPP */
/* Deskripsi : pointer yang menunjuk pointer */
/* -------------------------------------------------- */
#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
int var_x = 273;
int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
/* (Boleh disebut pointer integer saja) */
int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
/* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer

saja) */
ptr1 = &var_x;
ptr2 = &ptr1;
/* Mengakses nilai var_x melalui ptr1 dan ptr2 */
printf("Nilai var_x = %d\n", *ptr1);
printf("Nilai var_x = %d\n", **ptr2);
return 0;
}