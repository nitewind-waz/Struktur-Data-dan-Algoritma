#include <stdio.h>

int main(){
    int x,y;
    int *px; // Deklarasi pointer

    x = 87;
    px = &x; // Memasukkan alamat x ke pointer
    
    y = *px; // y di assign oleh pointer yang mengarah ke nilai x

    printf("nilai x : %d\n", x);
    printf("address x : %d\n", &x);
    printf("nilai yang ditunjuk oleh pointer px : %d\n", *px);
    printf("nilai y : %d\n", y);



    return 0;
}
