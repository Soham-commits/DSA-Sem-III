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

int linearSearch(int n, int a[n], int key) {
  int i;

  for (i = 0; i < n; i++) {
    if (a[i] == key)
      return i;
  }

  return -1;
}

int main() {
  int n, key, p;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int a[n];

  accept(n, a);

  display(n, a);

  printf("Enter element to search: ");
  scanf("%d", &key);

  p = linearSearch(n, a, key);

  if (p == -1)
    printf("Element not found");
  else
    printf("Element found at position %d", p + 1);

  return 0;
}