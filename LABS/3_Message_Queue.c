#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct queue
{
    int front, rear;
    char data[SIZE][20];
};

typedef struct queue QUEUE;

void send(QUEUE *q, char item[20])
{
    if (q->front == (q->rear + 1) % SIZE)
        printf("\n Queue full");
    else
    {
        q->rear = (q->rear + 1) % SIZE;
        strcpy(q->data[q->rear], item);
        
        if (q->front == -1)
            q->front = 0;
    }
}

char *receive(QUEUE *q)
{
    char *del;
    
    if (q->front == -1)
    {
        printf("\n Queue empty");
        return NULL;
    }
    else
    {
        del = q->data[q->front];
        
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % SIZE;
        }
        
        return del;
    }
}

void display(QUEUE q)
{
    int i;
    
    if (q.front == -1)
        printf("\n Queue Empty");
    else
    {
        printf("\n Queue content are\n");
        
        for (i = q.front; i != q.rear; i = (i + 1) % SIZE)
            printf("%s\n", q.data[i]);
        
        printf("%s\n", q.data[i]);
    }
}

int main()
{
    int ch;
    char *del;
    char item[20];
    QUEUE q;
    
    q.front = -1;
    q.rear = -1;
    
    for (;;)
    {
        printf("\n1. Send\n2. Receive\n3. Display\n4. Exit");
        printf("\nRead Choice :");
        scanf("%d", &ch);
        getchar();
        
        switch (ch)
        {
            case 1:
                printf("\n Read msg to be send :");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = '\0'; // Remove trailing newline
                send(&q, item);
                break;
                
            case 2:
                del = receive(&q);
                
                if (del != NULL)
                    printf("\n Element deleted is %s\n", del);
                
                break;
                
            case 3:
                display(q);
                break;
                
            default:
                exit(0);
        }
    }
    
    return 0;
}
