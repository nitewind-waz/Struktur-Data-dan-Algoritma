/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi;
		address P, Prec;
		int x;

	/* Program */
	CreateList (&MyList);
	P = Alokasi(9);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	InsVFirst(&MyList, 7);
	PrintInfo (MyList);
	Prec = First(MyList);
	InsVLast(&MyList, 11);
	PrintInfo (MyList);
	InsertAfter(&MyList, P, Prec);
	PrintInfo (MyList);
	InsVFirst(&MyList, 5);
	PrintInfo (MyList);
	InsVLast(&MyList, 13);
	PrintInfo (MyList);
	DelVLast(&MyList, &isi);
	PrintInfo (MyList);
	Prec = (First(MyList));
	P = (Next(First(MyList)));
	DelAfter(&MyList, &P, Prec );
	PrintInfo (MyList);
	DelVFirst(&MyList, &isi);
	PrintInfo (MyList);
	DelAll (&MyList);
	CreateList (&MyList);
	PrintInfo (MyList);
	DelAll (&MyList);

	scanf("%d", &x);
	/* Finishing */
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

