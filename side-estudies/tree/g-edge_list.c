#include <stdio.h>
#include <stdlib.h>

typedef struct 
{ //como inteiros, armazeno os índices
  int startVertex;
  int endVertex;
  //int weight; //pra ter um peso
} Edge;

typedef struct node {
  Edge edges;
  struct node *next;
}No;

typedef struct {
  No *head;
} Lista;

Edge ler_edge()
{
  Edge n;
  printf("start: ");
  scanf(" %d", &n.startVertex);
  printf("end: ");
  scanf(" %d", &n.endVertex);

  return n;
}

void add(Lista *E, Edge n)
{
    No* novo = malloc(sizeof(No));
    
    novo->edges = n;
    
    if (E->head == NULL)
    {
        novo->next = E->head;
        E->head = novo;
        return;
    }
    No *i = E->head;
    
    while (i->next != NULL)
        i = i->next;
    
    i->next = novo;
    novo->next = NULL;
    return;
}


int main()
{
  char Vertex[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  Lista EdgeList;
  EdgeList.head = NULL;

  int n;
  printf("Insira: ");
  scanf("%d", &n);
  while (n != 0)
  {
    Edge novo = ler_edge();
    add(&EdgeList, novo);
  }


  return 0;
}

//edge list
/*
Uma lista de vértices e uma de conexões
*/


/*
A graph G is an ordered pair
of a set V of vertices and 
a set E of edges.
    G = (V, E)

V são os nós.
E são as ligações

Edges podem ser direcionados 
(u, v) == u -> v
(v, u) == v -> u

ou não direcionados
{u, v} == u -- v == {v, u}

No weighted graph, os edges têm valores associados,
pesos. 

a --> b --> c --> d
  200   150   80

self loop: um nó se referir a si mesmo
multiedge: a - b
             -
           a -> b
             ->

Number of edges:
    V = {v1, v2, v3, v4}
    |V| = 4
Cada nó pode ter edge para todo o resto
v1 -> v2
   -> v3
   -> v4

0 <= |E| <= n(n-1) if directed
0 <= |E| <= (n(n-1))/2 if not directed

Path :- a sequence of vertices 
where each adjacent pair 
is connected by and edge.

Simple Path :- a [WALK] in wich
no vertices (and thus no edges)
are repeated

Trail :- a walk in wich no edges are repeated

<A, B, F, H>
<A, B, F, H, E, B, A, D>

Closed walk :- starts and ends at 
same vertex
Simple cycle :- no repetition other than start and end
*/