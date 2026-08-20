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

void selectionSort(Array *array) {
  int i, j, p, temp;

  for (i = 0; i < array->size - 1; i++) {
    p = i;

    for (j = i + 1; j < array->size; j++) {
      if (array->elements[j] < array->elements[p])
        p = j;
    }

    temp = array->elements[i];
    array->elements[i] = array->elements[p];
    array->elements[p] = temp;
  }
}

int main(void) {
  Array array = {{0}, 0};
  int choice;

  do {
    printf("\n1. Accept array");
    printf("\n2. Display array");
    printf("\n3. Selection sort");
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
      selectionSort(&array);
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
