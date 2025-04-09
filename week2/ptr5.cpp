#include <stdlib.h>
#include <stdio.h>

int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int i = 5, j;
    char c = 'X';
    int *Ptri = (int *) malloc(4); // Deklarasi pointer ptri sekaligus alokasi memori sebanyak 4 byte menggunakan function malloc()
    int *Ptrj = (int *) malloc(sizeof(int)); // Deklarasi pointer ptrj sekaligus alokasi memori sebanyak ukuran dari integer
    float *fx = (float *) malloc(sizeof(float)); // Deklarasi pointer  fx sekaligus alokasi memori sebanyak ukuran dari float
    int A[5];
    float f = 7.23;

/* Program */
    *Ptri = 8; // Memasukan nilai oleh pointer ke alamat dari ptri
    *Ptrj = 0;// Memasukan nilai oleh poinnter ke alamat yang ditunjuk oleh Ptrj 
    *fx = 3; // Memasukan nilai oleh pointer ke alamat yang ditunjuk oleh fx
    printf("Alamat i = %x \n", &i);
    printf("Nilai i = %d \n", i);
    printf("Ukuran int = %d byte\n\n", sizeof(int));
    printf("Alamat j = %x \n", &j);
    printf("Nilai j = %d \n", j);
    printf("Alamat c = %x \n", &c);
    printf("Nilai c = %c \n", c);
    printf("Ukuran char = %d byte\n\n", sizeof(char));

    printf("Alamat Ptri = %x \n", &Ptri);
    printf("Isi var Ptri = %x \n", Ptri);
    printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
    printf("Ukuran pointer int = %d byte\n\n", sizeof(int *));
    printf("Alamat Ptrj = %x \n", &Ptrj);
    printf("Isi var Ptrj = %x \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);
    Ptrj = Ptri; // Ptrj di assign oleh Ptri sehingga ptrj sama menunjuk seperti ptri
    printf("Isi var Ptrj sekarang = %x \n", Ptrj);
    printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);
    printf("Alamat A = %x \n", &A);
    printf("Isi var A = %x \n", A[0]);
    printf("Ukuran array A = %d byte\n\n", sizeof(A));
    printf("Alamat f = %x \n", &f);
    printf("Nilai f = %f \n", f);
    printf("Ukuran float = %d byte\n\n", sizeof(float));

return 0;
}