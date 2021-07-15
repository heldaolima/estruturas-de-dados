#include <stdio.h>

/*
    Biblioteca;
    titulo
    autor
    ano
    qtd de copias
    n emprestados


    inserir
    remover
    emprestar
    receber
*/

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;
data[10] teste;

int main()
{

    printf("Dia: ");
    scanf("%d", &teste.dia);
    printf("Mês: ");
    scanf("%d", &teste.mes);
    printf("Ano: ");
    scanf("%d", &teste.ano);

    if (teste.dia < 10) printf("0%d/", teste.dia);
    else printf("%d/", teste.dia);

    if (teste.mes < 10) printf("0%d/", teste.mes);
    else printf("%d/", teste.mes);

    printf("%d\n", teste.ano);

    return 0;    
}