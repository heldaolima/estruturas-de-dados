#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int vet1[5];
    int *vet2 = (int*) malloc(5 * sizeof(int))

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", vet2+i);
    }

    printf("\n\n\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Posição %d valor %d\n", i, vet2)
    }
    
    


    return 0;
}

/*
    enderço - 10105
    int var = 10

    int *p = &var  <- armazena o endereço 10105

    int v[5]; -> ponteiro que aponta para cinco espaços de memória

    

*/