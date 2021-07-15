#include <stdio.h>

/*
@author: Hélder Lima
*/

struct livro {
    int registro;
    char titulo[100];
    char autor[50];
    int ano;
    int qtd_copias;
    int qtd_emprestados;
};


void mostrar_livros(struct livro l[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\n--- REGISTRO [%d] --- \nTítulo: %sAutor: %s", l[i].registro, l[i].titulo, l[i].autor);
        printf("Ano: %d\n", l[i].ano);
        printf("Quantidade total de cópias: %d\n", l[i].qtd_copias);
        printf("Quantidade de livros emprestados: %d\n", l[i].qtd_emprestados);
    }
}

void emprestar(struct livro l[], int tam)
{
    printf("Livros disponíveis: ");
    mostrar_livros(l, tam);

    int empr;
    printf("\nInsira o número de registro do livro a ser removido: ");
    scanf("%d", &empr);

    while (empr < 0 || empr > tam)
    {
        printf("Número inválido! Insira o número de registro do livro a ser removido: ");
        scanf("%d", &empr);
    }

    int i = empr-1;

    printf("Livro escolhido:\n");
    printf("\n--- REGISTRO [%d] --- \nTítulo: %sAutor: %s", l[i].registro, l[i].titulo, l[i].autor);
    printf("Ano: %d\n", l[i].ano);
    printf("Quantidade total de cópias: %d\n", l[i].qtd_copias);
    printf("Quantidade de livros emprestados: %d\n", l[i].qtd_emprestados);

    if (l[i].qtd_copias - l[i].qtd_emprestados <= 1)
    {
        printf("Há apenas uma cópia do livro disponível. Segundo as políticas da biblioteca, não podemos emprestá-lo.\n");
        return;
    }
    else 
    {
        l[i].qtd_emprestados += 1;
        printf("Livro emprestado! Lembre-se de devolvê-lo!\n");
        return;
    }

}

int remover(struct livro l[], int tam)
{
    printf("Livros disponíveis: ");
    mostrar_livros(l, tam);

    int rem;
    printf("\nInsira o número de registro do livro a ser removido: ");
    scanf("%d", &rem);

    while (rem < 0 || rem > tam)
    {
        printf("Número inválido! Insira o número de registro do livro a ser removido: ");
        scanf("%d", &rem);
    }

    for (int i = 0; i < tam; i++)
    {
        if (l[i].registro == rem){
            while (i < tam)
            {
                l[i+1].registro -= 1;
                l[i] = l[i+1];
                i++;
            }
            break;
        }
    }

    printf("Livro removido com sucesso\n");

    return tam-1;
}

int add_livros(struct livro l[], int qtd)
{
    char escolha = 'S';
    int i = qtd;
    

    while (escolha == 's' || escolha == 'S')
    {
        getchar();
        l[i].registro = i+1;
        printf("Adicionando o livro de registro [%d]...\n", l[i].registro);
        
        printf("Título: ");
        fgets(l[i].titulo, 100, stdin);
        
        printf("Autor: ");
        fgets(l[i].autor, 50, stdin);
        
        printf("Ano: ");
        scanf("%d", &l[i].ano);
        
        printf("Quantidade total de cópias: ");
        scanf("%d", &l[i].qtd_copias);
        
        printf("Quantidade de cópias emprestadas: ");
        scanf("%d", &l[i].qtd_emprestados);

        i++;
        printf("Adicionar novo livro? [s/n]? ");
        scanf(" %c", &escolha);
    }
    return i;
}

int main()
{
    struct livro biblioteca[50];
    int escolha, qtd = 0;
    
    printf("[1] Mostrar livros disponíveis\n[2] Adicionar livros\n[3] Remover livro\n[4] Emprestar livro\n[5] Encerrar\n");
    printf("Sua opção: ");
    scanf("%d" , &escolha);

    while (escolha < 1 || escolha > 5)
    {
        printf("Escolha inválida! Sua opção: ");
        scanf("%d", &escolha);
    }

    while (escolha != 5)
    {
        if (escolha == 1)
        {
            if (qtd == 0) printf("Nenhum livro adicionado ainda!\n");
            else mostrar_livros(biblioteca, qtd);
        }

        else if (escolha == 2) 
        {
            if (qtd == 50) printf("Biblioteca lotada!\n");
            else qtd = add_livros(biblioteca, qtd);
        }

        else if (escolha == 3)
        {
            if(qtd == 0) printf("Nenhum livro foi aicionado ainda!\n");
            else qtd = remover(biblioteca, qtd);
        }

        else if (escolha == 4)
        {
            if (qtd == 0) printf("Nenhum livro foi adicionado ainda!\n");
            else emprestar(biblioteca, qtd);
        }

        printf("\n[1] Mostrar livros disponíveis\n[2] Adicionar livros\n[3] Remover livro\n[4] Emprestar livro\n[5] Encerrar\n");
        printf("Sua opção: ");
        scanf("%d" , &escolha);
    }
    return 0;
}