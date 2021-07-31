//Árvore binária de busca BST
//ordered
// left: < root
// right >= root
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode {
    int data;
    struct treenode  *left, *right;
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

bool Insert(TreeNode **rootptr, int value)
{
    TreeNode *root = *rootptr;
    if (root == NULL)
    {
        (*rootptr) = NovoNo(value);
        return true;
    }
    if (value == root->data) return false;
    if (value < root->data) 
        return Insert(&root->left, value);
    else
        return Insert(&root->right, value);
}
 
bool Search(TreeNode *root, int data) 
{
    if (root == NULL) return false;

    if (root->data == data) return true;

    if (data < root->data) 
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int main()
{
    TreeNode *root = NULL;
    
    Insert(&root, 15);
    Insert(&root, 11);
    Insert(&root, 24);
    Insert(&root, 5);
    Insert(&root, 19);
    Insert(&root, 16);
    Insert(&root, 21);

    PrintTree(root);

    return 0;
}