#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int elements[MAX_SIZE];
  int size;
} Array;

void accept(Array *array) {
  int i;

  printf("Enter the elements:\n");

  for (i = 0; i < array->size; i++)
    scanf("%d", &array->elements[i]);
}

void display(const Array *array) {
  int i;

  printf("\nArray: ");

  for (i = 0; i < array->size; i++)
    printf("%d ", array->elements[i]);

  printf("\n");
}

int linearSearch(const Array *array, int key) {
  int i;

  for (i = 0; i < array->size; i++) {
    if (array->elements[i] == key)
      return i;
  }

  return -1;
}

int main(void) {
  int choice, key, p;
  Array array = {{0}, 0};

  do {
    printf("\n1. Accept array");
    printf("\n2. Display array");
    printf("\n3. Linear search");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter number of elements: ");
      scanf("%d", &array.size);
      accept(&array);
      break;
    case 2:
      display(&array);
      break;
    case 3:
      printf("Enter element to search: ");
      scanf("%d", &key);
      p = linearSearch(&array, key);
      if (p == -1)
        printf("Element not found\n");
      else
        printf("Element found at position %d\n", p + 1);
      break;
    case 4:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice.\n");
    }
  } while (choice != 4);

  return 0;
}
