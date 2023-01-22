#include <stdio.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int knapsack(int maxcap, int wt[], int profit[], int n) {
  int i, w;
  int bag[n + 1][maxcap + 1];
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= maxcap; w++) {
      if (i == 0 || w == 0) bag[i][w] = 0;
      else if (wt[i - 1] <= w) {
        // include
        bag[i][w] = max(profit[i - 1] + bag[i - 1][w - wt[i - 1]], bag[i - 1][w]);
      } else {
        bag[i][w] = bag[i - 1][w];
      }
    }
  }
  return bag[n][maxcap];
}

int main() {
  int i, n, profit[20], wt[20], maxcap;
  printf("Enter number of items : ");
  scanf("%d", &n);
  printf("Enter Profit : \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &profit[i]);
  }
  printf("Enter Weight \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &wt[i]);
  }
  printf("\n Enter size of knapsack : ");
  scanf("%d", &maxcap);
  printf("%d", knapsack(maxcap, wt, profit, n));
  return 0;
}