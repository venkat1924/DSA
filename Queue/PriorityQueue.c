#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node in the priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Define the priority queue structure
typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    return pq;
}

// Function to enqueue a new element with a given priority
void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);

    // If the queue is empty or the new element has higher priority than the front
    if (pq->front == NULL || priority > pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        // Traverse the queue to find the right position for the new element
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to dequeue the element with the highest priority
int dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty.\n");
        return -1; // Return a default value indicating an empty queue
    }

    Node* temp = pq->front;
    int data = temp->data;
    pq->front = temp->next;
    free(temp);

    return data;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->front == NULL;
}

// Function to print the elements in the priority queue
void printPriorityQueue(PriorityQueue* pq) {
    Node* current = pq->front;
    while (current != NULL) {
        printf("Data: %d, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(PriorityQueue* pq) {
    Node* current = pq->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(pq);
}

int main() {
    // switch case to access and edit priority queue
    PriorityQueue* pq = createPriorityQueue();
 int d,p,ch;
 while(1){
     printf("Enter choice here:\n 1.enter data element to queue\n 2.dequeue \n 3.print queue \n 4.exit ");
     scanf("%d",&ch);
     switch(ch){
         
    case 1:
    printf("Enter the data element and its priority to be entered:");
    scanf("%d%d",&d,&p);
    enqueue(pq,d,p);
    break;
    
    case 2:
     printf("Dequeue: %d\n", dequeue(pq));
     printf("Priority Queue after dequeue:\n");
    printPriorityQueue(pq);

    freePriorityQueue(pq);
     break;
     
     case 3:
     printf("Priority Queue:\n");
    printPriorityQueue(pq);
    break;
    
    case 4:
    exit(0);
    break;
    
    default:
    printf("Invalid choice: try again");
    break;
    
    
     }
 }
    return 0;
}
