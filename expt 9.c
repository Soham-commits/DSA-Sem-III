#include <stdio.h>

#define SIZE 5

typedef struct
{
    int data[SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

void enqueue(CircularQueue *queue, int value)
{
    if (queue->count == SIZE)
    {
        printf("Queue is full.\n");
        return;
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % SIZE;
    queue->count++;
}

void dequeue(CircularQueue *queue)
{
    if (queue->count == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deleted: %d\n", queue->data[queue->front]);
    queue->front = (queue->front + 1) % SIZE;
    queue->count--;
}

void display(const CircularQueue *queue)
{
    if (queue->count == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = 0; i < queue->count; i++)
        printf("%d ", queue->data[(queue->front + i) % SIZE]);
    printf("\n");
}

int main(void)
{
    CircularQueue queue = {0};
    int choice, value;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
