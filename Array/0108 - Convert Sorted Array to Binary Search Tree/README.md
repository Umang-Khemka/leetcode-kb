## Problem Summary
The goal is to construct a balanced binary search tree from a given sorted array, ensuring the tree remains approximately balanced to maintain search efficiency. This involves dividing the array into smaller segments and creating tree nodes accordingly. The resulting tree should have the property that for every node, all elements in its left subtree are less than the node, and all elements in its right subtree are greater.

## Intuition
To create a balanced binary search tree from a sorted array, one might naturally think of dividing the array into two halves and using the middle element as the root of the tree, then recursively applying the same process to the left and right halves.

## Core Idea
The core idea here is to use a recursive approach to divide the sorted array into smaller segments and create the binary search tree by selecting the middle element of each segment as the root of the subtree.

## Step-by-Step Algorithm
1. The `build` function takes a vector `nums` and two indices `left` and `right` as parameters, representing the current segment of the array being processed.
2. If `left` is greater than `right`, the function returns `nullptr`, indicating the end of a branch in the tree.
3. The `mid` index is calculated as the average of `left` and `right`, rounded down, to find the middle element of the current segment.
4. A new `TreeNode` is created with the value of `nums[mid]`, and its `left` and `right` children are recursively set by calling `build` on the segments `left` to `mid - 1` and `mid + 1` to `right`, respectively.
5. The `sortedArrayToBST` function initiates the process by calling `build` on the entire array.

## Dry Run
Given the input array `[1, 2, 3, 4, 5]`, the `build` function would first create a root node with value `3` (the middle element), then recursively create left and right subtrees from the segments `[1, 2]` and `[4, 5]`, resulting in a balanced binary search tree.

## Time Complexity
The time complexity is O(n), where n is the number of elements in the array, because each element is visited once during the recursive construction of the tree.

## Space Complexity
The space complexity is O(log n) due to the recursive call stack, which in the worst case (a completely unbalanced tree) could be O(n), but for a balanced tree, it remains O(log n).

## Why This Approach Works
This approach works because it ensures the tree remains approximately balanced by always selecting the middle element as the root, thus maintaining the property of a binary search tree where all elements in the left subtree are less than the root, and all elements in the right subtree are greater.

## Common Mistakes / Edge Cases
* Not handling the base case of an empty segment (`left > right`) correctly.
* Incorrectly calculating the `mid` index, which could lead to an unbalanced tree.
* Not properly setting the `left` and `right` children of each node.

## Recognition Pattern
This problem can be recognized by the requirement to construct a data structure (in this case, a binary search tree) from a sorted input, with an emphasis on maintaining balance for efficiency. Keywords like "sorted array," "binary search tree," and "balanced" are indicative of this problem type.