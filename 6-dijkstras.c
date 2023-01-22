#include <stdio.h>

int main() {
  int n, cost[20][20], i, j , u, source, visited[10], distance[10], k;
  printf("Enter number of vertices ");
  scanf("%d", &n);
  printf("\n Enter adj matrix ");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  
  printf("Enter source vertex : ");
  scanf("%d", &source);
  for (i = 1; i <= n; i++) {
    visited[i] = 0;
    distance[i] = cost[source][i]; // calculating indegree (from source -> i calc all distances)
  }
  distance[source] = 0; // dist from source -> source will always be 0
  visited[source] = 1;

  // for remaining n^2
  for (k = 2; k <= n; k++) {
    int min = 999;
    // find min
    for (i = 1; i <= n; i++) {
      if (distance[i] < min && visited[i] == 0) {
        min = distance[i];
        u = i; // for next
      }
    }
    // mark u as visited
    visited[u] = 1;
    // calculate shortest path
    for (i = 1; i <= n; i++) {
      if (visited[i] == 0) {
        if (distance[u] + cost[u][i] < distance[i]) {
          distance[i] = distance[u] + cost[u][i];
        }
      }
    }
  }

  // print
  for (i = 1; i <= n; i++) {
    printf("%d -> %d = %d\n", source, i, distance[i]); // from source to all vertices
  }
  return 0;
}