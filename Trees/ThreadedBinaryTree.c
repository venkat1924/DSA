//Doesn't work, but the idea is solid
#include <stdio.h>

typedef struct node {
    int data;
    int lflag, rflag; //  0->no children, 1-> has children
    struct node *left, *right;
} NODE;

void inorder(NODE* head) {
    NODE *temp = head->left; // head->left is the root node

    // Finding the leftmost node
    while(temp->lflag != 0)
        temp = temp->left;

    // Traverse the threaded tree using threads
    while(temp != head) {
        printf("%d ", temp->data);

        if(temp->rflag == 1) // If there's a thread
            temp = temp->right; // Move to inorder successor
        else // If there's a right child
        {
            temp = temp->right; // Move to right child
            while(temp->lflag == 1) // Traverse until reaching the leftmost node
                temp = temp->left;
        }
    }
}

int main() {
    // Sample tree creation
    NODE n1 = {1, 1, 1, NULL, NULL};
    NODE n2 = {2, 1, 1, NULL, NULL};
    NODE n3 = {3, 0, 0, NULL, NULL};
    NODE n4 = {4, 1, 0, NULL, NULL};
    NODE n5 = {5, 0, 1, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n1;
    n3.left = &n1;
    n3.right = &n5;
    n5.right = &n3;

    // Thread the nodes with no right child
    n2.rflag = 1;
    n4.rflag = 1;
    n5.rflag = 1;

    NODE head = {0, 0, 0, &n1, &n1};

    printf("Inorder Traversal: ");
    inorder(&head);
    printf("\n");

    return 0;
}
