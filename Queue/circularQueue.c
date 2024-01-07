#include <stdio.h>
#include <stdlib.h>

#define size 100
int q[size];
int f, r = -1;

void enqueue(int item);
int dequeue();
void display();

int main() {
    int choice, item;

    while (1) {
        printf("Enter your choice:\n 1. enqueue\n 2. dequeue\n 3. display\n 4. exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to be added to queue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void enqueue(int item) {
    if ((r + 1) % size == f) {
        printf("Queue is full\n");
    } else {
        r = (r + 1) % size;
        q[r] = item;
        if (f == -1) {
            f = 0;
        }
    }
}

int dequeue() {
    int temp;
    if (f == -1) {
        printf("Queue is empty\n");
        return -1;
    } else if (f == r) {
        temp = q[f];
        f = -1;
        r = -1;
    } else {
        temp = q[f];
        f = (f + 1) % size;
    }
    return temp;
}

void display() {
    int i;
    if (f == -1) {
        printf("Queue empty\n");
    } else {
        for (i = f; i != (r + 1) % size; i = (i + 1) % size) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}
