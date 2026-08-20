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

void insertionSort(int n, int a[n]) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = a[i];
    j = i - 1;

    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = key;
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

  insertionSort(n, a);

  printf("\nAfter sorting:");
  display(n, a);

  return 0;
}