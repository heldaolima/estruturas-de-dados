#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct pessoa {
    char nome[31];
    int idade;
} Elem;

typedef struct node {
    Elem elemento;
    struct node *next;
} No;

typedef struct {
    No *head;
}LinkedList;

void clean(LinkedList *l)
{
    No *aux;
    
    while (l->head)
    {
        aux = l->head->next;
        free(l->head);
        l->head = aux;
    }
}

void imprimir(LinkedList l)
{
    No *atual = l.head;

    while (atual != NULL)
    {
        printf("Nome: %s", atual->elemento.nome);
        printf("Idade: %d\n", atual->elemento.idade);

        atual = atual->next;
    }
}


int InserirInicio(LinkedList *l, Elem novo_elemento) //o que tava acontecendo é que eu tava pensando em termos de array; not that simple. Precisa, de fato, separar a inserção da cabeça da inserção da cauda. Pois só assim vai fazer sentido;
{
    No *novo;
    
    novo = malloc(sizeof(No));
    if (novo == NULL) return False;

    novo->elemento = novo_elemento;
    novo->next = l->head;
    l->head = novo;

    return True; 
}

Elem LerElemento(Elem novo)
{
    getchar();
    printf("Insira o nome: ");
    fgets(novo.nome, 31, stdin);
    
    printf("Insira a idade: ");
    scanf("%d", &novo.idade);

    return novo;
}

void criar(LinkedList *lista)
{
    lista->head = NULL;
}

int main()
{
    LinkedList lista;

    criar(&lista);

    int op = 0;
    
    while (op != -1)
    {
        printf("[1] Criar\n");
        printf("[2] Adicionar\n");
        printf("[3] Imprimir\n");
        
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 2)
        {
            Elem novo = LerElemento(novo);
            if (InserirInicio(&lista, novo)) printf("Done\n");
            else printf("Erro!\n");
            
        }
        else if (op == 3)
        {
            imprimir(lista);
        }
        else if (op == -1)
        {
            printf("Encerrando...\n");
            break;
        }

        clean(&lista);
    }

    return 0;
}