#include <stdio.h>
#define SIZE 100

void enqueue(int *inp_arr, int *Rear, int *Front);
void dequeue(int *inp_arr, int *Rear, int *Front);
void display(int *inp_arr, int *Rear, int *Front);

int main() {
    int inp_arr[SIZE];
    int Rear = -1;
    int Front = -1;
    int ch;

    while (1) {
        printf("Enter your choice of operations : \n 1)Enqueue \n 2)Dequeue \n 3)Display \n 4)Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue(inp_arr, &Rear, &Front);
                break;
            case 2:
                dequeue(inp_arr, &Rear, &Front);
                break;
            case 3:
                display(inp_arr, &Rear, &Front);
                break;
            case 4:
                return 0;
            default:
                printf("Incorrect choice \n");
        }
    }
}

void enqueue(int *inp_arr, int *Rear, int *Front) {
    int insert_item;
    if (*Rear == SIZE - 1)
        printf("Overflow \n");
    else {
        if (*Front == -1)
            *Front = 0;
        printf("Element to be inserted in the Queue: ");
        scanf("%d", &insert_item);
        *Rear = *Rear + 1;
        inp_arr[*Rear] = insert_item;
    }
}

void dequeue(int *inp_arr, int *Rear, int *Front) {
    if (*Front == -1 || *Front > *Rear) {
        printf("Underflow \n");
        return;
    } else {
        printf("Element deleted from the Queue: %d\n", inp_arr[*Front]);
        *Front = *Front + 1;
    }
}

void display(int *inp_arr, int *Rear, int *Front) {
    if (*Front == -1)
        printf("Empty Queue \n");
    else {
        printf("Queue: \n");
        for (int i = *Front; i <= *Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
