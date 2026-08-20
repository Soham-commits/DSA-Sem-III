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

void selectionSort(int n, int a[n]) {
  int i, j, p, temp;

  for (i = 0; i < n - 1; i++) {
    p = i;

    for (j = i + 1; j < n; j++) {
      if (a[j] < a[p])
        p = j;
    }

    temp = a[i];
    a[i] = a[p];
    a[p] = temp;
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

  selectionSort(n, a);

  printf("\nAfter sorting:");
  display(n, a);

  return 0;
}