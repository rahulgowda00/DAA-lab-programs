#include <stdio.h>

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void merge(int arr[], int s, int m, int e) {
  // main logic -> take temp array of same size, and compare elements and merge into the temp array
  int temp[e - s + 1];
  int i = s, j = m + 1, k = 0; // 1 starts from 0 and other from mid
  while (i <= m && j <= e) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  // remaining elements in i
  while (i <= m) {
      temp[k++] = arr[i++];
  }
  
  // remaining elements in j
  while (j <= e) {
      temp[k++] = arr[j++];
  }
  // copy back to og arr

  for (int i = s; i <= e; i++) {
    arr[i] = temp[i - s];
  }
}

void ms(int arr[], int s, int e) {
  if (s < e) {
    int m = (s + e) / 2;
    ms(arr, s, m);
    ms(arr, m + 1, e);
    merge(arr, s, m, e);
  }
}


int main() {
  int arr[] = {4,0,3,1};
  int size = 4;
  ms(arr, 0, size - 1);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}