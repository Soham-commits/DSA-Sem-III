
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void initialize() {
    front = malloc(sizeof(struct Node));
    if (front == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    front->next = NULL;
}

void enqueue(int x) {
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Overflow\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (front->next == NULL) {
        front->next = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front->next == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = front->next;
    int x = temp->data;

    front->next = temp->next;

    if (front->next == NULL)
        rear = NULL;

    free(temp);
    printf("Deleted: %d\n", x);
}

void display() {
    struct Node *temp = front->next;

    if (temp == NULL) {
        printf("Queue Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    initialize();

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
