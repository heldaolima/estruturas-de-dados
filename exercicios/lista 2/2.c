#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[30];
    int prior;
}Elem;

typedef struct node
{
    Elem p;
    struct node *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim; 
}Fila;

int Enfileirar(Fila *f, Elem pessoa)
{
    No *new;
    *new = (No*) malloc(sizeof(No));
    if (new == NULL) return 0;

    new->p = pessoa;

    if (f->inicio == NULL)
    {
        f->inicio = new;
        new->proximo = NULL;
        return 1;
    }
    else
    {
        No *atual, *anterior = NULL;
        atual = f->inicio;
        while (atual != NULL)
        {
            if (pessoa.prior > atual->p.prior) //vem antes
            {
                if (anterior == NULL)
                {
                    new->proximo = f->inicio;
                    f->inicio = new;
                    return 1;
                }
                
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

int main()
{
    Fila fila;
    
    fila.inicio = NULL;
    fila.fim = NULL;
    int c = 0;
    while (c != -1)
    {
        printf("[1] Mostrar fila\n");
        printf("[2] Enfileirar\n");
        printf("[3] Desenfileirar\n");
        printf("[-1] Encerrar");
        
        printf("Escolha: ");
        scanf("%d");
    
    }
    
    return 0;
}