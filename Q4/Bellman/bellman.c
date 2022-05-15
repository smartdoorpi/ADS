
#include <stdio.h>
#include <stdlib.h>



struct Edge {
  int u;  //start vertex
  int v;  //end vertex
  int w;  //weight
};
struct Graph {
  int V;        //total number of vertices
  int E;        //total number of edges
  struct Edge *edge;  
};

void bellmanford(struct Graph *g, int source);
void print(int arr[], int size);

int main(void) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = 4;  //total vertices
  graph->E = 5;  //total edges

  graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
  graph->edge[0].u = 0;
  graph->edge[0].v = 2;
  graph->edge[0].w = 4;

  graph->edge[1].u = 0;
  graph->edge[1].v = 1;
  graph->edge[1].w = 6;

  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 4;

  graph->edge[3].u = 2;
  graph->edge[3].v = 2;
  graph->edge[3].w = 4;

  graph->edge[4].u = 3;
  graph->edge[4].v = 4;
  graph->edge[4].w = 2;

  bellmanford(graph, 0);  //0 is the source vertex

  return 0;
}

void bellmanford(struct Graph *graph, int source) {
  int i, j, u, v, w;
  int gV = graph->V;
  int gE = graph->E;
  int d[gV];
  int p[gV];
  for (i = 0; i < gV; i++) {
    d[i] = 99999;
    p[i] = 0;
  }
  d[source] = 0;
  for (i = 1; i <= gV - 1; i++) {
    for (j = 0; j < gE; j++) {
      u = graph->edge[j].u;
      v = graph->edge[j].v;
      w = graph->edge[j].w;

      if (d[u] != 99999 && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }
  for (i = 0; i < gE; i++) {
    u = graph->edge[i].u;
    v = graph->edge[i].v;
    w = graph->edge[i].w;
    if (d[u] != 99999 && d[v] > d[u] + w) {
      printf("Negative weight cycle found!\n");
      return;
    }
  }

  printf("Distance array: ");
  print(d, gV);
  printf("Predecessor array: ");
  print(p, gV);
  printf("No negative weight cycle found!\n ");
}

void print(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
