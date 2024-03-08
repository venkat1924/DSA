# B-Trees: Efficient Search Trees for Large Datasets

B-trees are a special type of search tree designed for efficient storage and retrieval of large datasets. They address the limitations of binary search trees (BSTs) by allowing more than two children per node. Here's a breakdown of key B-tree concepts:

* **Multi-way Search Trees:** Unlike BSTs with two children (left and right), B-trees are called `m-way` search trees because each node can have up to `m` children.
* **Balanced Structure:** B-trees are **strictly balanced**. This means all leaf nodes (nodes without children) reside at the same level, ensuring efficient searching.
* **Order of the Tree (m):** The `order` (m) defines the capacity of a B-tree node. A B-tree of order `m` can have a maximum of `m` children and store up to `m-1` keys within a single node.
* **Key Storage:** Each node acts like a mini-sorted list. Keys are stored in ascending order, allowing for efficient comparisons during search operations.

**Examples:**

* **m=2 (Similar to BST):** In this case, the B-tree behaves like a BST. Each node can have at most 2 children (left and right) and store at most 1 key (m-1 = 2-1).
* **m=3 (More Capacity):** With order 3, each node can have up to 3 children and store up to 2 keys (m-1 = 3-1). This allows for more efficient handling of larger datasets compared to a BST.
<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ad087c78-75b3-46e5-8930-4415011397f2">
</p>

The tree maintains the binary search order and all leaves are at the same depth. (Depth is another term for level)


### Inserting Elements in a B-Tree (Order 3):

Unlike BSTs, insertions in B-trees happen at **leaf nodes**, not the root. In a B-tree of order 3, each node can hold a maximum of **2 keys** (m-1) and have up to **3 children** (m). 

Here's what happens when inserting a new element:

1. We traverse the tree, finding the appropriate leaf node for insertion based on the element's value.
2. If the leaf node has **less than 2 keys** (not full), the new element is simply added while maintaining the ascending order.
3. However, if the leaf node is already **full** (contains 2 keys), we perform a **split** operation:
    * The **middle element** of the full leaf node is promoted as a new key to its **parent node**.
    * The remaining elements (originally in the full leaf) are distributed into **two new child nodes**. These new child nodes become the children of the parent node that received the promoted key.

This process ensures that the B-tree remains balanced, with all leaf nodes at the same level, even after insertions. 

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ac3419bf-e0c1-470b-92a3-584a82abfd93)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/fdd10f0b-e629-452f-9bcc-b5aad817ec13)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/02a647ec-5377-4b1d-b521-76053022d6cb)


## B+ tree

A B+ tree of order m can have at most m children and at most m-1 keys just like B trees.
BUT when a node has m keys, one key is promoted to the parent node AND it's also copied in the left child node (only if the left child node is a leaf node, otherwise, we don't copy the promoted values, just as in B tree). This way, all keys are present in the leaf nodes.

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ce9a6e92-7996-4d3f-b66b-2fff3568e874)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ed5d4b65-e807-4b46-9b14-c6e4ed376253)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/7f47078d-9c7f-4103-bb3b-42cdfe9d1f5d)

So after the B+ tree has been constructed, the last layer will consist of all the keys in the tree. Also, each leaf node will contain a reference to the next leaf node in the layer, to provide for sequential access.

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/b8173187-7159-4c38-98d8-0e82108712a9)

# Objective of using a B/B+ tree

Secondary storage contains huge amounts of data. An index table needs to be built to contain references to the actual data. B/B+ trees are used to build this index table.

To summarise the differences between B and B+ trees:

|B-tree|B+ tree|
| :---: | :---:|
| All keys will not be in the leaf nodes. | All keys will be in the leaf nodes. |
| Provides only random access. | Provides both random and sequential access between leaf nodes. |
| No additional memory is required. | Additional memory is required to store the promoted key in the leaf node. |




