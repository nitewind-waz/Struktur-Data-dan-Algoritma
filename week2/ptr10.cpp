#include <stdio.h>
/* Prototype */
void f1(void);
void f2(void);
void f3(void);
void f4(void);

/* kamus Global */
#define true 1
#define false 0
int quit = false;


int main()
{
/* kamus lokal */
/* Definisi tabel yang elemennya adalah pointer ke fungsi */
/* Elemen tabel yang ke - i akan mengakses fungsi ke - i */
/* Pilihan menjadi indeks tabel, dan dipakai untuk mengaktifkan fungsi */
/* yang sesuai */
    void (*tab[4]) () = {f1, f2, f3, f4}; /*Deklarasi pointer ke procedure */
    // Array tab berisi pointer ke fungsi, di mana setiap elemen mengarah ke fungsi yang sesuai (f1, f2, f3, f4).

    /* program */
    printf("%p\n",tab[1]);
    printf("%p", &f2);
    printf("Pointer to function : \n");
    /* Menu */
    do
    {
    printf("Pilih salah satu : \n");
    printf("1. Buka file hanya untuk baca \n");
    printf("2. Tutup file \n");
    printf("3. Edit file \n");
    printf("4. Quit \n");
    tab[getchar() - '1'] () ; // Input untuk mengarah ke fungsi tsb
    getchar(); /* untuk membuang return karakter */
    } while (!quit);
    return 0;
}
/* Body Function */
void f1 ()
{
    printf("Ini fungsi f1 \n");
}

void f2 ()
{
    printf("Ini fungsi f2 \n");
}
void f3 ()
{
    printf("Ini fungsi f3 \n");
}
void f4 ()
{
    quit = true;
    printf("Quit ... \n");
}