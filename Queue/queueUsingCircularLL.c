
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
typedef struct {
    struct Node *front, *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to insert an element at the rear of the queue
void enqueue(Queue* q, int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;

    if (isEmpty(q)) {
        q->front = temp;
    } else {
        q->rear->next = temp;
    }

    q->rear = temp;
    q->rear->next = q->front;
}

// Function to delete an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item;
    if (q->front == q->rear) {
        item = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        item = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return item;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp->next != q->front) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q,40);
    display(q);

    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    printf("Dequeued item: %d\n", dequeue(q));
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}
