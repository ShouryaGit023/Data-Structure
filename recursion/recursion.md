# Recursion

## Subsequence Generation
- Every element has 2 options ---->either to take or not take
- as per this make the array when the index reached to end print the array

**Time Complexity :** `O(2^n)`


## All Subsequence with sum equal to K
- Same as before all element has two choice
- in the end if the sum equals to K just print that subsequence

**Time Complexity :** `O(2^n)`

### Slight modification to this
-  IF I WANT TO PRINT ONLY ONE SUBSEQUENCE
-  the technique is to have base case return true;
- check for take and not take if those satisfy the condtion return true;

**This can be used for question asking `Whether there exist atleast one kinda `**

----
## Count Subsequence with sum equal to K
- Same logic as before either take or not take
- if sum equals to k just do count ++
- ❌ dont use this type, use the below stated one

**The pattern will be to return 1 when the condition is satisfied**
- take `l` as the `taken value`
- take `r` as the `not taken value`
- Return `l+r`;

## Combinational Sum - I
- Return the list containing the subarray, where each subarray sum is K
- Can choose same element multiple times

## Combinational Sum- II
- We are not allowed to take a element twice
- Also have to return unique sequences in sorted order (do the sorting and one condition check)
- `Time Complexity: (2^n)*k`

## Subset Sum- I
- Print the sum of each n every subset
- Same take and not take