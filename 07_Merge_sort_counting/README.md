# Merge Sort + Counting Pattern

## When to Use
Use this pattern when:
- Counting pairs in an array
- Conditions depend on relative order: comparison or inequlity conditions 
- Brute force gives O(n²)

Examples:
- Count inversions
- Reverse pairs
- Count pairs satisfying inequality

## Core Idea
While merging two sorted halves, we can count valid pairs efficiently because both halves are already sorted.

Instead of checking every pair:
We move pointers intelligently during merge.

## Time Complexity
O(n log n)

## Generic Template

1. Divide array into two halves
2. Recursively solve left and right
3. Count valid pairs across halves
4. Merge the two sorted halves

Condition: 1) Simple order -> count during merge 
           2) Mathematical -> count before merge using 2 pointers 
