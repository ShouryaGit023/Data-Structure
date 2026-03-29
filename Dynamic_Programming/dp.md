## There are two ways to write DP
1. first being Top-Down approach----> Recursion+ Memoisation
2. second being Bottom-Up approach ---> tabulation (converting recursion in loop format)

   1. Tabulation me first base case use krke data dalo
   2. Then use kha se kha tk loop chahiye
   3. write the code


## Minimum Cost Climbing Stairs
 ### Before this a basic question
 Starting from the ith stair, tell the possible number of way to climb the stairs(variation of this) [done by recursion ]


## Actual Question:
  1. Every stair is associated with some cost
  2. So find the min cost to reach the end starting from either 0th or 1st Stair
  3. Return the min cost to reach the top floor


## MIN No. OF COINS
  Given a array of coins, find min number of coin req to add up to k

### 3. Frog Jump
- Frog want to jump from 1--->n
- Can jump either 1 or 2 places
- Find minimum energy required by him
- Try all possible way from one index
- take minimum of that while storing the values

### 4. Maximum sum of non adjacent elements
- same pick not pick,
- but applying the dp and memoisation in this

### 5. House Robbery
- cannot rob from adjacent house
- twist is that houses are in circular array
- take c1- 0--- n-2
- take c2-> 1---n-1 
- as first and last house are never taken together
- take the minimum of this then

### 6. Ninja Training
- on particular day he can train any from 3
- next day can choose any but not the last day one
- find the max training skill gained
- do a 2d dp and check for all the possibilities

 ### 7.No. of Unique Path
 - Count all the path and return 
 - memoize or tabulate to produce the fastest approach

 ### 8. Minimum Path sum
 - Do all the paths and count the sum
 - use dp
 - that all

 ### 9 . Triangle path sum
 - start from 0,0
 - can go only to i+1,j or to i+1,j+1
 - goal is to reach the last row

 ### 10. max path sum in matrix
 - starting and ending point are not fixed

 ### 11.  Cherry Pickup
 - Fixed starting point 
 - Find the max no of cherry that they can pickup
 - How man ways to reach to the last row 
(not finished)


## DP on Subsequences:

### 12. Subset sum equal to Target
- same take not take conditions
- will use 2d dp to track id and target for that val

### 13. Partioning in subsets forming equal sum
- sum of each subset should be S/2;
- if S is odd--- ans is no
- find one subset whose sum is S/2;
- Same as the last question

### 14. Minimum partition subsets
- can be solved using tabulation 
- consider each cell tells whether till that index we can have a particular target or not
- solved using memoization 

### 15. Count subsets with sum equal to k
- Both the approach is given
- Memoization is intuitive 
- Tabulation is also given

### 16. Count subsets with differnce d
- reduce s1-s2=d && s1+s2 =S to find a particular formulae
- it boils down the question to que 14 (finding a particular(here how many) subset with sum k)

### 17. Knapsack
- did the memoization one
- tabulation is also important

### 18. Coin Change
- we have multiple supply of coin so look for that
- we have to find min so look for that

### 19. Target Sum
- have to assign + - to each of the value 
- can be converted to diff subset wala ques
- did normally and by diff subset aproach

### 20. Unbounded Knapsack
- same as knapsack but now we have unlimited supply of products

### 21 Rod cutting 
- Same as unbounded dp
- Learn to optimise the space and tabulation version

### 22. Longest Common Subsequence
- if matched do 1+(i-1,j-1);
- else do max ((i-1,j), (i,j-1));
- for printing the lcs do the extra code of finding the index where a new number is found in the matrix

### 23 Longest Common Substring
- if matched do 1+(i-1,j-1);
- else do dp[i][j]=0;
- also note that this will require tabulation matrix
- take the max of the grid

### 24. Longest Palindromic Substring
- Same as earlier
- make one string that is reverse of the original
- find lcs in that

### 25. Minimum insertion to make a palindrom string
- keep the longest palindroming subsequence intact
- we have to add the elements who are not part of LPS
- that is n-LPS is the ans

### 26. Minimum Operation to make a ==b (using deletion and insertion in string a)
- ans is n+m- 2*LCS;

### 27. Smallest Common SuperSequence
- length is n+m-lcs
- to print the String iterate through the dp table

### 28. Distinct Subsequence
- take not take 
- and easy one

### 29. Edit Distances
- here we have 3 options
- insert , delete, replace
- code is self explanatory
