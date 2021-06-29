#include <iostream>
#include <cstdlib>
#include <ctime>


char vitoria(char tab[][3])
{
    char obj = tab[0][2];
    if (obj == 'X' || obj == 'O')
    {
        int j = 1;
        int cont = 1;
        for (int i = 1; i < 3; i++){
            
            printf("i, j: %d, %d\n", i, j);
            if (tab[i][j] == obj) cont++;
            j--;
        }
        if (cont == 3) return obj;
    }
    return 'F';
}


void imprime(char tab[][3]) //imprime o tabuleiro
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (j == 2) printf("%c\n", tab[i][j]);
            else printf("%c\t", tab[i][j]);
        }
    }
    std::cout << std::endl;
}

void init(char tab[][3]) //inicializa o tabuleiro
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf(" %c", &tab[i][j]);
        }
    }
}

int jogo(char tab[][3])
{
    imprime(tab);

    char r;
    r = vitoria(tab);
    
    return r;
}

int main()
{       
    char tab[3][3];
    
    init(tab);

    char result;

    result = jogo(tab);
    printf("result: %c\n", result); 


    return 0;
}