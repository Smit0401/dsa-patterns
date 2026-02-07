# Binary Search on Answer

## When to Use
Used when:
- We need to minimize or maximize something
- We can check if a value is feasible

## Core Idea
We don’t search in array instead we search in the **answer space**.

If a solution works for X, it will also work for all values greater or smaller depending on the problem.

## Generic Template

low = minPossible  
high = maxPossible  

while low <= high:
    mid = low + (high-low) / 2
    if feasible(mid):
        answer = mid
        high = mid - 1
    else:
        low = mid + 1
