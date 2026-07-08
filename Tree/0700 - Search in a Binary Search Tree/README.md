## Problem Summary
This problem involves finding a node with a specific value in a binary search tree. The goal is to locate the node efficiently by leveraging the properties of the tree. 

## Intuition
To solve this problem, one would naturally think of traversing the tree in a way that takes advantage of its sorted structure, rather than performing a blind search.

## Core Idea
The key insight here is to use the property of binary search trees where all values to the left of a node are smaller, and all values to the right are larger, allowing for an efficient search by moving left or right based on comparisons.

## Step-by-Step Algorithm
1. Initialize `curr` to the `root` of the tree.
2. Enter a loop that continues until `curr` is `nullptr`.
3. Inside the loop, compare the value of `curr->val` with the target `val`.
4. If `curr->val` equals `val`, return `curr` as the target node is found.
5. If `curr->val` is greater than `val`, update `curr` to `curr->left` to search in the left subtree.
6. If `curr->val` is less than `val`, update `curr` to `curr->right` to search in the right subtree.
7. If the loop ends without finding the target `val`, return `nullptr` to indicate the value is not in the tree.

## Dry Run
Consider a binary search tree with the following structure:
       4
      / \
     2   7
    / \ / \
   1  3 6  9
If we search for the value 6, starting from the root (4), we compare 4 with 6, move to the right subtree, compare 7 with 6, move to the left subtree of 7, and find 6, returning the corresponding node.

## Time Complexity
The time complexity is O(h), where h is the height of the tree, because in the worst case, we traverse from the root to a leaf node.

## Space Complexity
The space complexity is O(1), as we only use a constant amount of space to store the current node and do not use any data structures that scale with input size.

## Why This Approach Works
This approach works because it maintains the invariant that if the target value is in the tree, it must be in the current subtree being explored, allowing for an efficient search by pruning branches based on comparisons.

## Common Mistakes / Edge Cases
* Not handling the case where the tree is empty (root is nullptr).
* Failing to update the current node correctly based on comparisons.
* Not returning nullptr when the target value is not found.

## Recognition Pattern
This problem can be recognized by the presence of a binary search tree and the need to find a specific value within it, often signaled by phrases like "search in a BST" or "find a node in a binary search tree".