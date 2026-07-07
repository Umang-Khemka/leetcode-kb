## Problem Summary
This problem involves determining whether a given binary tree is balanced, meaning the absolute difference in height between its left and right subtrees does not exceed 1 for all nodes. The task is to design a function that checks for this balance condition. 

## Intuition
To solve this, one would naturally think of calculating the height of each subtree and comparing them, considering the recursive nature of binary trees.

## Core Idea
The key insight here is to use a recursive approach to calculate the height of each subtree and simultaneously check if the tree is balanced, returning -1 as a sentinel value to indicate imbalance.

## Step-by-Step Algorithm
1. Define a helper function `height` that takes a `TreeNode* root` as input.
2. Within `height`, if `root` is `nullptr`, return 0, indicating the height of an empty tree.
3. Recursively calculate the heights of the left and right subtrees (`leftHeight` and `rightHeight`).
4. If either subtree is found to be unbalanced (`leftHeight` or `rightHeight` equals -1), immediately return -1.
5. Check if the absolute difference between `leftHeight` and `rightHeight` is greater than 1; if so, return -1 to indicate the tree is unbalanced.
6. Otherwise, return the height of the tree as 1 plus the maximum of `leftHeight` and `rightHeight`.
7. The main function `isBalanced` simply calls `height` on the root and checks if the result is not -1.

## Dry Run
For a tree with root node having value 3, left child as 9, and right child as 20 with children 15 and 7, the `height` function would recursively calculate heights, ensuring the tree is balanced by comparing the heights of subtrees.

## Time Complexity
The time complexity is O(n), where n is the number of nodes in the tree, because each node is visited once by the recursive `height` function.

## Space Complexity
The space complexity is O(h), where h is the height of the tree, due to the recursive call stack.

## Why This Approach Works
This approach works because it maintains an invariant: if any subtree is found to be unbalanced, the function immediately returns -1, propagating this result up the call stack and ensuring that an unbalanced tree is correctly identified.

## Common Mistakes / Edge Cases
* Not handling the case where a subtree is null (already handled by returning 0 for null trees).
* Failing to propagate the -1 sentinel value correctly when a subtree is found to be unbalanced.
* Incorrectly calculating the height of the tree or the difference in heights between subtrees.

## Recognition Pattern
This problem can be recognized by the requirement to check balance or height properties in a tree, often signaled by phrases like "balanced," "height," or "depth" in the problem statement, and typically involves a recursive approach to traverse the tree and calculate relevant metrics.