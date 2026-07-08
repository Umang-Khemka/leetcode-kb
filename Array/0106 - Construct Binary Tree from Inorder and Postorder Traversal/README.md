## Problem Summary
Given two traversal sequences, we need to construct the original binary tree. The sequences are inorder and postorder traversals, which provide information about the left and right subtrees of each node.

## Intuition
To reconstruct the tree, we can use the fact that the last element in the postorder traversal is the root of the tree, and then recursively construct the left and right subtrees.

## Core Idea
The key insight is to use a hashmap `mp` to store the indices of the elements in the inorder traversal, allowing us to efficiently find the position of the root node in the inorder sequence.

## Step-by-Step Algorithm
1. Create a hashmap `mp` to store the indices of the elements in the inorder traversal.
2. Initialize the `postIndex` to the last element of the postorder traversal.
3. Call the `build` function with the initial indices `inLeft` and `inRight` set to 0 and the size of the inorder traversal minus 1, respectively.
4. In the `build` function, create a new `TreeNode` with the value of the current `postIndex` and decrement `postIndex`.
5. Find the position `pos` of the current node in the inorder sequence using the `mp` hashmap.
6. Recursively call the `build` function to construct the right subtree with the indices `pos + 1` and `inRight`.
7. Recursively call the `build` function to construct the left subtree with the indices `inLeft` and `pos - 1`.

## Dry Run
For the input `inorder = [4, 2, 5, 1, 3]` and `postorder = [4, 5, 2, 3, 1]`, the `build` function will first create a `TreeNode` with value 1 and then recursively construct the left and right subtrees.

## Time Complexity
The time complexity is O(n) because we visit each node once, where n is the number of nodes in the tree, due to the recursive calls in the `build` function.

## Space Complexity
The space complexity is O(n) because we store the indices of the elements in the inorder traversal in the `mp` hashmap and also use recursive call stack space.

## Why This Approach Works
This approach works because it correctly identifies the root node and then recursively constructs the left and right subtrees based on the inorder and postorder traversals, maintaining the correct tree structure.

## Common Mistakes / Edge Cases
* Forgetting to decrement the `postIndex` after creating a new `TreeNode`.
* Incorrectly calculating the indices for the recursive calls to the `build` function.
* Not handling the base case where `inLeft > inRight` correctly.

## Recognition Pattern
This problem can be recognized by the presence of two traversal sequences (inorder and postorder) and the requirement to reconstruct the original binary tree, which signals the use of recursive tree construction and hashmap-based indexing.