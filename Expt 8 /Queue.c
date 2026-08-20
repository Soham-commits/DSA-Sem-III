#include <stdio.h>

#define MAX 5

int jobID[MAX];
char title[MAX][50];

int front = -1;
int rear = -1;

void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    printf("Enter Job ID: ");
    scanf("%d", &jobID[rear]);

    printf("Enter Document Title: ");
    scanf(" %[^\n]", title[rear]);

    printf("Print Job Added!\n");
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Processing Job: %d - %s\n",
           jobID[front], title[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    int i = front;

    printf("\nPending Print Jobs:\n");

    while (1) {
        printf("%d - %s\n", jobID[i], title[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Print Job");
        printf("\n2. Process Print Job");
        printf("\n3. Display Pending Jobs");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}