# Kadane’s Algorithm

## When to Use
Used when:
- You need the maximum sum subarray
- You want the best contiguous segment

## Core Idea
At each index, decide:
- Extend the current subarray
- Or start a new subarray

We keep track of:
- current_sum
- max_sum

## Generic Template

current = arr[0]
max_sum = arr[0]

for i from 1 to n-1:
    current = max(arr[i], current + arr[i])
    max_sum = max(max_sum, current)
