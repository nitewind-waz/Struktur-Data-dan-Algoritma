#include <stdio.h>
#include <stdlib.h>

typedef struct People {
    char nama[10];
    struct People *next;
} People;

int main(){
    People Antrian[5]{ // Membuat array dari struct people
        {"Reza", NULL}, 
        {"Ridho", NULL}, 
        {"Sinta", NULL}, 
        {"", NULL}, 
        {"Jojo", NULL}, 
    };

    People *Head = &Antrian[1];

    Head->next = &Antrian[0];
    Head->next->next = &Antrian[2];
    Head->next->next->next = &Antrian[4];
    Head->next->next->next->next = &Antrian[3]; 

    while (Head != NULL)
    {
        printf("%s\n", Head->nama);
        Head = Head->next;
    }
    return 0;
}