#include <stdio.h>
#include <stdlib.h>

void ImprimeVetor(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l +1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l+i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    i = 0; //L
    j = 0; //R
    k = l; //Merged

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
        {
            A[k] = L[i];
            i++;
            k++;
        }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        
        Merge(a, l, m, r);
    }
    //else return;
}


int main()
{
    int a[] = {2, 4, 1, 6, 8, 5, 3, 7};
    int size = sizeof(a) / sizeof(a[0]);

    ImprimeVetor(a, size);

    MergeSort(a, 0, size-1);

    ImprimeVetor(a, size);

    return 0;
}

/*
int a[] = {2, 4, 1, 6, 8, 5, 3, 7}; 8

quebrar o problema em subproblemas

> dividir em dois
L {2, 4, 1, 6}    R{8, 5, 3, 7}

fica mais simples ordenar uma e depois outra, então, feitos os processos podemos juntá-las uma na outra (merge)

imaginemo-las ordenadas: L{1, 2, 4, 6}  R{3, 5, 7, 8}

Seria ver no indice 0 qual delas tem o menor valor e colocar esse valor no indice 0 da lista principal

Merge(L, R, A)
{
    nL = len(L);
    nR = len(R);
    i = 0; //L;
    j = 0; //R;
    k = 0; //A;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j]) //se L tem o menor elemento na posiçao
        {
            A[k] = L[i];
            i++;
        }
        else{ //o da direita é menor
            A[k] = R[j];
            j++;
        }
        k++;
    }
    //isso aqui é caso o while acima cesse. Porque se eu usar todos os elementos de um array, o while tem que parar pra nao dar erro
    //como a saída do while implica que só resta elemento em uma das listas, só um dos whiles abaixo será executado. muito bom
    while (i < nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }


    AGORA OS SUBARRAYS
> dividir em dois
L {2, 4, 1, 6}    R{8, 5, 3, 7}
    
    {2, 4} {1, 6}   {8, 5} {3, 7}
    
    {2} {4} {1} {6}     {8} {5} {3} {7}

    cada lista acima está ordenada;
    Então a gente dá um merge com a lista acima! E assim sucessivamente.

    MergeSort(A[])
    {
        n = len(A);
        if (n < 2) return;

        mid = n/2;
        left[mid];
        right[n-mid]; 

        for (i = 0; i < mid; i++)
            left[i] = A[i];
        for (i = mid; i < n; i++)
            right[i-mie] = A[i];
        
        MergeSort(left); 
        MergeSort(right);
        Merge(left, right, A);


    }


}

*/