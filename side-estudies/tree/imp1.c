#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define COUNT 10

typedef struct node {
    int dado;
    struct node* left;
    struct node* right;
} No;

int Search(No* root, int data)
{
    if (root == NULL) return FALSE;
    
    if (root->dado == data) return TRUE;

    else if (data <= root->dado) return Search(root->left, data);
    else return Search(root->right, data);

    /*
            10
        12       9
    15              8
                10

    Só funciona pra esse Insert_Ordenado
    >8<
    Root é null? Não.
    root é 8? Não.
    8 é menor que root? É
        Então desce pra 9
        E assim vai até achar 8 e retornar TRUe
    */

}

No* NovoNo(int dado)
{
    No* novo = malloc(sizeof(No));
    novo->dado = dado;
    novo->left = NULL;
    novo->right = NULL;
    
    return novo;
}

No* Insert(No* r, int dado)
{
    if (r == NULL) //árvore vazia
        r = NovoNo(dado);
    else if (dado <= r->dado) //menores vão para esquerda
        r->left = Insert(r->left, dado);
    else //maiores para a direita;
        r->right = Insert(r->right, dado);

    return r;
}

// No* Insert_Left(No *root, int dado)
// {
//     return;
// }

// No* Insert_Right(No *root, int dado)
// {
//     return;
// }

void ImprimeArvore(No* root, int space)
{
    if (root == NULL) return;

    space += COUNT;

    ImprimeArvore(root->right, space);
    printf("\n");

    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->dado);

    ImprimeArvore(root->left, space);

}

//implementando árvore, no caso uma ordenada
int main() 
{
    No* raiz = NULL; //não dá pra fazer aquele esquema aqui de tipo árvore: RECURSÃO

    raiz = Insert(raiz, 10);
    raiz = Insert(raiz, 12);
    raiz = Insert(raiz, 25);
    raiz = Insert(raiz, 9);
    raiz = Insert(raiz, 8);
    raiz = Insert(raiz, 10);

    int n = 8;
    if (Search(raiz, n)) printf("%d encontrado na árvore\n", n);
    else printf("%d não encontrado na árvore\n");

    ImprimeArvore(raiz, 0);

    return 0;
}