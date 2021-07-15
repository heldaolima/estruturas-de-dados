#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[31];
    int idade;
}Elem;

typedef struct {
    Elem *elementos; //algo me diz que isso é pra ser um array
    int quantidade, tamanho;
}ListaEstatica;

// int Pesquisar(ListaEstatica lista, char *nome) //*nome é uma string
// {
//     for (int i = 0; i < lista.quantidade; i++)
//     {
//         if (stricmp(lista.elementos[i].nome, nome) == 0) return i;
//     }
//     return -1;
// }

int Quantidade(ListaEstatica lista)
{
    return lista.quantidade;
}

int Cheia(ListaEstatica lista)
{
    return lista.quantidade == lista.tamanho;
}

int Vazia(ListaEstatica lista)
{
    return lista.quantidade == 0; //ESSA PORRA É UM CONDICIONAL
}

void Imprimir(ListaEstatica lista)
{
    for (int i = 0; i < lista.quantidade; ++i)
    {
        printf("Nome: %s - ", lista.elementos[i].nome);
        printf("Idade: %d\n", lista.elementos[i].idade);
    }
}

// int Remover(ListaEstatica *lista, Elem *elem)
// {
//     int pos = Pesquisar(*lista, elem->nome);
//     if (pos < 0) return FALSE;
//     else{
//         *elem = lista->elementos[pos];
//         for (int i = pos; i < lista->quantidade; i++)
//         {
//             lista -> elementos[i] = lista->elementos[i+1];
//         }
//         lista->quantidade--;
//         return TRUE;
//     }
// }

int RemoverFinal(ListaEstatica *lista, Elem *elem)
{
    if (Vazia(*lista)) return FALSE;
    *elem = lista->elementos[--lista->quantidade]; //what happens here?
    return TRUE;
}

int RemoverInicio(ListaEstatica *lista, Elem *elem)
{
    if (Vazia(*lista)) return FALSE;
    *elem = lista->elementos[0];
    lista->quantidade--;
    for (int i = 0; i < lista->quantidade; i++)
    {
        lista->elementos[i] = lista->elementos[i+1];    
    }
    return TRUE;
}

int InserirFim(ListaEstatica *lista, Elem novo)
{
    if (Cheia(*lista)) return FALSE;
    lista->elementos[lista->quantidade++] = novo;
    return TRUE;
}

int InserirInicio(ListaEstatica *lista, Elem novo)
{
    if (Cheia(*lista)) return FALSE;
    for (int i = lista->quantidade; i > 0; i++)
    {
        lista->elementos[i] = lista->elementos[i-1];
    }
    lista->elementos[0] = novo;
    lista->quantidade++;
    return TRUE;
}

int Criar(ListaEstatica *lista, int tam)
{
    lista->elementos = calloc(tam, sizeof(Elem)); //CRIOU UM VETOR
    
    if (lista->elementos == NULL) return FALSE;
    lista->tamanho = tam;
    lista->quantidade = 0;
    return TRUE;
}

int main()
{
    ListaEstatica lista;
    int c = Criar(&lista, 5);

    if (c) printf("Criou!\n");
    else printf("Não criou\n");

    Elem novo;
    novo.idade = 19;
    strcpy(novo.nome, "Hélder");
    

    if (InserirInicio(&lista, novo)) printf("Adicionado\n");
    else printf("erro\n");

    Imprimir(lista);

    printf("vazia: %d\n", Vazia(lista));

    return 0;
}