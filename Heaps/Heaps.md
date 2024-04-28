A heap is a binary tree that satisfies two properties:
1. **Structural Property**:
    1. It is an almost complete binary tree. Level i has $2^i$ nodes.
    2. The nodes are inserted from left to right (left-filled)
    3. The last level will never be fully filled.
2. **Parental Dominance**: Every node will be more _dominant_ than its children node. The manner of dominance depends on the type of heap.
    1. In a max heap, each node is greater in value than all its children nodes.
    2. In a min heap, each node is smaller in value than all its children nodes.

# Heap Construction
## Bottom-Up Approach
1. Construct a binary tree for the given elements.
2. From the last level, go upwards checking if the parent nodes at every level are greater/smaller than its children nodes.
3. If necessary, swap appropriately. When a swap is performed between two nodes, recheck the subtree with the swapped node as root.
## Top-Down Approach
1. Add each node in the leaf layer from the left (left filled property), and swap it upwards into its correct spot.
2. This way, instead of constructing a binary tree and converting it into a heap, we build a heap while inserting the elements in the first place.

> :warning: Even when the same elements are used to construct a heap, the two approaches may give different results.
   
