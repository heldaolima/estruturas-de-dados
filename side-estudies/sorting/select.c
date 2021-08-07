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

void SelectionSort(int a[], int n)
{
    int iMin;
    for (int i = 0; i < n-1; i++) //até o penúltimo elemento, pois o último estará no lugar certo
    {
        iMin = i; //o minimo começa com i
        for (int j = i+1; j < n; j++) //começa no numero seguinte a i
        {
            if (a[j] < a[iMin])
                iMin = j; //achei um menor, coloco o seu indice na variável
        }
        Swap(&a[i], &a[iMin]); //troca o ith pelo menor que encontramos
    }
}

//selection sort
int main()
{
    int a[]= {2, 7, 4, 1, 5, 3};
    ImprimeVetor(a, 6);

    SelectionSort(a, 6);

    ImprimeVetor(a, 6);

    return 0;
}

/*
A = {2 7 4 1 5 3}

acha o mínimo [1]
e troca com o primeiro indice
A = {1, 7, 4, 2, 5, 3}

Proximo minimo, depois de 1 -> 2
Troca com o segundo indice
A = {1, 2, 4, 7, 5, 3}
E assim vai, até que
A = {1, 2, 3, 4, 5, 7}
*/