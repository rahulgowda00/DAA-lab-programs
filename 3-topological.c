#include <stdio.h>
int main() {
    int count = 0;
    int arr[10][10];
    printf("\n Enter number of vertex : ");
    int n;
    scanf("%d", &n);
    printf("\n Adjacency Matrix : ");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int indegree[10], vis[10];
    // set indegree and visited to 0
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        vis[i] = 0;
    }
    // calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indegree[i] += arr[j][i];
        }
    }

    // check
    int k;
    while (count < n) {
        for (int k = 0; k < n; k++) {
            if (indegree[k] == 0 && vis[k] == 0) {
                printf("%d ", (k + 1));
                vis[k] = 1;
            }
            // update indegree
            for (int i = 0; i < n; i++) {
                if (arr[i][k] == 1) { // if already visited that indegree
                    indegree[k]--;
                }
            }
        }
        count++;
    }
}