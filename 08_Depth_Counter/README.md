# Depth Counter Pattern

## When to Use
Used when:
- Tracking nesting level
- Parentheses or bracket problems
- Finding maximum nesting depth
- Segmenting expressions

## Core Idea
Maintain a counter:
- Increment when encountering an opening symbol
- Decrement when encountering a closing symbol

This avoids using an explicit stack when only depth matters.

## Generic Template

depth = 0
maxDepth = 0

for char in string:
    if char == '(':
        depth++
        maxDepth = max(maxDepth, depth)
    else if char == ')':
        depth--
