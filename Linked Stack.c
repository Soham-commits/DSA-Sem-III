
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void push(int val) {
    struct Node *temp =
        malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Overflow\n");
        return;
    }

    temp->data = val;
    temp->link = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = top;
    int val = temp->data;

    top = top->link;
    free(temp);

    printf("Popped: %d\n", val);
}

void display() {
    struct Node *temp = top;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }

    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    return 0;
}
