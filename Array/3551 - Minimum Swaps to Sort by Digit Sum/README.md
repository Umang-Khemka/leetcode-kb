## Problem Summary
The problem requires finding the minimum number of swaps to sort an array based on the sum of digits of each number. The sorting should be done in ascending order of the digit sum, and if two numbers have the same digit sum, they should be sorted in ascending order of the numbers themselves.

## Intuition
To solve this problem, one would naturally think of first calculating the digit sum for each number and then sorting the array based on these sums. After sorting, the original positions of the numbers can be used to determine the minimum number of swaps required to achieve the sorted order.

## Core Idea
The core idea of this solution is to use a custom sorting comparator that prioritizes the digit sum of each number, and then applies the cycle detection approach from graph theory to find the minimum number of swaps.

## Step-by-Step Algorithm
1. Define a helper function `digitSum` to calculate the sum of digits for a given number.
2. Create a sorted copy of the input array `nums`, using a custom comparator that compares the digit sums of two numbers, and if they are equal, compares the numbers themselves.
3. Create an unordered map `pos` to store the positions of the numbers in the sorted array.
4. Initialize a vector `vis` to keep track of visited indices and a variable `swaps` to count the minimum number of swaps.
5. Iterate through the original array, and for each unvisited index, perform a cycle detection to find the minimum number of swaps required to sort the cycle.

## Dry Run
For example, given the input `[7, 3, 6, 12, 15, 9]`, the sorted array would be `[3, 6, 7, 9, 12, 15]` based on the digit sums. The positions of the numbers in the sorted array would be stored in the `pos` map. Then, the cycle detection would be performed for each unvisited index to find the minimum number of swaps.

## Time Complexity
The time complexity is O(n log n) due to the sorting operation, where n is the size of the input array.

## Space Complexity
The space complexity is O(n) for storing the sorted array, the positions map, and the visited indices vector.

## Why This Approach Works
This approach works because it correctly identifies the cycles in the permutation and calculates the minimum number of swaps required to sort each cycle, which is a well-known result in graph theory.

## Common Mistakes / Edge Cases
* Not handling the case where two numbers have the same digit sum correctly.
* Not using a stable sorting algorithm, which could lead to incorrect results.
* Not correctly implementing the cycle detection algorithm.

## Recognition Pattern
This problem can be recognized by the requirement to sort an array based on a custom key (in this case, the digit sum of each number) and then find the minimum number of swaps to achieve the sorted order, which is a classic application of the cycle detection approach from graph theory.