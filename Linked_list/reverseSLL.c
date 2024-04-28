#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} NODE;

NODE* getNode(int value)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if (temp == NULL)
        exit(42);
    else
    {
        temp->data = value;
        temp->next = NULL;
        return temp;
    }
}

NODE* insertEnd(int value, NODE* head)
{
    NODE* temp = getNode(value);

    if (head == NULL)
        return temp;
    else
    {
        NODE* cur = head;

        while (cur->next != NULL)
            cur = cur->next;

        cur->next = temp;
        return head;
    }
}

NODE* reverseList(NODE* head)
{
    NODE *prev = NULL, *cur = head, *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void printList(NODE* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    NODE* head = NULL;
    head = insertEnd(1, head);
    head = insertEnd(2, head);
    head = insertEnd(3, head);
    head = insertEnd(4, head);
    head = insertEnd(5, head);

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
