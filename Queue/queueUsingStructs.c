#include <stdio.h>
#define SIZE 20

typedef struct queue
{
    int front, rear;
    int data [SIZE];
} QUEUE;

void enqueue (QUEUE* q, int item)
{
    if (q->rear == SIZE-1)
        printf("Queue full.\n");
    else
    {
        q->data[++(q->rear)]=item;
        if (q->front == -1)
            q->front=0;
    }
}

int dequeue (QUEUE* q)
{
    if (q->front == -1)
        printf("Queue is empty.\n");
    else
    {
        int item = q->data[q->front];
        
        if (q->front == q->rear)
            q->front=q->rear=-1;
        else
            ++(q->front);
        return item;
    }
}

void display(QUEUE* q)
{
    if (q->front==-1)
        printf("Queue is empty.\n");
    else 
    {
        for (int i=q->front; i<=q->rear; i++)
            printf("%d ", q->data[i]);
        printf("\n");
    }
}

int main()
{
    QUEUE q;
    q.front=q.rear=-1;
    int ch, item;
    
    while(1)
    {
        printf("1)Insert\n2)Delete\n3)Display\n4)Exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &item);
                    enqueue(&q, item);
                    break;
                    
            case 2: printf("Item deleted is: %d\n", dequeue(&q));
                    break;
                    
            case 3: printf("Elements are: ");
                    display(&q);
                    break;
            case 4: return 0;
        }
    }
    
}
