#include <stdio.h>
#include <stdlib.h>

typedef struct adjlistnode { //um nó na lista de adjacência
    int dest; //destino 
    struct adjlistnode* next;
}AdjListNode;

typedef struct { //lista de adjacência
    AdjListNode *head;
}AdjList;

//grafo -> array de listas de adjacência
//Tamanho
typedef struct { 
    int V;
    AdjList* array;
    int* visitados;
}Graph;

Graph* createGraph(int V) //cria um grafo de V vértices
{
    Graph* graph = malloc(sizeof(Graph));
    
    graph->V = V;

    //array de listas de adjacência. Tamanho V
    graph->array = malloc(V * sizeof(AdjList));

    //inicializa as listas de adjacência
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;

    return graph;
}

//cria um novo nó de lista de adjacência
AdjListNode* newAdjListNode(int dest)
{
    AdjListNode* novo = malloc(sizeof(AdjListNode));
    novo->dest = dest;
    novo->next = NULL;
    return novo;
}

//adiciona uma aresta 
void addEdge(Graph* graph, int ini, int dest)
{
    /*adiciona aresta de ini pra dest; Um novo nó é
    adicionado à lista de adjacência de ini. O nó é
    adicionado sempre no começo*/
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[ini].head;
    graph->array[ini].head = newNode;

    /*Como o grafo é não-direcionado, adiciona uma aresta
    pde dest pra ini também*/
    newNode = newAdjListNode(ini);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(Graph* graph)
{
    for (int v = 0; v < graph->V; v++)
    {
        AdjListNode* atual = graph->array[v].head;
        printf("\n Lista de adjacência do vértice %d\n head ", v);
        while (atual)
        {
            printf("-> %d ", atual->dest);
            atual = atual->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 11; //numero de vertices

    Graph* graph = createGraph(11);
    
   addEdge(graph, 0, 5);
   addEdge(graph, 0, 10);
   
   addEdge(graph, 1, 5);
   addEdge(graph, 1, 4);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 10);

   addEdge(graph, 2, 3);
   addEdge(graph, 2, 10);

//    addEdge(graph, 3, 2);
   addEdge(graph, 3, 9);
   addEdge(graph, 3, 4);
//    addEdge(graph, 3, 1);

//    addEdge(graph, 4, 1);
//    addEdge(graph, 4, 3);
   addEdge(graph, 4, 9);
   addEdge(graph, 4, 8);
   addEdge(graph, 4, 6);

//    addEdge(graph, 5, 0);
   addEdge(graph, 5, 6);
//    addEdge(graph, 5, 1);

   addEdge(graph, 6, 7);
//    addEdge(graph, 6, 5);
//    addEdge(graph, 6, 4);
   addEdge(graph, 6, 8);
   addEdge(graph, 6, 10);

//    addEdge(graph, 7, 6);
   addEdge(graph, 7, 10);

//    addEdge(graph, 8, 6);
   addEdge(graph, 8, 9);
//    addEdge(graph, 8, 4);
   addEdge(graph, 8, 10);

//    addEdge(graph, 9, 8);
//    addEdge(graph, 9, 4);
//    addEdge(graph, 9, 3);
   addEdge(graph, 9, 10);      


    printGraph(graph);


    return 0;
}

/*
ideas so far:
    colocar um flag de 'explodido' nas arestas
    contador que incrementa ao passar pelas intactas

    passar por todas

    pelo visto eu vou ter que considerar que arestas múltiplas são uma só aresta, 
    como no desenho

    mas nao tem como representar as paredes pelas arestas, parece
    porque as arestas ligam vértices
    a ideia seria ir do primeiro ao último vertice conectado, mas ai nao dá

    as arestas não são paredes, mas portões. Cada cela está ligada a outra por um portão
*/