## Problem Summary
The problem requires removing covered intervals from a given list of intervals. An interval is considered covered if it is completely contained within another interval. The goal is to find the number of intervals that are not covered by any other interval.

## Intuition
To solve this problem, one would naturally think of sorting the intervals based on their start points and then comparing their end points to determine which intervals are covered.

## Core Idea
The key insight here is to sort the intervals based on their start points and then prioritize the intervals with larger end points when the start points are the same.

## Step-by-Step Algorithm
1. Sort the `intervals` vector based on the start point of each interval. If two intervals have the same start point, the one with the larger end point comes first.
2. Initialize `count` to 0 and `maxEnd` to 0.
3. Iterate through the sorted `intervals`. For each interval, check if its end point is greater than `maxEnd`.
4. If the end point is greater, increment `count` and update `maxEnd` to the current interval's end point.
5. Return `count` as the number of intervals that are not covered.

## Dry Run
For the input `intervals = [[1, 4], [3, 6], [2, 8]]`, the sorted intervals would be `[[1, 4], [2, 8], [3, 6]]`. Iterating through the sorted intervals, `count` would be incremented twice (for intervals `[1, 4]` and `[2, 8]`), resulting in a final `count` of 2.

## Time Complexity
The time complexity is O(n log n) because the code sorts the intervals using the `sort` function, which has a time complexity of O(n log n).

## Space Complexity
The space complexity is O(1) because the code only uses a constant amount of space to store the `count` and `maxEnd` variables.

## Why This Approach Works
This approach works because it ensures that the intervals with larger end points are always considered first when the start points are the same. This way, an interval is only counted if it is not completely covered by any other interval.

## Common Mistakes / Edge Cases
* Not handling the case where two intervals have the same start point correctly.
* Not updating `maxEnd` correctly when a new interval is counted.
* Not considering the case where an interval is completely covered by another interval.

## Recognition Pattern
This problem can be recognized by the presence of intervals and the need to remove or count certain intervals based on their coverage. The key phrases to look out for are "covered intervals", "remove intervals", or "count intervals".