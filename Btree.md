- A multi-way search tree (m-way search tree): Binary search property holds (right subtree>root and left subtree<root)
- A strictly balanced tree: all leaf nodes are at the same level
- m-> denotes the order of the tree
- A B-tree can have a maximum of m children and each node can store up to m-1 keys
  - EG: m=2 (basically a BST), so each node can have <=2 children, and each node can store <= 2-1=1 key.
  - EG: m=3, each node can have <=3 children and each node can store <= 3-1=2 keys.
![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ad087c78-75b3-46e5-8930-4415011397f2)
The Binary search property has been obeyed and all leaf nodes are at the same level.

### An example question solved:
New elements are always inserted into root nodes. Here, the order of the B-tree is 3, so each node can contain a max of 2 keys and have a max of 3 children. Whenever a node contains three elements, the middle one is promoted into the parent node and the remaining two elements in the node are split into separate leaf nodes.

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ac3419bf-e0c1-470b-92a3-584a82abfd93)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/fdd10f0b-e629-452f-9bcc-b5aad817ec13)

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/02a647ec-5377-4b1d-b521-76053022d6cb)


## B+ tree

A B+ tree of order m can have at most m children and at most m-1 keys just like B trees.
BUT when a node has m keys, one key is promoted to the parent node AND it's also present in the left child node. This way, all keys are present in the leaf nodes.

![image](https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ce9a6e92-7996-4d3f-b66b-2fff3568e874)


