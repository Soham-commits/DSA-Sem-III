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

void shellSort(Array *array) {
  int i, j, gap, key;

  for (gap = array->size / 2; gap > 0; gap = gap / 2) {
    for (i = gap; i < array->size; i++) {
      key = array->elements[i];
      j = i;

      while (j >= gap && array->elements[j - gap] > key) {
        array->elements[j] = array->elements[j - gap];
        j = j - gap;
      }

      array->elements[j] = key;
    }
  }
}

int main(void) {
  Array array = {{0}, 0};
  int choice;

  do {
    printf("\n1. Accept array");
    printf("\n2. Display array");
    printf("\n3. Shell sort");
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
      printf("\nBefore sorting:");
      display(&array);
      shellSort(&array);
      printf("\nAfter sorting:");
      display(&array);
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
