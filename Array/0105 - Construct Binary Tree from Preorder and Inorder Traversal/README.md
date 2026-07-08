## Problem Summary
Given preorder and inorder traversal sequences, construct the original binary tree. The goal is to use these two sequences to recreate the tree structure.

## Intuition
To solve this problem, one would naturally think of using the preorder sequence to identify the root node and then use the inorder sequence to determine the left and right subtrees.

## Core Idea
The key insight is to use a hashmap (`mp`) to store the indices of the nodes in the inorder sequence, allowing for efficient lookup of the root node's position in the inorder sequence.

## Step-by-Step Algorithm
1. Create a hashmap (`mp`) to store the indices of the nodes in the inorder sequence.
2. Initialize a variable (`preIndex`) to keep track of the current index in the preorder sequence.
3. Call the recursive `build` function, passing in the left and right bounds of the inorder sequence, the preorder sequence, the hashmap, and the `preIndex`.
4. In the `build` function, create a new `TreeNode` with the value at the current `preIndex` in the preorder sequence.
5. Use the hashmap to find the position of the root node in the inorder sequence (`pos`).
6. Recursively call `build` for the left and right subtrees, updating the `preIndex` accordingly.

## Dry Run
For example, given preorder `[3,9,20,15,7]` and inorder `[9,3,15,20,7]`, the `build` function would first create a `TreeNode` with value `3`, then recursively call `build` for the left subtree (inorder `[9]`) and the right subtree (inorder `[15,20,7]`).

## Time Complexity
The time complexity is O(n), where n is the number of nodes in the tree, because each node is visited once in the inorder sequence and once in the preorder sequence.

## Space Complexity
The space complexity is O(n), where n is the number of nodes in the tree, because of the recursive call stack and the hashmap used to store the indices of the nodes in the inorder sequence.

## Why This Approach Works
This approach works because the preorder sequence gives us the root node, and the inorder sequence gives us the left and right subtrees. By using a hashmap to store the indices of the nodes in the inorder sequence, we can efficiently find the position of the root node and recursively construct the left and right subtrees.

## Common Mistakes / Edge Cases
* Forgetting to update the `preIndex` variable when recursively calling `build`.
* Not handling the base case where `inLeft > inRight` correctly.
* Not using a hashmap to store the indices of the nodes in the inorder sequence, leading to inefficient lookup.

## Recognition Pattern
This problem can be recognized by the presence of two sequences (preorder and inorder) and the goal of constructing a binary tree from them. The key phrase to look out for is "construct a binary tree from preorder and inorder traversal sequences".