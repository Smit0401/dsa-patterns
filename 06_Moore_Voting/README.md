# Moore’s Voting Algorithm

## Case 1: Majority Element (> n/2)

### Template
count = 0
candidate = None

for x in arr:
    if count == 0:
        candidate = x
    if x == candidate:
        count += 1
    else:
        count -= 1

return candidate


## Extended Moore’s Voting (> n/3)

### Template
count1, count2 = 0, 0
cand1, cand2 = None, None

for x in arr:
    if x == cand1:
        count1++
    else if x == cand2:
        count2++
    else if count1 == 0:
        cand1 = x; count1 = 1
    else if count2 == 0:
        cand2 = x; count2 = 1
    else:
        count1--; count2--

# Second pass to verify
count1, count2 = 0, 0
for x in arr:
    if x == cand1: count1++
    if x == cand2: count2++

if count1 > n/3: add cand1
if count2 > n/3: add cand2
