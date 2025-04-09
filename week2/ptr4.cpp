#include <stdio.h>

int main(){
    int z, s, *pz, *ps;

    z = 20;
    s = 30;

    pz = &z; // pz di assign oleh alamat dari variable z
    ps = &s; // ps di assign oleh alamat dari variable s

    // pz menunjuk ke nilai z = 20, ps menunjuk ke nilai s = 30
    *pz = *pz + *ps; //operasi yang dilakukan adalah pointer yang menunjuk nilai sehingga mengubah nilai ke z dan s tetap

    printf("z = %d\n s = %d\n", z, s);
    return 0;
}