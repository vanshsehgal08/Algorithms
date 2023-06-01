#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
int isEmpty(struct Queue* queue);
void display(struct Queue* queue);

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    int choice, value;

    while (1) {
        printf("\nLinear Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid menu option.\n");
        }
    }

    return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue any more elements.\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Enqueued value: %d\n", value);
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue any more elements.\n");
        return -1;
    }

    int value = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return value;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear)
        return 1;
    else
        return 0;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->items[i]);
    printf("\n");
}
