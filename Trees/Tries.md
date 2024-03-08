# Tries: A Tree for Storing Words

Tries are a special kind of tree data structure used to store and manage sets of words. Imagine a branching tree where each branch represents a letter in a word.

**Basic Idea:**

* Each word is represented by a path from the root of the tree to a leaf (end node).
* As you travel down the path, each branch represents a character in the word.
* Unlike a regular tree, all nodes (except the root) store a single character, building the word step-by-step.

**Classifications:**

* **Standard Trie:**
  <p align="center">
    <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/0e313445-b359-4e3d-bb3d-92a507fba418" width=400>
  </p>
    * This is the basic trie structure described above.
    * Every path from root to leaf represents a complete word.
    * No word in the set can be a prefix (beginning part) of another word.
* **Compressed Trie:**
    * A more space-efficient version of the standard trie.
    * It identifies and merges redundant branches that contain the same characters.
    * This reduces wasted space but requires internal nodes to have at least two branches ($degree >= 2$).
    <p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/ec1ceb25-ea6a-457f-860e-4efad3bf4620" width=400>
</p>

* **Compact Trie (Similar to Compressed Trie):**
    * This is a compressed trie with an additional numeric representation for efficiency.
    * It uses an array to store the actual words themselves.
    * Each node in the trie holds three values $(i, j, k)$ :
        * $i$: Index in the word array pointing to the first word containing the substring represented by the node.
        * $j$: Starting position of the substring within the word at index $i$.
        * $k$: Ending position of the substring within the word at index $i$.

        <p align="center">
          <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/515dfe89-8582-4152-ae8f-513285fee97e" width = 600>
        </p>

**Benefits of Tries:**

By using tries, we can perform various operations on sets of words very efficiently, such as searching for specific words, finding words with a common prefix (e.g., autocomplete suggestions), and implementing spell checkers.

## Suffix Tries: Efficient Search Within Words

A suffix trie is a specialized trie data structure designed to efficiently search within a single word (or string). It works by storing all possible suffixes (endings) of the word in a compressed trie.

Here's a breakdown of the concept:

1. **Suffix Breakdown:** 
   - We start by taking the given word and creating a list containing all its suffixes. 
   - Remember, a suffix is any ending portion of the word. 

2. **Standard Trie Construction:**
   - Next, we build a regular trie using this list of suffixes. 
   - In a standard trie, each complete path from root to leaf represents a complete suffix.
  
    <p align="center">
      <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/27b1788a-4fe0-4c7e-a8e6-4e475b8f6c5e" width = 400>
    </p>

3. **Compression for Efficiency:**
   - To save space, we then transform the standard trie into a compressed trie. 
   - This process identifies and merges branches that share the same characters, reducing redundancy.
     
   <p align="center">
     <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/24a2ea4b-8535-4290-bd80-fe580106ffe7" width = 400>
  </p>


Since there's just a single word, we don't need an index to separate words. Therefore, each node in a suffix trie simply stores two integers:

  - Starting index: This represents the starting position of the suffix within the original word.
  - Ending index: This represents the ending position of the suffix within the original word.
    
<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures/assets/128356330/bca81fa4-1ade-420e-b4d7-60cfbab118ad" width = 400>
</p>

With this structure, suffix tries enable efficient operations like finding all occurrences of a substring within the word or identifying repeated patterns.

  




