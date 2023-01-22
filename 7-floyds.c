#include <stdio.h>
int min(int a, int b) {
  if (a < b) return a;
  else {
    return b;
  }
}

void floyd(int arr[10][10], int n) {
  int i,j,k;
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (i == j) arr[i][j] = 0;
        else {
          arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        }

      }  
    }
  }
}

int main() {
  int arr[10][10], n, i, j;
  printf("Enter number of vertices : \n");
  scanf("%d", &n);
  printf("\n Enter matrix : \n");

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  floyd(arr, n);
  printf("Output matrix : \n");

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      printf("%d \t", arr[i][j]);
    }
    printf("\n");
  }

  // shortest path (output matrix except the same i and j)
  printf("Shortest paths are : \n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i != j) { // print all except i = j (1,1 || 2,2 etc)
        printf("\n <%d %d> =  %d", i, j, arr[i][j]);
      }
    }
  }

  return 0;
}