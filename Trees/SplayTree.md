It is a self-adjusting binary search tree with an additional property that the recently accessed key/element becomes the root node.

Not a strictly balanced binary search tree: this means that its worst case time for some operation when amortized is $O(\log{}n)$, whereas for a strictly balanced binary search tree, it is always going to be $O(\log{}n)$

We always perform an operation, and then we _**splay**_ the tree; that is, we perform rotations after every insertion, deletion or search to make the recently accessed key the new root node.
1. **ZIG**: right rotation
2. **ZAG**: left rotation
3. You also have zig-zig, zag-zag, zig-zag and zag-zig.
For a search or insertion, the element itself is made the root.
For a deletion, the previous element accessed while searching for the element is made the root.
