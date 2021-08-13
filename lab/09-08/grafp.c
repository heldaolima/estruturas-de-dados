#include <stdio.h>

void ligacoes(int n, int adj[][n], char nos[])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
                printf("%c -> %c\n", nos[i], nos[j]);
        }
    }
}

void imprime_matriz(int n, int adj[][n])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void criar_grafo(int n, int adj[][n])
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (i == 0)
            {
                if (j == 1) adj[i][j] = 1;
                else adj[i][j] = 0;
            }
            else if (i == 1)
            {
                if (j == 0 || j == 2 || j == 3) adj[i][j] = 1;
                else adj[i][j] = 0;
            }
            else if (i == 2)
            {
                if (j == 1) adj[i][j] = 1;
                else adj[i][j] = 0;
            }
            else {
                if (j == 0 || j == 1 || j == 2) adj[i][j] = 1;
                else adj[i][j] = 0;
            }
        }
    }
}

int main()
{
    char nos[] = {'a', 'b', 'c', 'd'};

    int adj[4][4];
    criar_grafo(4, adj);
    imprime_matriz(4, adj);
    
    printf("\n\n");

    ligacoes(4, adj, nos);
    return 0;
}
