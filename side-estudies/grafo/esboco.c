#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

typedef struct adjlistnode { //um nó na lista de adjacência
    int dest; 
    struct adjlistnode* next;
}AdjListNode;

typedef struct { //lista de adjacência
    AdjListNode *head;
    AdjListNode *end;
}AdjList;

typedef struct
{
    int V;
    AdjList *array;
    int *visitados; //array 1 ou 0
}Graph;

AdjListNode* createNode(int v)
{
    AdjListNode* new = malloc(sizeof(AdjListNode));
    new->dest = v;
    new->next = NULL;
    return new;
}

void adicionar(Graph* graph, int ini, int dest, AdjListNode *newNode) //adiciona a nova aresta com os valores sempre no fim
{
    if (graph->array[ini].head == NULL)
    {
        newNode->next = graph->array[ini].head;
        graph->array[ini].head = newNode;
    }
    else
        graph->array[ini].end->next = newNode;
    graph->array[ini].end = newNode;
}

void addEdge(Graph* graph, int ini, int dest)
{
    AdjListNode* newNode = createNode(dest); //novo nó com o destino
    adicionar(graph, ini, dest, newNode);
    
    /*Como o grafo é não-direcionado, adiciona uma aresta
    pde dest pra ini também*/
    
    newNode = createNode(ini);
    adicionar(graph, dest, ini, newNode);

}

Graph* CreateGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) printf("!!!!ERRO!!!!\n\n");

    graph->V = vertices;
    
    graph->array = malloc(vertices * sizeof(AdjList)); //vertices adjacentes
    graph->visitados = (int*) malloc(sizeof(vertices * sizeof(int))); //vertices visitados (0 ou 1)

    for (int i = 0; i < vertices; i++)
    {
        graph->array[i].head = NULL;
        graph->array[i].end = NULL;
        graph->visitados[i] = 0;
    }

    return graph;
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
    //10 == saída
    int V = 11; //numero de vertices

    Graph* graph = CreateGraph(V);
    
   addEdge(graph, 0, 5);
   addEdge(graph, 0, 10);
   
   addEdge(graph, 1, 5);
   addEdge(graph, 1, 4);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 10);

   addEdge(graph, 2, 3);
   addEdge(graph, 2, 10);

   addEdge(graph, 3, 2);
   addEdge(graph, 3, 9);
   addEdge(graph, 3, 4);
   addEdge(graph, 3, 1);

   addEdge(graph, 4, 1);
   addEdge(graph, 4, 3);
   addEdge(graph, 4, 9);
   addEdge(graph, 4, 8);
   addEdge(graph, 4, 6);

   addEdge(graph, 5, 0);
   addEdge(graph, 5, 6);
   addEdge(graph, 5, 1);

   addEdge(graph, 6, 7);
   addEdge(graph, 6, 5);
   addEdge(graph, 6, 4);
   addEdge(graph, 6, 8);
   addEdge(graph, 6, 10);

   addEdge(graph, 7, 6);
   addEdge(graph, 7, 10);

   addEdge(graph, 8, 6);
   addEdge(graph, 8, 9);
   addEdge(graph, 8, 4);
   addEdge(graph, 8, 10);

   addEdge(graph, 9, 8);
   addEdge(graph, 9, 4);
   addEdge(graph, 9, 3);
   addEdge(graph, 9, 10);      


    printGraph(graph);

    // bfs(graph, 0);
    
    return 0;
}
