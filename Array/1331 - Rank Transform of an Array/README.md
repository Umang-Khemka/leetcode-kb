## Problem Summary
The problem requires transforming an array by replacing each element with its rank in the sorted array, where equal elements have the same rank. The goal is to achieve this transformation efficiently. The input array contains distinct and duplicate elements.

## Intuition
To solve this problem, one would naturally think of sorting the array to determine the rank of each element. However, simply sorting the array would not be enough, as we need to preserve the original order of elements. We also need to handle duplicate elements by assigning them the same rank.

## Core Idea
The key insight is to use a map (`mp`) to store the rank of each unique element in the sorted array. This allows us to look up the rank of each element in constant time.

## Step-by-Step Algorithm
1. Create a copy of the input array `arr` and sort it in ascending order, storing it in `temp`.
2. Initialize a rank counter `rank` to 1.
3. Iterate through the sorted `temp` array, and for each unique element, assign its rank to the `mp` map and increment the `rank` counter.
4. Iterate through the original `arr` array, and for each element, replace it with its corresponding rank from the `mp` map.

## Dry Run
For the input array `[40, 10, 20, 30]`, the sorted `temp` array would be `[10, 20, 30, 40]`. The `mp` map would be populated as `{10: 1, 20: 2, 30: 3, 40: 4}`. The final transformed array would be `[4, 1, 2, 3]`.

## Time Complexity
The time complexity is O(n log n) due to the sorting of the `temp` array.

## Space Complexity
The space complexity is O(n) for storing the `temp` array and the `mp` map.

## Why This Approach Works
This approach works because the `mp` map ensures that each unique element is assigned a unique rank, and duplicate elements are assigned the same rank. The sorting step allows us to determine the rank of each element efficiently.

## Common Mistakes / Edge Cases
* Not handling duplicate elements correctly, resulting in incorrect ranks.
* Not preserving the original order of elements in the transformed array.
* Not checking for empty input arrays.

## Recognition Pattern
This problem can be recognized by the requirement to transform an array based on the rank of its elements, often involving sorting and mapping operations. Phrases like "rank transformation" or "replace elements with their rank" signal this technique.