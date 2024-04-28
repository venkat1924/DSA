A binary search tree with no `NULL` in it.

1. Left-threaded binary tree: the left NULL is replaced with the address of the predecessor
2. Right-threaded binary tree: the right NULL is replaced with the address of the successor
3. Complete binary tree: left NULL replaced by predecessor and right NULL by successor

Predecessor and successor here refers to the preceding and succeeding element in:
1. Inorder:
    1. the head node will have its left child as the root node
    2. its right child pointing to itself (in an inorder left-threaded BT)
    3. the first element in the inorder traversal will point to the head node if its left child is NULL
3. Preorder
4. Postorder

Example: inorder left-threaded binary tree, postorder complete threaded binary tree

