# Two Pointers Pattern

## When to Use
Used when:
- Array or string is sorted
- We need to find pairs or triplets
- We move from both ends

## Core Idea
Use two indices moving toward each other to reduce time complexity.

## Generic Template

left = 0
right = n - 1

while left < right:
    if condition satisfied:
        update answer
    else if need larger value:
        left++
    else:
        right--
