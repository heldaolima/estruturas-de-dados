#include <stdio.h>

int testes(char nome[])
{
    if (nome[0] == ' ' || (nome[0] >= 97 && nome[0] <= 126) ) return -1; //primero caractere espaço ou minúscula
    
    int i = 0;
    while (nome[i] != '\0')
    {
        if (nome[i] >= 48 && nome[i] <= 57) return -1; //números no nome
        i++;
    }
    return 0;
}

int main()
{
    int r;
    char nome[50];
    printf("Insira o seu nome: ");
    fgets(nome, 50, stdin);
    r = testes(nome);
    
    while (r == -1)
    {
        getchar();
        printf("Entrada inválida! Insira o seu nome: ");
        fgets(nome, 50, stdin);
        r = testes(nome);
    }

    printf("Olá, %s", nome);

    
    return 0;
}