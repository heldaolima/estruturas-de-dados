#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int registro;
    char titulo[100];
} Book;

typedef struct node {
    Book livro;
    struct node *proximo;
} No;

typedef struct {
    No *head;
} LinkedList;

int Vazia(LinkedList *l)
{
    if (l->head == NULL) return TRUE;
    else return FALSE;
}

int RemoveInicio(LinkedList *l)
{
    if (Vazia(l)) return FALSE;

    No *new = l->head;

    l->head = new->proximo;
    
    free(new);

    return TRUE;

}

int RemoveFim(LinkedList *l)
{
    if (Vazia(l)) return FALSE;

    No *curr, *ant = NULL;
    curr = l->head;

    while (curr->proximo != NULL)
    {
        ant = curr;
        curr = curr->proximo;
    }

    if(ant == NULL) return RemoveInicio(l);

    ant->proximo = curr->proximo; //penultimo aponta para NULL; fim da lista
    
    free(curr);

    return TRUE;

}

int RemoveLivro(LinkedList *l, char *elem)
{
    printf("Elemento: %s\n", elem);

    if (Vazia(l)) return -1;

    No *curr, *anterior = NULL;
    for (curr = l->head; curr != NULL; curr = curr->proximo)
    {
        printf("Na lista: %s\n", curr->livro.titulo);
        if (strcmp(curr->livro.titulo, elem) == 0)
        {
            if (anterior == NULL) return RemoveInicio(l);
            anterior->proximo = curr->proximo;
            free(curr);

            return TRUE; 
        }
        anterior = curr;
    }
    return FALSE;
}

int InserirInicio(LinkedList *l, Book elem)
{
    No *new;

    new = malloc(sizeof(No));

    if (new == NULL) return FALSE;

    new->livro = elem;
    new->proximo = l->head;
    l->head = new;

    return TRUE;
}

int Pesquisar(LinkedList *l,  char *tit)
{
    if (Vazia(l)) return -1; //a lista está vazia
    
    No *curr;
    for (curr = l->head; curr != NULL; curr = curr ->proximo)
    {
        if (strcmp(curr->livro.titulo, tit) == 0) return TRUE; //encontrado 
    }
    return FALSE; //não encontrado

}

int Quantidade(LinkedList l)
{
    No *curr;
    curr = l.head;
    
    int cont = 0;
    while (curr != NULL)
    {
        cont++;
        curr = curr->proximo;
    }
    return cont;
}

int InserirFim(LinkedList *l, Book elem)
{
    if (Vazia(l)) return InserirInicio(l, elem);

    No *novo, *atual;
    atual = l->head;
    while (atual->proximo != NULL) atual = atual->proximo;

    novo = malloc(sizeof(No));
    if (novo == NULL) return FALSE;

    novo->livro = elem;
    novo->proximo = NULL;

    atual->proximo = novo;

    return TRUE;
}

void Imprimir(LinkedList lista)
{
    No *curr;

    curr = lista.head;
    printf("-------------------------------------\n\n");
    while (curr != NULL)
    {
        printf("Titulo: %s", curr->livro.titulo);
        printf("Registro: %d\n\n", curr->livro.registro);

        curr = curr->proximo;
    }
    printf("-------------------------------------\n");
}

void Criar(LinkedList *lista)
{
    lista->head = NULL;
}

Book Ler_Livro(Book novo)
{
    printf("Insira o número de registro: ");
    scanf("%d", &novo.registro);
    
    getchar();
    
    printf("Insira o título do livro: ");
    fgets(novo.titulo, 100, stdin);
    
    return novo;
}

int main()
{
    LinkedList biblioteca;
    int escolha;
    Criar(&biblioteca);


    printf("[2] Mostrar livros disponíveis\n");
    printf("[3] Pesquisar livro\n");
    printf("[4] Ver a quantidade de livros\n");
    printf("[5] Inserir livro no fim\n");
    printf("[6] Inserir livro no início\n");
    printf("[7] Remover livro do fim\n");
    printf("[8] Remover livro específico\n");
    printf("[9] Remover livro do início\n");
    printf("[11] Encerrar\n");

    printf("Sua opção: ");
    scanf("%d" , &escolha);

    while (escolha != 11) 
    {
        if (escolha == 2) Imprimir(biblioteca);
        
        
        if (escolha == 3)
        {
            char comp[100];
            getchar();
            printf("Insira o título: ");
            fgets(comp, 100, stdin);
            int r = Pesquisar(&biblioteca, comp);
            if (r == -1) printf("Lista vazia!\n");
            else if (r == 1) printf("Encontrado!\n");
            else printf("Não encontrado!\n");
        }

        if (escolha == 4) printf("\nAtualmente há %d livros disponíveis\n\n", Quantidade(biblioteca));

        if (escolha == 5)
        {
            Book novo;
            novo = Ler_Livro(novo);
            if (InserirFim(&biblioteca, novo)) printf("Livro inserido!\n");
            else printf("Um erro ocorreu.\n");
        }

        if (escolha == 6)
        {
            Book novo;
            novo = Ler_Livro(novo);
            if (InserirInicio(&biblioteca, novo)) printf("Novo livro inserido no início!\n");
            else printf("Um erro ocorreu!\n");
        }

        if (escolha == 7)
        {
            if (RemoveFim(&biblioteca)) printf("Último livro removido\n");
            else printf("Um erro ocorreu\n");
        }

        if (escolha == 8)
        {
            char remove[100];
            getchar();
            printf("Insira o livro a ser removido: ");
            fgets(remove, 100, stdin);
            int r = RemoveLivro(&biblioteca, remove);
            if (r == 1) printf("Livro removido\n");
            else if (r == -1) printf("Biblioteca vazia\n");
            else printf("Livro não encontrado\n");
        }

        if (escolha == 9)
        {
            if (RemoveInicio(&biblioteca)) printf("Início da lista removido\n");
            else printf("Um erro ocorreu\n");
        }

        printf("\n[2] Mostrar livros disponíveis\n");
        printf("[3] Pesquisar livro\n");
        printf("[4] Ver a quantidade de livros\n");
        printf("[5] Inserir livro no fim\n");
        printf("[6] Inserir livro no início\n");
        printf("[7] Remover livro do fim\n");
        printf("[8] Remover livro específico\n");
        printf("[9] Remover livro do início\n");
        printf("[11] Encerrar\n");

        printf("Sua opção: ");
        scanf("%d" , &escolha);

    }


    return 0;
}