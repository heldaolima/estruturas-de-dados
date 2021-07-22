#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no {
    int dado;
    struct no *prox;
}No;

typedef struct fila {
    No *ini;
    No *fim;
}Fila;

int enfileira(int dado, Fila *f) //numa fila, o novo dado sempre entra no fim
{
    No *new = malloc(sizeof(No));
    if (new == NULL) return FALSE;

    new->dado = dado;
    new->prox = NULL;

    if (f->ini == NULL) {
        f->ini = new;
    }
    else {
        f->fim->prox = new;
    }
    f->fim = new;
}

int desenfileirar(Fila *f) //sempre sai o primeiro elemento;
{
    No *new = f->ini;
    int dado;
    if (new != NULL)
    {
        f->ini = new->prox;
        new->prox = NULL; //isso aqui não necessário; as coisas necessárias já foram feitas nas linhas acima
        free(new);
        if (f->ini == NULL){
            f->fim = NULL;
        }
        return TRUE;
    } else{
        printf("Fila vazia\n");
        return FALSE;
    }
}

void imprime(Fila f)
{
    No *atual;
    int i = 0;
    if (atual != NULL)
    {
        for (atual = f.ini; atual != NULL; atual = atual->prox)
        {
           printf("Dado [%d]: %d\n", i,  atual->dado);
           i++;
        }
        printf("\n");
    }
    else printf("Fila vazia\n");
}

int main()
{
    Fila f;
    f.ini = NULL;
    f.fim = NULL;

    enfileira(10, &f);
    enfileira(20, &f);
    enfileira(30, &f);

    imprime(f);
    desenfileirar(&f);

    imprime(f);

    return 0;
}