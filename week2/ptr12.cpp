#include <stdio.h>

/* Kamus Global */
int N; /* ukuran efektif */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succ (int *i); /* suksessor, berupa procedure by ref */
void pred (int *i); /* predesessor */
/* Prosedur dengan parameter sebuah fungsi */
void geser (int *TT, void (*f) (int *));
/* Program Utama */

int main()
{
    /* kamus lokal */
    int MyTab[10];
    int i;
    /* program */
    N = 10;
    for (i = 0; i < N; i++)
    {
        MyTab[i] = i;
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");

    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n");
    geser (MyTab, succ);
    printf(" dalam main \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");
    
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n");
    geser (MyTab, pred);
    printf(" dalam main setelah aplikasi pred \n");
    for (i = 0; i < N; i++)
    {
        printf(" %d ", MyTab[i]);
    }
    printf("\n");
    return 0;
}
/* Body Function */

void succ (int *i) // Mengirim alamat variable ke prosedure
{
*i = *i+1;
}

void pred (int *i) // Mengirim alamat variable ke prosedur
{
*i = *i-1;
}

void geser (int *TT, void (*f) (int *))
{

int i;
printf(" dalam geser \n");
for (i = 0; i < N; i++)

{
f (&TT[i]);
printf(" %d ", TT[i]);
}
printf("\n");
}

/*README
Perbedaan file ini dengan yang sebelumnya adalah metode disini yaitu modul geser yang parameternya prosedur by reference yang mana pointernya
mengambil nilai dari MyTab yang diarahkan oleh pointer *TT
*/