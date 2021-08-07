#include <stdio.h>

void ImprimeVetor(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Swap(int* a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void BubbleSort(int a[], int n)
{
    for (int k = 1; k < n; k++) //aqui são as passadas pelo array
    {
        // printf("k: %d  ", k);
        for (int i = 0; i < n-k; i++) //aqui é o bubble
        {
            // printf("%d \n", i);
            // printf("%d %d\n", a[i], a[i+1]);
            if (a[i] > a[i+1])
                Swap(&a[i], &a[i+1]); 
        }
        // printf("\n");
    }
}

int main()
{
    int a[] = {2, 7, 4, 1, 5, 3};
    ImprimeVetor(a, 6);

    BubbleSort(a, 6);

    ImprimeVetor(a, 6);
    return 0;
}

/*
int a[] = {2, 7, 4, 1, 5, 3};

passar de um elemento por vez, várias vezes
comparar esse elemento com o seu adjacente
se o atual for menor, swap

2 e 7
7 e 4 -> swap
2, 4, 7, 1, 5, 3
7 e 1 -> swap
2, 4, 1, 7, 5, 3
7 e 5 -> swap
2, 4, 1, 5, 7, 3
3 e 7 -> swap
2, 4, 1, 5, 3, 7

7, maior elemento, foi empurrado ao fim do array

*/
