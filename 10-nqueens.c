#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char board[20][20];
int n;

void display() {
  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c \t", board[i][j]);
    }
    printf("\n\n");
  }
}

int getmarkedcolumn(int row) {
  for (int i = 0; i < n; i++) {
    if (board[row][i] == 'Q') {
      return i;
      break;
    }
  }
  return -999; // not feasible
}

int feasible(int row, int col) {
  int c2;
  for (int i = 0; i < n; i++) {
    c2 = getmarkedcolumn(i);
    if (col == c2 || abs(row - i) == abs(col - c2)) return 0; // cant be placed
  }
  return 1; // can place queen
}

void nqueen(int row) {
   int i, j;
   if (row < n) {
      for (i = 0; i < n; i++) {
         if (feasible(row, i)) {
            board[row][i] = 'Q';
            nqueen(row + 1);
            board[row][i] = '.';
         }
      }
   } else {
      printf("\nThe solution is:- ");
      display();
   }
}
 

int main() {
  printf("\n Enter the number of queens : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = '.';
    }
  }
  nqueen(0); // run code from 0th
  return 0;
}