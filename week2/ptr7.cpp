#include <stdio.h>
#include <stdlib.h>

int main(){
    char *pkota = "bandung"; // Pointer ke string literal (read only)
    char kota[] = "bandung"; // string yang dapat dimodifikasi (char yang ditumpuk di array)
    puts(pkota);
    printf("%s", kota);
    return 0;
}