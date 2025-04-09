/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	 return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	
	 return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = Alokasi(X);
	if (P != NULL) {
		Next(P) = First(*L);
		First(*L) = P;
	}
	
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsVLast (List *L, infotype X)
/* IS : L mungkin kosong */
/* FS : Menambahkan elemen X di akhir list jika alokasi berhasil */
{
    /* Kamus Lokal */
    address P, temp;

    /* Algoritma */
    P = Alokasi(X); 
    if (P != NULL) { 
        Next(P) = NULL; 
        
        if (First(*L) == NULL) { 
            First(*L) = P; 
        } else {
            temp = First(*L);
            while (Next(temp) != NULL) { 
                temp = Next(temp);
            }
            Next(temp) = P; 
        }
    }
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	if (First(*L) != Nil)
	{
		P = First(*L);
		First(*L) = Next(P);
		*X = Info(P);
		Next(P) = Nil;
		DeAlokasi (P);
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVLast (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel, prec;
	 /* Algoritma */
	if (First(*L) != Nil)
	{
		PDel = First(*L);
		if (Next(PDel) == Nil)
		{
			*X = Info(PDel);
			First(*L) = Nil;
			DeAlokasi(PDel);
		} else 
		{
			prec = Nil;
			while (Next(PDel) != Nil)
			{
				prec = PDel;
				PDel = Next(PDel);
			}
			Next(prec) = Nil;
			*X = Info(PDel);
		}
		DeAlokasi(PDel);
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (P != Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	
    if (P != NULL && Prec != NULL) {
        Next(P) = Next(Prec); // P menunjuk ke elemen setelah Prec
        Next(Prec) = P; // Prec menunjuk ke P sebagai elemen berikutnya
    }
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	 Last = First(*L);
	 while (Next(Last) != Nil)
	 {
		Last = Next(Last);
	 }
	 Next(Last) = P;
	 Next(P) = Nil;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	First(*L) = Next(*P);
	Next(*P) = Nil;
}


void DelP (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 
	 /* Algoritma */
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	*P = First(*L);
		while (Next(*P) != Nil)
		{
			Prec = (*P);
			(*P) = Next(*P);
		}
		Next(Prec) = Nil;
		(*P) = Prec;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
    if (Prec != Nil && Next(Prec) != Nil) { 
        *Pdel = Next(Prec); 
        Next(Prec) = Next(*Pdel); 
        Next(*Pdel) = Nil;
    }
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	 P = First(L);
	if (ListEmpty(L)){
		printf("List Kosong\n");
	} 
	else 
	{
		while ((P) != Nil)
		{
			printf("%d->", Info(P));
			P = Next(P);
		}
		printf("Nil\n");
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	 PDel = First(*L);
	 DeAlokasi(PDel);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}



