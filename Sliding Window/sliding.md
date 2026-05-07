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

### 3. Maximum number of Consecutive ones with atmost K flips
- this can be interpreted as Max Subarray length with atmost K zero
- Do that and the ans will be yours

### 4. Fruits in the basket
- Use map to maintain the size of 2
- Increment l when size exceeds the


### 5. Max substring with at most K different characters
- same as before


### 6. Number of substring with all character
- check till we get all character
- the total substring would be till end of array

### 7. Longest Repeating Character Replacement
- Track the max freq and total length of the subarray
- number of changes req will be total_length - max_freq
- make sure its less than k 
