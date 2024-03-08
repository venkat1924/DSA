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

<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ac3419bf-e0c1-470b-92a3-584a82abfd93" width="300">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/fdd10f0b-e629-452f-9bcc-b5aad817ec13" width="300">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/02a647ec-5377-4b1d-b521-76053022d6cb" width="300">
</p>



## B+ tree

Here's the rewritten explanation for B+ trees with improved readability:

**B+ Trees: Enhanced Search and Sequential Access**

B+ trees are an improvement over B-trees, designed for efficient searching and retrieval of large datasets stored on disk. Similar to B-trees, a B+ tree of order `m` can have a maximum of `m` children and `m-1` keys within a node.

However, B+ trees handle insertions differently to optimize search performance:

* **Key Placement:** When a node becomes full (holding `m` keys), a split operation occurs. Unlike B-trees, **one key is promoted to the parent node**, but it also gets **copied to the left child node**, if it's a leaf node. This ensures **all keys are present in the leaf nodes**.

<p align="center">

<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ce9a6e92-7996-4d3f-b66b-2fff3568e874" width=300>

<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ed5d4b65-e807-4b46-9b14-c6e4ed376253" width=300>

<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/7f47078d-9c7f-4103-bb3b-42cdfe9d1f5d" width=300>
</p>

* **Efficient Search:** By keeping all keys in the leaf nodes, B+ trees enable efficient searches. During a search, we traverse the tree using the keys in the internal nodes as a guide, eventually reaching the appropriate leaf node that contains the desired key or indicates its absence.
* **Sequential Access:**  B+ trees offer an additional advantage: **sequential access**. Each leaf node typically contains a **reference (pointer)** to the next leaf node in the same level. This allows us to efficiently iterate through all data entries in sorted order, a feature not readily available in traditional B-trees.
<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/b8173187-7159-4c38-98d8-0e82108712a9" width=300>
</p>

In summary, B+ trees provide efficient searching and retrieval of large datasets by keeping all keys in the leaves and enabling efficient navigation through the sorted data using pointers between leaf nodes. 





Here's a rewrite of the explanation about B-Tree and B+ Tree objectives to improve understanding:

# Why Use B-Trees and B+ Trees?

When dealing with massive datasets stored on secondary storage (like hard drives), traditional search methods become slow. To improve retrieval speed, we create **indexes**, which act as special data structures that point to the actual data location. B-trees and B+ trees are two popular choices for building efficient indexes.

**Core Function:**

Both B-trees and B+ trees excel at **organizing and searching large datasets**. They achieve this by structuring data in a hierarchical way, similar to a family tree. Each level in the tree helps narrow down the search until we reach the specific data point.


# B-Tree vs. B+ Tree: Key Differences

| Feature           | B-Tree                                 | B+ Tree                                   |
|-------------------|-----------------------------------------|----------------------------------------------|
| Keys in Leaf Nodes | Not all keys are guaranteed to be in leaf nodes | All keys are guaranteed to be in leaf nodes  |
| Access Type       | Primarily random access                  | Random and sequential access                 |
| Memory Usage      | Lower memory usage                       | Might require additional memory to store promoted key in leaf nodes |
| Search Efficiency  | Potentially slower searches due to non-leaf key lookups | Faster searches due to all keys being in leaf nodes |





