#include <stdio.h>

#define QUEUE_SIZE 10
#define TITLE_LENGTH 100

typedef struct
{
    int jobId;
    char title[TITLE_LENGTH];
} PrintJob;

typedef struct
{
    PrintJob jobs[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

void enqueue(CircularQueue *queue)
{
    if (queue->count == QUEUE_SIZE)
    {
        printf("Print queue is full.\n");
        return;
    }
    printf("Enter job ID: ");
    scanf("%d", &queue->jobs[queue->rear].jobId);
    printf("Enter document title: ");
    scanf(" %99[^\n]", queue->jobs[queue->rear].title);
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->count++;
    printf("Print job added.\n");
}

void dequeue(CircularQueue *queue)
{
    if (queue->count == 0)
    {
        printf("No pending print jobs.\n");
        return;
    }
    printf("Processing job %d: %s\n", queue->jobs[queue->front].jobId,
           queue->jobs[queue->front].title);
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->count--;
}

void displayQueue(const CircularQueue *queue)
{
    if (queue->count == 0)
    {
        printf("No pending print jobs.\n");
        return;
    }
    printf("\nPending print jobs:\n");
    for (int i = 0; i < queue->count; i++)
    {
        int index = (queue->front + i) % QUEUE_SIZE;
        printf("Job ID: %d | Document: %s\n", queue->jobs[index].jobId,
               queue->jobs[index].title);
    }
}

int main(void)
{
    CircularQueue queue = {.front = 0, .rear = 0, .count = 0};
    int choice;
    do
    {
        printf("\n--- Printer Queue Manager ---\n");
        printf("1. Add a print job\n2. Process a print job\n3. Display pending jobs\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&queue);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            displayQueue(&queue);
            break;
        case 4:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
