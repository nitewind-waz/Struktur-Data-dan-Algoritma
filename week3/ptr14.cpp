/* ---------------------------------------------------------------------------------------------- */
/* File Program : PTR14.CPP */
/* Deskripsi : Array dinamis, dimana ukuran array ditentukan dari read keyboard */
/* ---------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    
    int *tab; /* deklarasi array, perhatikan belum tampak bedanya dg
    deklarasi pointer biasa */

    int N, i;
    /* program */
    printf("Contoh mengisi array dinamis berukuran 0..N : \n");
    printf("N = ");
    scanf("%d", &N);
    printf("Alokasi setelah mengetahui ukuran array \n");
    tab = (int *) malloc((N+1) *sizeof(int)); // Mengalokasikan ruang sebanyak N elemen ke memori

    // Jika N = 4, maka membutuhkan 20 Byte memori karena integer biasanya = 4byte
    
    if (tab != NULL)
    {
        for (i=0; i<=N; i++)
        {
        printf("i=%d tab[i]=%d \n", i, *(tab + i)); // Mengeluarkan output dari nilai yang diarahkan oleh tab dan berisi nilai sembarang
        }   ;
        printf("Akhir program \n");
    /* dealloc */
        free(tab); /*dealokasi*/
        return 0;
    }
    else
    {
        printf("Alokasi gagal ... \n");
        return 1;
    }
return 0;
}