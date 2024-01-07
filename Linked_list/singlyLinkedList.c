#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Global variable for the header node
struct Node *header = NULL;

// Function to create a new node with given data
struct Node* getNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to free a node from memory
void freeNode(struct Node *node) {
    free(node);
}

// Function to insert a node in an ordered manner
void insert(int value) {
    struct Node *newNode = getNode(value);

    if (header == NULL || header->data >= value) {
        newNode->next = header;
        header = newNode;
    } else {
        struct Node *current = header;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node with given data
void deleteNode(int value) {
    if (header == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = header;
    struct Node *prev = NULL;

    if (temp->data == value) {
        header = temp->next;
        freeNode(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    freeNode(temp);
}

// Function to display the linked list
void display() {
    struct Node *current = header;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main() {
    int choice, value;

    while (1) {
        printf("\nOperations on Ordered Singly Linked List:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
