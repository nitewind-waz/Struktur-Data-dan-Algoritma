#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING char

typedef struct Nama *address;
typedef struct  Nama {
   STRING orang[10];
   address next;

}ListName;

void printList(address Head) {
    address temp = Head;  // Mulai dari Head
    printf("Isi Linked List:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->orang);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    address Head;
    address A, B, C;

    Head = NULL;

    A = (address) malloc(sizeof(ListName));  // Alokasi memori sebesar node
    strcpy(A->orang, "Sinta");
    A->next = NULL;
    Head = A;

    B = (address) malloc(sizeof(ListName));  // Alokasi memori sebesar node
    strcpy(B->orang, "Ridho");
    B->next = NULL;
    B->next = Head;
    Head = B;

    C = (address) malloc(sizeof(ListName));  // Alokasi memori sebesar node
    strcpy(C->orang, "Reza");
    C->next = NULL;
    C->next = Head;
    Head = C;

    printList(Head);

    free(A);
    free(B);
    free(C);

    return 0;
}