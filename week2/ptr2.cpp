#include <stdio.h>

int main(){
    // float *pu 
    int *pu; // Karena sebelumnya float, dan address dari int tidak bisa di ambil oleh pointer float 
    float nu;

    int u = 1234;

    pu = &u; // Pointer pu di assign oleh alamat dari u

    nu = *pu; // Variable float nu di assign oleh alamat yang ditunjuk oleh pointer pu ke variable int u  sehingga nu

    printf("u = %d\n", u);
    printf("nu = %f\n", nu); 
    return 0;
}