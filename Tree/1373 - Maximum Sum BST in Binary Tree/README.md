## Problem Summary
The goal is to find the maximum sum of a binary search tree (BST) within a given binary tree. This involves identifying a subtree that satisfies the BST property and has the largest sum of node values. The solution must efficiently traverse the tree and evaluate all possible subtrees.

## Intuition
To solve this problem, one would naturally consider using a recursive approach to traverse the tree and evaluate each subtree. The key is to identify a way to efficiently determine whether a subtree is a valid BST and calculate its sum.

## Core Idea
The core idea is to use a recursive function `solve` that returns a `NodeInfo` struct containing information about whether the subtree is a BST, its minimum and maximum values, and its sum. This allows the solution to efficiently evaluate each subtree and keep track of the maximum sum found.

## Step-by-Step Algorithm
1. The `solve` function is called recursively for each node in the tree, starting from the root.
2. For each node, the function checks if the left and right subtrees are valid BSTs and if the current node's value is within the valid range.
3. If the subtrees are valid BSTs and the current node's value is within the valid range, the function calculates the sum of the current subtree and updates the maximum sum `ans` if necessary.
4. The function returns a `NodeInfo` struct containing the results of the evaluation.

## Dry Run
Consider a tree with the following structure:
```
    1
   / \
  4   3
 / \
1   2
```
The `solve` function would recursively evaluate each subtree, starting from the leaves. For the subtree rooted at node 4, the function would determine that it is a valid BST with a sum of 7 (4 + 1 + 2) and update the maximum sum `ans` accordingly.

## Time Complexity
The time complexity is O(n), where n is the number of nodes in the tree, because the `solve` function visits each node once.

## Space Complexity
The space complexity is O(h), where h is the height of the tree, because of the recursive call stack.

## Why This Approach Works
This approach works because it uses a recursive function to efficiently evaluate each subtree and keep track of the maximum sum found. The `NodeInfo` struct allows the solution to avoid redundant calculations and ensure that each subtree is evaluated only once.

## Common Mistakes / Edge Cases
* Failing to handle the case where a subtree is not a valid BST
* Incorrectly calculating the sum of a subtree
* Not updating the maximum sum `ans` correctly

## Recognition Pattern
This problem can be recognized by the presence of a binary tree and the requirement to find a maximum sum of a subtree that satisfies a specific property (in this case, being a BST). The solution involves using a recursive approach to evaluate each subtree and keep track of the maximum sum found.