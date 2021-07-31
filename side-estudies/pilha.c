#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int num;
    struct node *next;
} No;

typedef struct {
    No *topo;
} Pilha;

int Empilhar(Pilha *p, int n)
{
    No *novo;
    novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->num = n;
        novo->next = p->topo;
        p->topo = novo;
    }
    else return FALSE;
}

void Imprimir(Pilha p)
{
    for (No *i = p.topo; i != NULL; i = i->next) printf("%d " , i->num);
    printf("\n");
}

int main()
{
    Pilha p;
    p.topo = NULL;

    Empilhar(&p, 1);
    Empilhar(&p, 3);
    Empilhar(&p, 9);
    Empilhar(&p, 4);

    Imprimir(p);

    return 0;
}