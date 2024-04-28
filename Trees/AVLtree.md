In a complete binary tree or complete BST with $n$ nodes, for accessing a node:
- Best Case: $O(1)$ for the root node
- Worst Case: $O(log n)$ for a leaf node

For a right-skewed BST with $n$ nodes:
- Best Case: $O(1)$ for the root node
- Worst Case: $O(n)$ for a leaf node

# AVL tree
- AVL tree is a balanced BST where the worst case to perform any operation is $O(log n)$.
- The **balance factor (BF)** of each node in the tree is $0, +1$ or $-1$.
> Balance factor of a node: height of left subtree $-$ height of right subtree
- The BF of leaf nodes will be $0$.
- The BF of all nodes in a complete binary tree are $0$.

These two are valid AVL trees.

```mermaid
classDiagram

class A {BF:  -1}
class B {BF:  0}
class C {BF: -1}
class D {BF:  0}
class P {BF:  0}
class Q {BF:  0}
class R{BF:  0}
class S {BF:  0}
class T {BF:  0}
class U {BF:  0}
class V {BF:  0}

A--B
A--C
C--null
C--D

P--Q
P--R
Q--S
Q--T
R--U
R--V

```
This is not a valid AVL tree

```mermaid
classDiagram
class A{BF:2}
class B{BF:1}
class C{BF:0}

class P{BF:2}
class Q{BF:-1}
class R{BF:0}

A--B
A--null1
B--C
B--null2

P--Q
P--null3
Q--null4
Q--R

```
> nullX are all regular NULL, mermaid doesn't support duplication.

## [Rotation](https://en.wikipedia.org/wiki/Tree_rotation)

Rotation is an operation performed to convert an unbalanced BST to a balanced BST (AVL).
Two types are:
- Single rotation
  - Left rotation (L)
  - Right rotation (R)
- Double rotation
  - Left right rotation (LR)
  - Right left rotation (RL)
> :warning:REMEMBER TO WRITE THE BF FOR EACH NODE EVERY TIME

