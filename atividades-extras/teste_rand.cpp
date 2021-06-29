#include <iostream>
#include <cstdlib>

void jogada_pc (char pc, char tab[][3])
{
    int x, y;
    int max = 3;
    srand(time(NULL));
    
    x = rand() % max;
    y = rand() % max;

    while (tab[x][y] != '*')
    {
        x = rand() % max;
        y = rand() % max;
    }

    tab[x][y] = pc;
}

void imprime(char tab[][3]) //imprime o tabuleiro
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (j == 2) printf("%c\n", tab[i][j]);
            else printf("%c\t", tab[i][j]);
        }
    }
}

void init(char tab[][3]) //inicializa o tabuleiro
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tab[i][j] = '*';
        }
    }
}


int main()
{
    char tab[3][3];
    
    init(tab);
    // imprime(tab);
    
    jogada_pc('X', tab);
    printf("\n");
    // imprime(tab);

    return 0;
}