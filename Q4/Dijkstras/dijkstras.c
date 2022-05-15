// Dijkstra's Algorithm in C

#include <stdio.h>

void Dijkstra(int Graph[10][10], int n, int start);

void Dijkstra(int Graph[10][10], int n, int start) {
  int travel_cost[10][10], dist[10], pred[10];
  int visited[10], c, min_dist, nextnode, i, j;

for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        travel_cost[i][j] = 9999;
      else
        travel_cost[i][j] = Graph[i][j];
}
for (i = 0; i < n; i++) {
    dist[i] = travel_cost[start][i];
    pred[i] = start;
    visited[i] = 0;
}

  dist[start] = 0;
  visited[start] = 1;
  c = 1;

  while (c < n - 1) {
    min_dist = 9999;

    for (i = 0; i < n; i++)
      if (dist[i] < min_dist && !visited[i]) {
        min_dist = dist[i];
        nextnode = i;
      }

  visited[nextnode] = 1;
  for (i = 0; i < n; i++)
      if (!visited[i])
        if (min_dist + travel_cost[nextnode][i] < dist[i]) {
          dist[i] = min_dist + travel_cost[nextnode][i];
          pred[i] = nextnode;
        }
        c++;
  } 

  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, dist[i]);
      printf("\nRoute=%d",i);
      j=i;
      do
      {
          j=pred[j];
          printf("<-%d",j);
      }while(j!=start);
    } 
}
int main() {
  int Graph[10][10], i, j, n, u;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 2;
  Graph[0][3] = 1;
  Graph[0][4] = 2;
  Graph[0][5] = 1;
  Graph[0][6] = 1;

  Graph[1][0] = 1;
  Graph[1][1] = 0;
  Graph[1][2] = 1;
  Graph[1][3] = 2;
  Graph[1][4] = 3;
  Graph[1][5] = 1;
  Graph[1][6] = 2;

  Graph[2][0] = 4;
  Graph[2][1] = 1;
  Graph[2][2] = 3;
  Graph[2][3] = 1;
  Graph[2][4] = 4;
  Graph[2][5] = 1;
  Graph[2][6] = 0;

  Graph[3][0] = 1;
  Graph[3][1] = 3;
  Graph[3][2] = 4;
  Graph[3][3] = 1;
  Graph[3][4] = 2;
  Graph[3][5] = 3;
  Graph[3][6] = 6;

  Graph[4][0] = 1;
  Graph[4][1] = 0;
  Graph[4][2] = 2;
  Graph[4][3] = 3;
  Graph[4][4] = 1;
  Graph[4][5] = 2;
  Graph[4][6] = 4;

  Graph[5][0] = 1;
  Graph[5][1] = 3;
  Graph[5][2] = 4;
  Graph[5][3] = 2;
  Graph[5][4] = 5;
  Graph[5][5] = 1;
  Graph[5][6] = 6;

  Graph[6][0] = 1;
  Graph[6][1] = 0;
  Graph[6][2] = 2;
  Graph[6][3] = 4;
  Graph[6][4] = 1;
  Graph[6][5] = 1;
  Graph[6][6] = 3;

  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}
