#include <stdio.h>

int main()
{
    char antrian[3][5] = {"Rido", "Reza", "Sinta"};
    
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", antrian[i]);
    }
    return 0;
}