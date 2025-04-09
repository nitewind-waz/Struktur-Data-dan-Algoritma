#include <stdlib.h>
#include <stdio.h>

/*NOTE*/
/*String tersebut tidak boleh dimodifikasi karena akan menyebabkan error*/

int main()
{
    /* kamus */
    /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
    static char *s[3] = {"the", "time", "is"};
    /* Definisi array yang elemennya string, dinamik */
    char *(*TabStr); /* Deklarasi array of string */
    int i;

    /* program */
    for (i=0; i < 3; i++) { //cetak isi s
        printf("%s\n", s[i]);
    }
    /* Alokasi TabStr sebanyak 3 */
    TabStr = (char **) malloc (3 * sizeof(char *)); // Ngealokasiin array of string
    for (i=0; i < 3; i++) {
        /* Alokasi string yang merupakan elemen tabel */
        *(TabStr + i) = (char *) malloc (5 * sizeof(char)); // Ngealokasiin maksimum dari isi string
        printf("\nInput Str[%d], maksimum 5 karakter : ", i);
        scanf("%5s", *(TabStr+i)); /* Mengisi nilai string */
        printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i));
}
return 0;
}