#include <stdio.h>

void accept(int n, int a[n]) {
  int i;

  printf("Enter the elements:\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void display(int n, int a[n]) {
  int i;

  printf("\nArray: ");

  for (i = 0; i < n; i++)
    printf("%d ", a[i]);

  printf("\n");
}

void shellSort(int n, int a[n]) {
  int i, j, gap, key;

  for (gap = n / 2; gap > 0; gap = gap / 2) {
    for (i = gap; i < n; i++) {
      key = a[i];
      j = i;

      while (j >= gap && a[j - gap] > key) {
        a[j] = a[j - gap];
        j = j - gap;
      }

      a[j] = key;
    }
  }
}

int main() {
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int a[n];

  accept(n, a);

  printf("\nBefore sorting:");
  display(n, a);

  shellSort(n, a);

  printf("\nAfter sorting:");
  display(n, a);

  return 0;
}