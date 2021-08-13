#include <stdio.h>

void preenche(int s, int m[][s])
{
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

int main()
{
    char VertexList[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int size = 8;

    int Edges[size][size]; //os indices estarao representados
                            //o conteudo é um bool pra dizer se há ou nao conexao 

    preenche(size, Edges);

    return 0;
}