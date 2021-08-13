#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

typedef struct {
    int items[SIZE];
    int front; //frente
    int rear; //traseira
}Queue;

typedef struct node {
    int vertex;
    struct node *next;
}Node;

typedef struct
{
    int numVertices;
    Node** adjList;
    int* visited;
}Graph;

Node* createNode(int v)
{
    Node* new = malloc(sizeof(Node));
    new->vertex = v;
    new->next = NULL;
    return new;
}

Queue* createQueue()
{
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q)
{
    if (q->rear == -1) return 1;
    else return 0;
}

void printQueue(Queue* q)
{
    if (isEmpty(q))
        printf("Queue is empty");
    else{
        printf("\nQueue contains \n");
        for (int i = q->front; i < q->rear +1; i++)
            printf("%d ", q->items[i]);
        printf("\n");
    }
}

int dequeue(Queue* q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resettin queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void enqueue(Queue* q, int value)
{
    // printf("\nvalue: %d\n", value);
    if (q->rear == SIZE -1)
        printf("Full queue\n");
    else {
        if (q->front == -1) //vazia
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

void bfs(Graph* graph, int startVertex)
{
    printf("start vertex: %d\n", startVertex);
    
    Queue* q = createQueue(); //recebe os vertices adjacentes
    graph->visited[startVertex] = 1;

    enqueue(q, startVertex); //vertices adjacentes

    while (!(isEmpty(q)))
    {
        printQueue(q);
        int currentVertex = dequeue(q); //tira da fila
        printf("Visited %d\n", currentVertex); //diz que visitou

        Node* temp = graph->adjList[currentVertex]; //adjacente ao visitado
        // printf("vertex temp %d \n", temp->vertex);

        while(temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) 
            {
                graph->visited[adjVertex] = 1; 
                // printf("while interno: ");
                enqueue(q, adjVertex); //põe na fila todos os adjacentes não adicionados, pra depois ir desenfileirando
            }
            temp = temp->next; //proximo
        }
    }
        
}

void addEdge(Graph* graph, int src, int dest)
{
    //src -> dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    //dest -> src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

Graph* CreateGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    graph->adjList = malloc(vertices * sizeof(Node)); //vertices adjacentes
    graph->visited = malloc(sizeof(vertices * sizeof(int))); //vertices visitados (0 ou 1)

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void printGraph(Graph* graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        Node* atual = graph->adjList[v];
        printf("\n Lista de adjacência do vértice %d\n head ", v);
        while (atual)
        {
            printf("-> %d ", atual->vertex);
            atual = atual->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph* graph = CreateGraph(11);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);

    printGraph(graph);

    bfs(graph, 10);
    
    return 0;
}
