#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[31];
    int idade;
}Elem;

typedef struct no{
    Elem elemento;
    struct no *proximo;
}No;

typedef struct {
    No *inicio; //esse tem elemento e proximo, sendo que o próximo é a cauda
} ListaSimplesmenteEncadeada;

int Vazia(ListaSimplesmenteEncadeada lista){
    return (lista.inicio == NULL);
}

int RemoveInicio(ListaSimplesmenteEncadeada *lista, Elem *elem)
{
    No *atual;
    
    if (Vazia(*lista)) return FALSE;

    atual = lista->inicio;
    lista->inicio = atual->proximo; //segundo elemento
    *elem = atual->elemento;
    
    free(atual);
    
    return TRUE;
}

int Remove(ListaSimplesmenteEncadeada *lista, char *nome, Elem *elem)
{
    No *anterior, *atual;

    if (Vazia(*lista)) return FALSE;

    anterior = NULL;
    atual = lista->inicio;

    while (atual != NULL)
    {
        if (strcmp(atual->elemento.nome, nome) == 0)
        {
            if (anterior == NULL) return RemoveInicio(lista, elem);
            anterior->proximo = atual->proximo;
            *elem = atual->elemento;
            free(atual);
            return TRUE;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

int RemoveFim(ListaSimplesmenteEncadeada *lista, Elem *elem)
{
    No *atual, *anterior = NULL;

    if (Vazia(*lista)) return FALSE;

    atual = lista->inicio;
    while (atual->proximo != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) return RemoveInicio(lista, elem);

    *elem = atual->elemento;
    anterior->proximo = atual->proximo;

    free(atual);

    return TRUE;
}

int InsereInicio(ListaSimplesmenteEncadeada *lista, Elem novo_elemento)
{
    No *novo; //nunca perca de vista que ele é uma caixinha daquelas;

    novo = malloc(sizeof(No));
    if (novo == NULL) return FALSE;
    
    //cabeças explodindo
    novo->elemento = novo_elemento;
    novo->proximo = lista->inicio;
    lista->inicio = novo;

    return TRUE; 
}

int InsereFim(ListaSimplesmenteEncadeada *lista, Elem novo_elemento)
{
    No *atual, *novo;

    if (Vazia(*lista)) return InsereInicio(lista, novo_elemento);

    atual = lista->inicio;
    while (atual->proximo != NULL) atual = atual->proximo; //parece que o atual "vira" os elementos da lista

    novo = malloc(sizeof(No));
    if (novo == NULL) return FALSE;

    atual->proximo = novo; //coloquei no final
    novo->proximo = NULL; //apontei pro nulo
    novo->elemento = novo_elemento; //inseri o elemento;
    return TRUE;

}

int Quantidade(ListaSimplesmenteEncadeada lista)
{
    No *atual;
    int qtd = 0;

    for (atual = lista.inicio; atual != NULL; atual = atual -> proximo) qtd++;
    return qtd;
}

int Pesquisa(ListaSimplesmenteEncadeada lista, char *nome)
{
    No *atual = lista.inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->elemento.nome, nome) == 0) return TRUE;
        atual = atual->proximo;
    }
    return FALSE;
}

void Imprime (ListaSimplesmenteEncadeada lista)
{
    No *atual;

    for (atual = lista.inicio; atual != NULL; atual = atual->proximo)
    {
        printf("Nome: %s - ", atual->elemento.nome);
        printf("Idade: %d\n", atual->elemento.idade);
    }

}

void Criar(ListaSimplesmenteEncadeada *lista)
{
    lista->inicio = NULL; //ou seja, a cabeça armazena o valor NULL, que é a nossa condição de parada. O primeiro elemento é o último.
}

int main()
{
    ListaSimplesmenteEncadeada lista;
    
    Criar(&lista);
    printf("Lista criada!\n");

    Elem n;
    n.idade = 15;
    strcpy(n.nome, "Hélder Silva");

    if (InsereInicio(&lista, n)) printf("adicionado\n");
    else printf("erro\n");

    Imprime(lista);
    
    return 0;
}