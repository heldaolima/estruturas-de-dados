#include <stdio.h>

void ImprimeVetor(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void InsertionSort(int a[], int n) //O(n^2)
{
    int value, hole;
    for (int i = 0; i < n; i++) //n
    {
        value = a[i];
        hole = i;
        while (hole > 0 && a[hole - 1] > value) //n
        {
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
    }  

/*
{7, 2, 4, 1, 5, 3}

i = 1, v = 2, h = 1
entra no while: h != 0 e v[h-1] == 7 > 2
{
    a[1] = 7;
    {7, 7, 4, 1, 5, 3}
    h--;
    (sai do while)
}
a[0] = 2
{2, 7, 4, 1, 5, 3}

e assim vai
v[h-1] > v isso é pra saber onde parar no subarray ordenado
*/
}

int main()
{
    int a[] = {7, 2, 4, 1, 5, 3};
    
    ImprimeVetor(a, 6);

    InsertionSort(a, 6);

    ImprimeVetor(a, 6);

    return 0;
}

/*
int a[] = {7, 2, 4, 1, 5, 3};
dividir o array em dois subsets, um ordenado e outro desordenado
ex:

7| 2 4 1 5 3

a parte ordenada começa em 7; um elemento sozinho está ordenado

agora anda pelo resto e insere na parte ordenada

pega 2, compara com 7 e coloa la
aux = 2
coloque todos os numeros maiores do que 7 uma posição à frente
e insira 2 na posição 0

2 7 | 4 1 5 3

o mesmo com o 4. Coloca o 7 pra frente e insere o 4 entre ele e o 2

2 4 7 | 1 5 3

e assim vai
*/