# Intervals Pattern

## When to Use
Used when problems involve:
- Ranges or intervals
- Meetings / schedules
- Overlapping segments

## Core Idea
1. Sort intervals by start time
2. Merge overlapping intervals by comparing current start with previous end

## Why Sorting is Needed
Sorting ensures that overlapping intervals are processed consecutively.

## Generic Template

sort intervals by start

for each interval:
    if current.start <= previous.end:
        merge intervals
    else:
        add new interval
