- Constant Windows
- Longest Subarray/ String 

### 1. Max points from cards
- MY approach- keep left and right pointer add the max and inc/ dec that
- why this doesnt work, we dont know the next number from left or right, that might give more sum

- Actual solution: check all possible sum using two pointer
- have leftsum ready, decrease it while adding the element in right sum;
