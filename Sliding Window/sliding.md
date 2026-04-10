- Constant Windows
- Longest Subarray/ String 

### 1. Max points from cards
- MY approach- keep left and right pointer add the max and inc/ dec that
- why this doesnt work, we dont know the next number from left or right, that might give more sum

- Actual solution: check all possible sum using two pointer
- have leftsum ready, decrease it while adding the element in right sum;


### 2. Longest Substring with Unique Characters
- keep a map to store the char with indices as the key
- if char is already in map and also is within range
- move the Left pointer to old index +1 and update the char index to the new index in the range
- take the ans as max(ans,r-l+1);