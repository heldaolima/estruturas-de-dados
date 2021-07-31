//Árvore Binária simples

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int data;
    struct treenode *left, *right;
}TreeNode;

TreeNode* NovoNo(int dado)
{
    TreeNode *novo = malloc(sizeof(TreeNode));
    if (novo != NULL)
    {
        novo->data = dado;
        novo->left = NULL;
        novo->right = NULL;
    }
    return novo;
}

void PrintTabs(int numtabs)
{
    for(int i = 0; i < numtabs; i++)
        printf("\t");
}

void PrintTree_Rec(TreeNode *root, int level)
{
    if (root == NULL) {
        PrintTabs(level);
        printf("---<Empty>---\n");
        return;
    }
    PrintTabs(level);
    
    printf("Valor: %d\n", root->data);
    PrintTabs(level);
    
    printf("Left: \n");
    PrintTree_Rec(root->left, level+1);
    PrintTabs(level);
    
    printf("Right\n");
    PrintTree_Rec(root->right, level+1);
    PrintTabs(level);
    
    printf("Done\n");
}

void PrintTree(TreeNode *root)
{
    PrintTree_Rec(root, 0);
}

int main()
{
    TreeNode *n1 = NovoNo(10);
    TreeNode *n2 = NovoNo(11);
    TreeNode *n3 = NovoNo(12);
    TreeNode *n4 = NovoNo(13);
    TreeNode *n5 = NovoNo(14);

    n1->left = n2; //root
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    PrintTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}