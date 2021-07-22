#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    // int cod;
    char nome[200];
    // char marca[100];
    int dia, mes, ano;
}Elem;

typedef struct node {
    Elem prod;
    struct node *proximo;
} No;

typedef struct {
    No *head;
} Lista;

Elem LerProduto()
{
    Elem p;
    // printf("Insira o código: ");
    // scanf("%d", &p.cod);

    getchar();
    printf("Insira o nome: ");
    fgets(p.nome, 200, stdin);
    
    // printf("Insira a marca: ");
    // fgets(p.marca, 100, stdin);

    printf("VALIDADE\nDia: ");
    scanf("%d", &p.dia);
    printf("Mês: ");
    scanf("%d", &p.mes);
    printf("Ano: ");
    scanf("%d", &p.ano);
    
    return p;
}


void ImprimeLista(Lista l)
{
    No *atual;

    printf("---------------------\n\n");
    for (atual = l.head; atual != NULL; atual = atual->proximo){
        // printf("Código: %d\n", atual->prod.cod);
        printf("Descrição: %s", atual->prod.nome);
        // printf("Marca: %s", atual->prod.marca);
        printf("Validade: %d/%d/%d\n\n", atual->prod.dia, atual->prod.mes, atual->prod.ano);
    }
    
    printf("---------------------\n\n");

}

int Inserir(Lista *l, Elem p)
{
    No *novo;
    novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) return 0;

    novo->prod = p;
    
    if (l->head == NULL) //lista vazia;
    {
        novo->proximo = l->head;
        l->head = novo;
        return 1;
    }
    
    No *atual, *anterior = NULL;
    atual = l->head;
    while (atual != NULL)
    {
        if (strcmp(atual->prod.nome, p.nome) == 0)
        {
            if (p.ano > atual->prod.ano) //novo depois
            {
                novo->proximo = atual->proximo;
                atual->proximo = novo;
                
                return 1;       
            }
            else if (p.ano == atual->prod.ano)
            {
                if (p.mes > atual->prod.mes) //novo depois
                {
                    novo->proximo = atual->proximo;
                    atual->proximo = novo;
                    return 1;
                }
                else if (p.mes == atual->prod.mes)
                {
                    if (p.dia > atual->prod.dia) //novo depois
                    {
                        novo->proximo = atual->proximo;
                        atual->proximo = novo;
                        return 1;
                    }
                    else //novo antes
                    {
                        if (anterior == NULL)
                        {
                            novo->proximo = l->head;
                            l->head = novo;
                            return 1;
                        }
                        anterior->proximo = novo;
                        novo->proximo = atual;
                        return 1;
                    }
                }
                else //novo antes
                {
                    if (anterior == NULL)
                    {
                        novo->proximo = l->head;
                        l->head = novo;
                        return 1;
                    }
                    anterior->proximo = novo;
                    novo->proximo = atual;
                    return 1;
                }
            }
            else
            {
                if (anterior == NULL)
                {
                    novo->proximo = l->head;
                    l->head = novo;
                    return 1;
                }
                anterior->proximo = novo;
                novo->proximo = atual;
                return 1;
            }
        }
        else{
            anterior = atual;
            atual = atual->proximo;
        }
        
    }
    //agora o anterior é o atual

    anterior->proximo = novo;
    novo->proximo = NULL;
    
    return 1;

}

int main()
{
    Lista estoque;
    estoque.head = NULL;

    int c = 0;

    while (c != -1)
    {
        printf("[1] Mostrar estoque\n");
        printf("[2] Inserir produto\n");
        printf("[3] Retirar produto\n");
        printf("[4] Consultar produto\n");
        printf("Escolha: ");
        scanf("%d", &c);
    
        if (c == 1) ImprimeLista(estoque);
    
        else if (c == 2)
        {
            Elem p = LerProduto();
            if (Inserir(&estoque, p)) printf("Produto inserido\n");
            else printf("Um erro ocorreu\n");
        }         

    }
    
    return 0;
}