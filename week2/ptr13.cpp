#include <stdio.h>


int N; /* ukuran efektif */


enum MyType
{
bulat, karakter
};
#include <stdio.h>
#include <stdlib.h>

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI (int *i); /* suksessor, berupa procedure by ref */
void predI (int *i); /* predesessor */
void succC (char *c); /* suksessor, berupa procedure by ref */
void predC (char *c); /* predesessor */
/* print tabel yang belum ketahuan typenya */
void printtab (void *T, enum MyType Ty);
/* Prosedur dengan parameter sebuah fungsi */
// prosedur ini memiliki kemampuan static dispacth.  
// https://en.wikipedia.org/wiki/Static_dispatch

// void geser (void *TT, void (*f) (void *), size_t size);

// alternatif deklarasi

typedef void (*GeserParams)(void *);
void geser (void *TT, GeserParams f, size_t size);


/* Program Utama */
// 29:37
int main()
{
    /* kamus lokal */
    int *MyTabInt;
    char *MyTabC;
    int i;
    /* program */
    N = 10;
    MyTabInt = (int *) malloc (N * sizeof(int));
    MyTabC = (char *) malloc (N * sizeof(char));
    *MyTabInt = 1;
    for (i = 0; i < N; i++)
    {
        *(MyTabInt + i) = i;
        *(MyTabC + i) = 'Z';
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    printf(" Tabel integer \n");
    printtab ((int *) MyTabInt, 0);
    printf(" Tabel charakter \n");
    printtab ((char *) MyTabC, 1);
    printf("\n");

    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n");
    geser ((int *) MyTabInt, (int *) succI, sizeof(int));
    geser ((char *) MyTabC, (char *) succC, sizeof(char));
    printf(" dalam main \n");
    printf(" Tabel integer \n");
    printtab ((int *) MyTabInt, 0);
    printf(" Tabel charakter \n");
    printtab ((char *) MyTabC, 1);
    printf("\n");
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n");
    geser ((int *) MyTabInt, (int *) predI, sizeof(int));
    geser ((char *) MyTabC, (char *) predC, sizeof(char));
    printf(" dalam main \n");
    printf(" Tabel integer \n");
    printtab ((int *) MyTabInt, 0);
    printf(" Tabel charakter \n");
    printtab ((char *) MyTabC, 1);
    printf("\n");
    return 0;
}
/* Body Function */
void succI (int *i)
{
    *i = *i+1;
}
void predI (int *i)
{
    *i = *i-1;
}
void succC (char *c)
{
    *c = *c+1;
}
void predC (char *c)
{
    *c = *c-1;
}

// void geser (void *TT, void (*f) (void *), size_t size)
// alternatif deklarasi
void geser (void *TT, GeserParams f, size_t size)
{
    int i;
    char *CC = TT;
    int *II = TT;
    printf(" dalam geser, memindahkan %d byte\n", size);
    if(size == sizeof(char)) {
        for (i = 0; i < N; i++)
        {
            f (&CC[i]);
            printf(" %c ", CC[i]);
            
        }
    }else {
        for (i = 0; i < N; i++)
        {
            f (&II[i]);
            printf(" %d ", II[i]);
            
        }
    }
    printf("\n");
}

void printtab (void *T, enum MyType Ty)
{
    int i;
    for (i = 0; i < N; i ++)
    {
        switch (Ty)
        {
        case bulat : printf("%d ",  *(((int *)T) + i)); break;
        case karakter : printf("%c ", *(((char *) T) + i)); break;
        }
    }
}

//Program ini memiliki problem yaitu incompatible pointer type
// Secara keseluruhan saya paham, tetapi errornya ini yang membuat saya pusing.