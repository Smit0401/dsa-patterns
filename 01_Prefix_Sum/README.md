# Prefix Sum Pattern

## When to Use
This pattern is used when dealing with:
- Subarray sum problems
- Continuous ranges
- Counting subarrays with a target sum

## Core Idea
We maintain a running cumulative sum.  
If:

currentSum - targetSum

has appeared before, then a valid subarray exists.

## Why It Works
We use a HashMap to store how many times a prefix sum has appeared, which allows us to find valid subarrays in O(1) time.

## Generic Template

sum = 0  
map[0] = 1  

for each element:
    sum += element  
    if (sum - k) exists in map:
        count += map[sum - k]  
    map[sum]++
