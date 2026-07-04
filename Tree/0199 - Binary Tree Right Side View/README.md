## Problem Summary
Given a binary tree, we need to find the rightmost node at each level. This requires traversing the tree level by level and keeping track of the last node encountered at each level.

## Intuition
To solve this problem, one would naturally think of using a depth-first search (DFS) or breadth-first search (BFS) approach, as these are common techniques for traversing trees. However, since we need to find the rightmost node at each level, a DFS approach that prioritizes the right child node would be more suitable.

## Core Idea
The key insight here is to use a DFS approach that traverses the tree level by level, starting from the right child node. This ensures that the rightmost node at each level is encountered first.

## Step-by-Step Algorithm
1. Define a helper function `dfs` that takes a `TreeNode* root`, an integer `level`, and a reference to a `vector<int> ans`.
2. In the `dfs` function, check if `root` is `nullptr`. If so, return immediately.
3. If the current `level` is equal to the size of `ans`, it means we've reached a new level, so append the value of `root` to `ans`.
4. Recursively call `dfs` on the right child of `root` with `level + 1`.
5. Recursively call `dfs` on the left child of `root` with `level + 1`.
6. In the `rightSideView` function, initialize an empty `vector<int> ans` and call `dfs` with the root node and level 0.
7. Return the `ans` vector.

## Dry Run
Consider a binary tree with the following structure:
```
    1
   / \
  2   3
 / \
4   5
```
The `dfs` function will traverse the tree as follows:
- Level 0: `root` = 1, `ans` = [1]
- Level 1: `root` = 3, `ans` = [1, 3]
- Level 2: `root` = 5, `ans` = [1, 3, 5]
The final result will be `[1, 3, 5]`.

## Time Complexity
The time complexity is O(N), where N is the number of nodes in the tree, because we visit each node exactly once.

## Space Complexity
The space complexity is O(H), where H is the height of the tree, because of the recursive call stack.

## Why This Approach Works
This approach works because the DFS traversal ensures that we visit the rightmost node at each level first. By appending the value of `root` to `ans` when we reach a new level, we effectively keep track of the rightmost node at each level.

## Common Mistakes / Edge Cases
* Forgetting to handle the case where `root` is `nullptr`.
* Not appending the value of `root` to `ans` when reaching a new level.
* Not prioritizing the right child node in the DFS traversal.

## Recognition Pattern
This problem can be recognized by the requirement to find the rightmost node at each level of a binary tree. The phrase "right side view" or "rightmost node at each level" is a clear indicator of this problem type.