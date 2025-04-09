#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989};
    int *ptgl;

    ptgl = tgl_lahir; // pointer di  assign oleh variable tgl_lahir

    printf("Nilai yang ditunjuk oleh ptgl = %d/%d/%d\n", *ptgl, *(ptgl + 1), *(ptgl + 2)); //cara mengakses indeks setelahnya menggunakan pointer yaitu dengan (pointer + (nilai))
    printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);
    return 0;
}