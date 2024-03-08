# Tries
- is a data structure representing a set of words (strings).
- is a tree used to store a set of words.
- apart from the root node, all other nodes store a character (letter)

  Tries can be classified as standard trie or compressed trie.
## Standard trie
- We get a word if we perform a traveral from the root to any of the leaf nodes.
- In the set S containing all the words in the trie, no word should be the prefix of the above.
  <p align="center">
    <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/0e313445-b359-4e3d-bb3d-92a507fba418" width=400>
  </p>
### Conversion of a standard trie to a compressed trie
- We can get a compressed trie from a standard trie by chaining the redundant nodes.
<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ec1ceb25-ea6a-457f-860e-4efad3bf4620" width=400>
</p>
  - All internal nodes have a degree $>=2$ in a compressed trie.
## Compact trie
- A representation of a compressed trie with some numeric values.
- We use an array indexed from 0 to n-1 to store the n words.
<p align="center">
<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/09428286-d4ce-4998-b77c-dae7a60661fc" width =400>
</p>

- Each node in the compact trie contains three integers (i,j,k) to represent the substring in the node:
  - i: represents the index of the word in the array which contains the substring. If the substring is in multiple strings, i refers to the first string which contains the substring.
  - j: represents the starting index of the substring in the word
  - k: represents the ending index of the substring in the word
### Conversion of a compressed trie to a compact trie
<p align="center">
<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/515dfe89-8582-4152-ae8f-513285fee97e" width = 600>
</p>

# Suffix trie
- is a compressed trie for all the suffixes of a word (string).
Example:
First, we create a set of all suffices given a word. We then build a standard trie for those suffices.
<p align="center">
<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/27b1788a-4fe0-4c7e-a8e6-4e475b8f6c5e" width = 400>
</p>
Then, we convert the standard trie to a compressed trie.
<p align="center">
<img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/24a2ea4b-8535-4290-bd80-fe580106ffe7" width = 400>
</p>
Now, to convert the compressed trie to a compact trie, we do not need an integer to denote which word contains the substring, because there is only one word. So each node only contains two integers to denote the starting and ending indices of the word.
<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/bca81fa4-1ade-420e-b4d7-60cfbab118ad" width = 400>
</p>
