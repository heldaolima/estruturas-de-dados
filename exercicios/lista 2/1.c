#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char parenteses;
    int pos;
    struct node *prox;
}No;

typedef struct {
    No *topo;
}Pilha;

int Vazia(Pilha *l)
{
    if (l->topo == NULL) return 1;
    else return 0;
}

void Imprime(Pilha *l)
{
    No *i;
    printf("[");
    for (i = l->topo; i != NULL; i = i->prox)
    {
        printf("'%c' ", i->parenteses);
    }
    printf("]\n");
}

int Remove(Pilha *l)
{
    if (Vazia(l)) return 0;

    No *atual;
    atual = l->topo;

    l->topo = atual->prox;

    free(atual);

    return 1;
}

int Insere(Pilha *l, char p, int i)
{
    No *novo;
    novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) return 0;

    novo->parenteses = p;
    novo->pos = i;
    novo->prox = l->topo;
    l->topo = novo;

    return 1;
}

int Analise(Pilha *l, char *string)
{
    int i = 0, r;

    while (string[i] != '\0')
    {
        if (string[i] != '(' && string[i] != ')') return -1; //caractere invalido

        if (string[i] == '(') r = Insere(l, string[i], i);
        else if (string[i] == ')') r = Remove(l);
        
        if (r == 0)
        {
            printf("Excesso de fecha-parênteses\n");
            printf("Inválido na posição %d.\n", i);
            return 0;
        }

        // Imprime(l); //só pra saber o que está acontecendo
        i++;
    }
    if (Vazia(l)) return 1;
    else
    {
        printf("Excesso de abre-parênteses\n");
        printf("Inválido na posição %d.\n", l->topo->pos);
        return 0;
    }
}

int main()
{
    Pilha l;
    l.topo = NULL;
    int stop = 0;
    
    while (stop != -1)
    {
        char string[50];
        printf("[1] Analisar string\n");
        printf("[-1] Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &stop);
        switch (stop)
        {
        case 1:
            printf("Insira a string de parênteses que será analisada: ");
            scanf("%s", string);
            
            int r = Analise(&l, string);

            if (r == -1) printf("Caractere inválido inserido\n");   
            
            else if (r == 0) printf("FALSE\n");
            
            else printf("TRUE\n");
        
        case -1:
            break;

        default:
            printf("Escolha inválida!\n");
        }
    }
    return 0;
}