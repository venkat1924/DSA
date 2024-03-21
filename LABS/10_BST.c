#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE create_node(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE Insertbst(NODE root, int item) {
    if (root == NULL)
        return create_node(item);
    
    if (item < root->data)
        root->left = Insertbst(root->left, item);
    else
        root->right = Insertbst(root->right, item);
    
    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

NODE inordersuccessor(NODE root) {
    NODE cur = root;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
}

NODE deletenode(NODE root, int key) {
    if (root == NULL)
        return root;
    
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL) {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE temp = root->left;
            free(root);
            return temp;
        }
        NODE temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main() {
    NODE root = NULL;
    int ch, item, key;
    
    for (;;) {
        printf("\n1. Insert");
        printf("\n2. Preorder");
        printf("\n3. Inorder");
        printf("\n4. Postorder");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\nRead your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nRead element to be inserted: ");
                scanf("%d", &item);
                root = Insertbst(root, item);
                break;
            case 2:
                printf("\nThe Preorder traversal is\n");
                preorder(root);
                break;
            case 3:
                printf("\nThe Inorder traversal is\n");
                inorder(root);
                break;
            case 4:
                printf("\nThe Postorder traversal is\n");
                postorder(root);
                break;
            case 5:
                printf("\nRead node to be deleted: ");
                scanf("%d", &key);
                root = deletenode(root, key);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
