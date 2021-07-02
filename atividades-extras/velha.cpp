#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    @author Hélder Lima
*/

char velha(char tab[][3]) //confirma se houve velha (empate)
{
    int cont = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if (tab[i][j] == '*') cont++; 
        }
    }
    
    if (cont == 0) return 'V';
    else return 'F';
}

int cont_vazio(char tab[][3]) //retorna o número de espaços vazios (útil para o caso de velha)
{
    int cont = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if (tab[i][j] == '*') cont++; 
        }
    }
    
    return cont;
}

char vitoria_colunas(char tab[][3]) //analisa se vitória nas colunas
{
    for (int i = 0; i < 3; i++)
    {
        char obj = tab[0][i];
        if (obj != '*')
        {   
            int cont = 1;
            for (int j = 1; j < 3; j++)
            {
                if (tab[j][i] == obj) cont++;
            }
            if (cont == 3) return obj;
        }
    }
    return 'F';
}

char vitoria_linhas(char tab[][3]) //analisa se vitória nas linhas
{
    for (int i = 0; i < 3; i++)
    {
        char obj = tab[i][0];
        if (obj != '*')
        {
            int cont = 1;
            for  (int j = 1; j < 3; j++)
            {
                if (tab[i][j] == obj) cont++;
            }
            if (cont == 3) return obj;
        }
    }
    return 'F';
}

char vitoria_secundaria(char tab[][3]) //analisa se vitória na diagonal secundária
{
    char obj = tab[0][2];
    if (obj != '*')
    {
        int j = 1;
        int cont = 1;
        for (int i = 1; i < 3; i++){
            
            if (tab[i][j] == obj) cont++;
            j--;
        }
        if (cont == 3) return obj;
    }
    return 'F';
}

char vitoria_principal(char tab[][3]) //analisa se vitória na diagonal principal
{
    char obj = tab[0][0];
    if (obj != '*')
    {
        int cont = 1;
        for (int i = 1; i < 3; i++){
            if (tab[i][i] == obj) cont++;
            else return 'F';
        }
        if (cont == 3) return obj;
    }
    return 'F';
}

void jogada_pc (char pc, char tab[][3]) //jogada do computador (aleatória)
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
            else printf("%c  ", tab[i][j]);
        }
    }
    std::cout << std::endl;
}

void init(char tab[][3]) //inicializa o tabuleiro
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tab[i][j] = '*'; //asteriscos são espaços vazios
        }
    }
}

int jogo(char user, char pc, char tab[][3])
{
    int x, y;
    std::cout << "O tabuleiro é uma matriz 3x3, cujas posições são enumeradas de 0 a 2\nx é linha, y é coluna\n";
    std::cout << "Escolha a posição de jogada [x,y]: ";
    scanf("%d,%d", &x, &y);
    
    while (x > 2 || x < 0 || y > 2 || y < 0 || tab[x][y] != '*')
    {
        std::cout << "Jogada inválida! Escolha a posição de jogada [x,y]: ";
        scanf("%d, %d", &x, &y);
    }

    tab[x][y] = user;

    imprime(tab);

    int vazio = cont_vazio(tab);

    if (vazio > 0) jogada_pc(pc, tab);
    std::cout << "Jogada da máquina:\n";
    imprime(tab);

    char r;

    r = vitoria_principal(tab);
    if (r == 'F')
    {
        r = vitoria_secundaria(tab);
        if (r == 'F')
        {
            r = vitoria_linhas(tab);
            if (r == 'F')
            {
                r = vitoria_colunas(tab);
                if (r == 'F')
                {
                    r = velha(tab);
                }
            }
        }
    }
    return r;
}

int main()
{
    std::cout << "==== JOGO DA VELHA ====" << std::endl;
    
    char user;
    std::cout << "Escolhe 'X' ou 'O'? ";
    std::cin >> user;
    
    if (user == '0') user = 'O';

    user = toupper(user); //garante que será maiúsculo
    
    while (user != 'X' && user != 'O')
    {
        std::cout << "Entrada inválida! Escolha X ou O: ";
        std::cin >> user;
        user = toupper(user);
    }
    
    char tab[3][3];
    
    init(tab);
    imprime(tab);

    char pc;
    if (user == 'X') pc = 'O';
    else pc = 'X';

    char result;

    result = jogo(user, pc, tab);
    while (result == 'F') result = jogo(user, pc, tab);

    if (result == user) std::cout << "-- Vitória do jogador! --\n";
    else if (result == pc) std::cout << "-- Vitória da máquina! -- \n";
    else if (result == 'V') std::cout << "-- Velha! --\n";

    return 0;
}