#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int cod;
    char nome[50];
    char marca[100];
    int qtd;
    int dia, mes, ano;
}Elem;

typedef struct node {
    Elem prod;
    struct node *proximo;
} No;

typedef struct {
    No *head;
} Lista;

int Vazia(Lista *l)
{
    if (l->head == NULL) return 1;
    else return 0;
}

Elem LerProduto()
{
    Elem p;
    printf("Insira o código: ");
    scanf("%d", &p.cod);

    getchar();
    printf("Insira o nome: ");
    fgets(p.nome, 50, stdin);
    
    printf("Insira a marca: ");
    fgets(p.marca, 100, stdin);

    printf("Quantidade disponível: ");
    scanf("%d", &p.qtd);
    while (p.qtd <= 0)
    {
        printf("Insira uma quantidade válida: ");
        scanf("%d", &p.qtd);
    }

    printf("VALIDADE\nDia: ");
    scanf("%d", &p.dia);
    while (p.dia < 0 || p.dia > 31)
    {
        printf("Dia inválido. Insira o dia: ");
        scanf("%d", &p.dia);
    }
    printf("Mês: ");
    scanf("%d", &p.mes);
    while (p.mes < 0 || p.mes > 12)
    {
        printf("Mês inválido. Insira o mês: ");
        scanf("%d", &p.mes);
    }
    printf("Ano: ");
    scanf("%d", &p.ano);
    
    return p;
}

void ImprimeProduto(Elem prod)
{
    printf("Código: %d\n", prod.cod);
    printf("Nome: %s", prod.nome);
    printf("Marca: %s", prod.marca);
    printf("Quantidade: %d\n", prod.qtd);
    printf("Validade: %d/%d/%d\n\n", prod.dia, prod.mes, prod.ano);
}

void ImprimeLista(Lista l)
{
    No *atual;

    printf("---------------------\n\n");

    for (atual = l.head; atual != NULL; atual = atual->proximo) ImprimeProduto(atual->prod);
    
    printf("---------------------\n\n");
}

void sort(Lista *l)
{
    No *i, *j;
    Elem temp;
    
    for (i = l->head; i->proximo != NULL; i=i->proximo)
    {
        for (j = i->proximo; j != NULL; j = j->proximo )
        {
            if (strcmp(i->prod.nome, j->prod.nome) == 0 && strcmp(i->prod.marca, j->prod.marca) == 0)
            {
                if (i->prod.ano > j->prod.ano)
                {
                    temp = i->prod;
                    i->prod = j->prod;
                    j->prod = temp;
                }
                else if (i->prod.ano == j->prod.ano)
                {
                    if (i->prod.mes > j->prod.mes)
                    {
                        temp = i->prod;
                        i->prod = j->prod;
                        j->prod = temp;
                    }
                    else if (i->prod.mes == j->prod.mes)
                    {
                        if (i->prod.dia > j->prod.dia)
                        {
                            temp = i->prod;
                            i->prod = j->prod;
                            j->prod = temp;
                        }
                    }
                }
            }
        }
    }
}

int Consultar(Lista *l, char *produto, char *marca) //retorna a quantidade total de produtos iguais
{
    No *atual;
    atual = l->head;

    int cont;

    int qtd = 0;    
    printf("\nInstâncias do produto encontradas: \n");
    while (atual != NULL)
    {
        if (strcmp(atual->prod.nome, produto) == 0 && strcmp(atual->prod.marca, marca) == 0)
        {
            cont=1;
            ImprimeProduto(atual->prod);
            qtd = qtd + atual->prod.qtd;
        }
        atual = atual->proximo;
    }
    return qtd;
}

int Retirar(Lista *l, char *produto, char *marca, int qtd)
{
    if (Vazia(l)) return -1;

    int tot = Consultar(l, produto, marca);
    
    printf("Total de produtos: %d\n", tot);
    if (tot == 0) return 0;
    else if (tot < qtd) return -2;
    
    printf("Total requerido: %d\n", qtd);
    
    No *atual;

    atual = l->head;
    
    while (atual != NULL)
    {
        if (strcmp(atual->prod.nome, produto) == 0 && strcmp(atual->prod.marca, marca) == 0)
        {
            int aux = qtd;
            aux = aux - atual->prod.qtd;
            atual->prod.qtd -= qtd;
            qtd = aux;
        }
        atual = atual->proximo;
    }
    
    No *anterior = NULL;
    
    while (l->head != NULL && l->head->prod.qtd <= 0) l->head = l->head->proximo;

    atual = l->head;

    while (atual != NULL && atual ->proximo != NULL)
    {
        if (atual->proximo->prod.qtd <= 0)
        {
            atual->proximo = atual->proximo->proximo;
        }
        else atual = atual = atual->proximo;
    }

    return 1;
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
    
    while (atual->proximo != NULL) atual = atual->proximo;
    
    atual->proximo = novo;
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
        printf("\n[1] Mostrar estoque\n");
        printf("[2] Inserir produto\n");
        printf("[3] Retirar produto\n");
        printf("[4] Consultar produto\n");
        printf("[-1] Encerra o programa\n");
        printf("Escolha: ");
        scanf("%d", &c);
    
        if (c == 1) ImprimeLista(estoque);
    
        else if (c == 2)
        {
            Elem p = LerProduto();
            if (Inserir(&estoque, p)) printf("Produto inserido\n");
            else printf("Um erro ocorreu\n");
            sort(&estoque); 
        }

        else if (c == 3)
        {
            int qtd;
            char remov_nome[50], remov_marca[100];
            getchar();
            printf("Insira o nome do produto a ser retirado: ");
            fgets(remov_nome, 50, stdin);

            printf("Insira a marca do produto: ");
            fgets(remov_marca, 100, stdin);

            printf("Insira a quantidade a ser removida: ");
            scanf("%d", &qtd);

            int r = Retirar(&estoque, remov_nome, remov_marca, qtd);
            
            if (r == 1) printf("Produto com o prazo de validade mais próximo retirado\n");
            else if (r == -1) printf("Estoque vazio!\n");
            else if (r == -2) printf("Quantidade disponível menor do que a requerida\n");
            else printf("Produto não encontrado\n");
        }

        else if (c == 4)
        {
            char consult[50], consult_marca[100];
            getchar();
            printf("Insira o nome do produto a ser consultado: ");
            fgets(consult, 50, stdin);

            printf("Insira a marca: ");
            fgets(consult_marca, 100, stdin);


            int r = Consultar(&estoque, consult, consult_marca);
            if (r == 0) printf("O produto não se encontra no estoque\n");
            else printf("Quantidade total: %d\n", r);
        }
    }   
    return 0;
}