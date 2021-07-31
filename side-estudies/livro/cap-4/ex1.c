#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int num;
    struct node *next;
} No;

typedef struct {
    No *head;
} LinkedList;

int Vazia(LinkedList *l)
{
    if (l->head == NULL) return TRUE;
    else return FALSE;
}

void NoInicio(LinkedList *l, int n)
{
    No *novo;
    novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->num = n;
        novo->next = l->head;
        l->head = novo;        
    }
}

void RemoveInic(LinkedList *l)
{
    if (!(Vazia(l)))
    {
        No *aux;
        aux = l->head;

        l->head = aux->next;
        free(aux);
    }
    
}

void RemoveEspec(LinkedList *l, int n)
{
    No *atual, *anterior = NULL;
    atual = l->head;

    while (atual->next != NULL)
    {
        if (atual->num == n)
        {
            if (anterior == NULL) RemoveInic(l);
            else
            {
                anterior->next = atual->next;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->next;
    }
}

void Switch(LinkedList *l, int n)
{
    if (!(Vazia(l)))
    {
        No *i = l->head;
        No *ant = NULL;
        while (i->next != NULL)
        {
            if (i->num == n)
            {
                i->num = i->next->num;
                i->next->num = n;
                return;
            }
            i = i->next;
        }
    }
}

void Append(LinkedList *l, int n)
{
    if (Vazia(l)) return NoInicio(l, n);
    
    No *i, *novo;
    novo = malloc (sizeof(No));
    if (novo != NULL)
    {
        novo->num = n;
        novo->next = NULL;

        i = l->head;
        while (i->next != NULL) i = i->next;
        
        i->next = novo;
    }
}

void Imprimir(LinkedList l)
{
    for (No *i = l.head; i != NULL; i = i->next) printf("%d ", i->num);
    printf("\n");
}

LinkedList Inverter(LinkedList *l)
{
    LinkedList Inv;
    Inv.head = NULL;

    No *i = l->head;
    while (i != NULL)
    {
        NoInicio(&Inv, i->num);
        i=i->next;
    }

    return Inv;
}

int main()
{
    LinkedList L1, L2;
    L1.head = NULL;
    L2.head = NULL;
    
    Append(&L1, 10);
    Append(&L1, 20);
    Append(&L1, 24);
    Append(&L1, 29);
    Append(&L1, 15);

    Imprimir(L1);

    L1 = Inverter(&L1);

    Imprimir(L1);

    return 0;
}