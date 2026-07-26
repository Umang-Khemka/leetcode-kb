## Problem Summary
We need to find the maximum product of three numbers in an array. This involves considering both the largest numbers and the smallest numbers, as two negative numbers can multiply to a large positive number.

## Intuition
To maximize the product, we should look for the largest numbers in the array. However, we should also consider the possibility that two negative numbers could multiply to a large positive number, which would then be multiplied by the largest number.

## Core Idea
The key insight is to sort the array and then consider the product of the three largest numbers and the product of the two smallest numbers (which could be negative) and the largest number.

## Step-by-Step Algorithm
1. Sort the input array `nums` in ascending order using `sort(nums.begin(), nums.end())`.
2. Get the size of the array `n` using `int n = nums.size()`.
3. Calculate the product of the three largest numbers using `nums[n-1] * nums[n-2] * nums[n-3]`.
4. Calculate the product of the two smallest numbers and the largest number using `nums[0] * nums[1] * nums[n-1]`.
5. Return the maximum of these two products using `max`.

## Dry Run
For the input `[1, 2, 3, 4]`, the sorted array is `[1, 2, 3, 4]`. The product of the three largest numbers is `2 * 3 * 4 = 24`. The product of the two smallest numbers and the largest number is `1 * 2 * 4 = 8`. The maximum product is `24`.

## Time Complexity
The time complexity is O(n log n) because the code sorts the array using `sort`, which has a time complexity of O(n log n).

## Space Complexity
The space complexity is O(1) because the code only uses a constant amount of space to store the variables `n` and the products.

## Why This Approach Works
This approach works because it considers all possible combinations of three numbers that could produce the maximum product. By sorting the array, we can easily find the largest and smallest numbers, and then calculate the products.

## Common Mistakes / Edge Cases
* Not considering the case where two negative numbers could multiply to a large positive number.
* Not handling the case where the array has fewer than three elements.
* Forgetting to use `max` to compare the two possible products.

## Recognition Pattern
This problem can be recognized by the phrase "maximum product" or "largest product", and the constraint that we need to find the product of a fixed number of elements. The presence of negative numbers in the array is also a hint that we need to consider the possibility of two negative numbers multiplying to a large positive number.