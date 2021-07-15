#include <stdio.h>

void valor (int x)
{
    printf("Valor antes dentro da função: %d\n", x);
    
    x = 10;

    printf("Valor depois dentro da função %d\n", x);
}

int main()
{
    int x = 5;
    
    valor(x);

    printf("Valor depois fora da função: %d\n", x);

    return 0;
}