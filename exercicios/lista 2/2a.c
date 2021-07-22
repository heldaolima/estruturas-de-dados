#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    int identidade;
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

int Vazia(Fila *f)
{
    if (f->inicio == NULL) return 1;
    else return 0;
}

int Quantidade(Fila *f)
{
    No *i;
    int cont = 0;

    for (i=f->inicio; i != NULL; i=i->proximo) cont++;
    
    return cont;
}

void ImprimirPessoa(Elem p)
{
    printf("Nome: %s", p.nome);
    printf("Identidade: %d\n", p.identidade);
    printf("Prioridade: %d\n", p.prior);
}

Elem Desenfileira(Fila *f)
{
    No *aux;
    Elem d;
    aux = f->inicio;
    if (aux != NULL)
    {
        d = f->inicio->p;        
        f->inicio = aux->proximo;
        
        if (f->inicio == NULL) f->fim = NULL;

        free(aux);
        return d;
    }
}

int DesenfileiraEspecifico(Fila *f, int id)
{
    No *i ,*anterior = NULL;
    i = f->inicio;
    while (i != NULL)
    {
        if (i->p.identidade == id)
        {
            if (anterior == NULL) 
            {
                Desenfileira(f);
                return 1;
            }
            anterior->proximo = i->proximo;
            free(i);
            return 1;
        }
        anterior = i;
        i = i->proximo;
    }
}

int Processo(Fila *f, Fila *fila_geral)
{
    No *novo;
    int cont = 0;
    for (novo = f->inicio; novo != NULL; novo=novo->proximo)
    {
        if (Vazia(f) || cont == 1) return cont;

        Elem atendido = Desenfileira(f);
        if (DesenfileiraEspecifico(fila_geral, atendido.identidade))
        {
            printf("ATENDIDO: \n");
            ImprimirPessoa(atendido);
            printf("--------------------\n\n");
        }
        cont++;
    }
    return cont;
}

int ProcessoP3(Fila *f, Fila *fila_geral)
{
    No *novo;
    int cont = 0;
    for (novo = f->inicio; novo != NULL; novo=novo->proximo)
    {
        if (Vazia(f) || cont == 2) return cont;

        Elem atendido = Desenfileira(f);
        if (DesenfileiraEspecifico(fila_geral, atendido.identidade))
        {
            printf("ATENDIDO: \n");
            ImprimirPessoa(atendido);
            printf("--------------------\n\n");
        }
        cont++;
    }
    return cont;
}

int Atendimento(Fila *fila_geral, Fila *p0, Fila *p1, Fila *p2, Fila *p3)
/*
Critério: Cada atendimento cobre no máximo quatro pessoas, sendo duas da prioridade 3 e uma de cada uma das outras
*/
{
    int cont_geral = ProcessoP3(p3, fila_geral);

    cont_geral += Processo(p2, fila_geral);

    cont_geral += Processo(p1, fila_geral);

    if (cont_geral != 4) cont_geral += Processo(p0, fila_geral);   

    return cont_geral;
}

int Enfileira(Fila *f, Elem pessoa)
{
    No *novo;
    novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->p = pessoa;
    novo->proximo = NULL;

    if (f->inicio == NULL)
    {
        novo->proximo = f->inicio;
        f->inicio = novo;
    }
    else f->fim->proximo = novo;
    
    f->fim = novo;
    
    return 1;
}

void ImprimirFila(Fila f)
{
    No *i;
    int pos = 1;
    printf("\n--------------------------\n\n");
    for (i = f.inicio; i != NULL; i=i->proximo)
    {
        printf("[%d]\n", pos);
        ImprimirPessoa(i->p);
        pos++;
    }
    printf("\n--------------------------\n\n");
}

void Inicializar(Fila *fila_geral, Fila *p0, Fila *p1, Fila *p2, Fila *p3)
{
    fila_geral->inicio = NULL;
    fila_geral->fim = NULL;
    p0->inicio = NULL;
    p0->fim = NULL;
    p1->inicio = NULL;
    p1->fim = NULL;
    p2->inicio = NULL;
    p2->fim = NULL;
    p3->inicio = NULL;
    p3->fim = NULL;
}

int IdRepetido(int id, Fila *f)
{
    if (Vazia(f)) return 0;

    No *i;
    for (i = f->inicio; i != NULL; i = i->proximo)
    {
        if (i->p.identidade == id) return 1;
    }
    return 0;
}

Elem LerPessoa(Fila *f)
{
    Elem novo;
    printf("Nome: ");
    fgets(novo.nome, 30, stdin);
    printf("Prioridade: ");
    scanf("%d", &novo.prior);
    while (novo.prior < 0 || novo.prior > 3)
    {
        printf("Prioridad inválida! Insira a prioridade: ");
        scanf("%d", &novo.prior);
    }
    printf("Senha: ");
    scanf("%d", &novo.identidade);
    while (IdRepetido(novo.identidade, f))
    {
        printf("Senha repetida! Insira uma identidade válida:");
        scanf("%d", &novo.identidade);
    }
    return novo;
}

int main()
{
    Fila fila_geral, p0, p1, p2, p3;

    int r = 0;

    Inicializar(&fila_geral, &p0, &p1, &p2, &p3);
    while (r != 5)
    {
        printf("\n[1] Emitir nova senha\n");
        printf("[2] Realizar atendimento\n");
        printf("[3] Visualizar filas\n");
        printf("[4] Quantidade de pessoas na fila\n");
        printf("[5] Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &r);
        if (r == 1)
        {
            if (Quantidade(&fila_geral) < 10)
            {
                getchar();
                Elem novo = LerPessoa(&fila_geral);

                while (novo.prior < 0 || novo.prior > 3)
                {
                    printf("Prioridade inválida! Insira uma prioridade válida: ");
                    scanf("%d", &novo.prior);
                }
                if (Enfileira(&fila_geral, novo)) printf("Enfileirado na fila geral\n");
                else printf("Um erro ocorreu\n");

                if(novo.prior == 0){
                    if (Enfileira(&p0, novo)) printf("Enfileirado na fila de prioridade 0\n");
                } 
                else if (novo.prior == 1) 
                {
                    if (Enfileira(&p1, novo)) printf("Enfileirado na fila de prioridade 1\n");
                }

                else if (novo.prior == 2) 
                {
                    if (Enfileira(&p2, novo)) printf("Enfileirado na fila de prioridade 2\n");
                }

                else if (novo.prior == 3) 
                {
                    if (Enfileira(&p3, novo)) printf("Enfileirado na fila de prioridade 3\n");
                }
            }
            else printf("Fila cheia! Por favor, aguarde até que as pessoas sejam atendidas!\n");
        }

        else if (r == 2)
        {
            if (Quantidade(&fila_geral) == 0) printf("Não há ninguém na fila para ser atendido!\n");
            else {
                printf("Realizando atendimento...\n");
                int c = Atendimento(&fila_geral, &p0, &p1, &p2, &p3);
                printf("%d pessoas foram atendidas.\n", c);
            }            
        }

        else if (r == 3)
        {
            printf("Fila geral:");
            ImprimirFila(fila_geral);
            printf("Prioridade 3:");
            ImprimirFila(p3);
            printf("Prioridade 2:");
            ImprimirFila(p2);
            printf("Prioridade 1:");
            ImprimirFila(p1);
            printf("Prioridade 0: ");
            ImprimirFila(p0);
        }

        else if (r == 4) printf("Quantidade de pessoas na fila geral: %d\n", Quantidade(&fila_geral));
    }
    return 0;
}

/*
A fila principal só pode ter até 10 pessoas. Com 10 pessoas, ela é considerada cheia e o banco não aceita uma nova senha até que clientes sejam atendidos e a fila se esvazie um pouco
*/ 