#include <stdio.h>

int main(){

    char nama[5];
    nama[0] = 'a';
    nama[1] = 'y';
    nama[2] = 'a';
    nama[3] = 'm';
    nama[4] = 'm';

    char *p;
    p = nama;

    printf("%p", p);
    return 0;
}