#include <stdio.h>

int main(){
    float d, *pd; 

    d = 54.5;

    printf("isi d semula = %g\n",d);

    pd = &d; // pointer pd di assign oleh address variable d
    *pd = *pd + 10; // operasi yang dilakukan oleh pointer pd yang mengarahkan kepada value d sehingga nilai d berubah.

    printf("isi d kini = %g\n", d); // isi d kini akan berubah menjadi 64.5 karena operasi yang dilakukan oleh pointer pd.
    return 0;
}