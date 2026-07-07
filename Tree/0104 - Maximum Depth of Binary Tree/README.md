## Problem Summary
This problem requires finding the maximum depth of a binary tree, which is the number of nodes along the longest path from the root node down to the farthest leaf node. The tree is defined by a set of nodes, each with a value and references to its left and right children.

## Intuition
To find the maximum depth, one would naturally think of exploring the tree in a recursive manner, checking the depth of each subtree and comparing them to find the maximum.

## Core Idea
The key insight here is to use recursion to calculate the depth of the left and right subtrees and then return the maximum of these depths plus one (for the current node).

## Step-by-Step Algorithm
1. Check if the `root` is `nullptr`, in which case return 0 because there are no nodes.
2. Recursively calculate the depth of the left subtree by calling `maxDepth(root->left)` and store it in `lh`.
3. Recursively calculate the depth of the right subtree by calling `maxDepth(root->right)` and store it in `rh`.
4. Return 1 (for the current node) plus the maximum of `lh` and `rh`.

## Dry Run
For a tree with the following structure:
```
    1
   / \
  2   3
 / \
4   5
```
Starting from the root (1), `maxDepth` is called. It calculates the depth of the left subtree (2, 4, 5) and the right subtree (3), and returns the maximum of these depths plus one.

## Time Complexity
The time complexity is O(n), where n is the number of nodes in the tree, because each node is visited once.

## Space Complexity
The space complexity is O(h), where h is the height of the tree, because that's the maximum depth of the recursion stack.

## Why This Approach Works
This approach works because it exhaustively checks all paths from the root to the leaves, ensuring that the longest path (i.e., the maximum depth) is found.

## Common Mistakes / Edge Cases
* Forgetting to handle the base case where the tree is empty (`root` is `nullptr`).
* Not correctly calculating the maximum depth by adding 1 to the maximum of the left and right subtree depths.

## Recognition Pattern
This problem can be recognized by the need to find a property of a tree (in this case, its maximum depth) and the presence of a recursive structure that can be used to explore the tree. Phrases like "find the maximum/minimum depth/height" or "calculate a property for all nodes in a tree" often signal this type of problem.