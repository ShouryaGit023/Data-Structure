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

### 30. WildCard Matching
- havent done


### 31. Buy and Sell Stock II
- take a buy variable to check whether to buy or not

### 32. Buy & Sell Stock III
- 3d DP
- Do again

### 33. Buy & Sell Stock IV
- Similar to B&S III 
- here no of transactions will be k (instead of 2);

### 34. Buy and sell with cooldown
- Here we can not buy immediately after a sell
- so there is a minor change in the sell code

### 35. Buy & Sell with Transaction fee
- same as before but with the intro of transaction fee
- transaction fee is deducted each time while doing sell
- to bs wo minus krdo ans aa jaega

### 36. Longest Increasing Subsequence
- Same take not take with few conditions
- kb lena h and kb nai with how many states that have to keep in mind

- Space Optimised Approach of LIS
- using 1D dp and checking the LIS of prev elements

- Binary Search Approach of LIS
- using lowerbound and replacing in case of found
- if the last element is samller than the current v[i] push back to ans
- return the ans.size()


### 37. Largest Divisible Subset
- sort as order is not important
- do the same as done in the previous printing LIS question 
- the subtle change would be checking v[i]%v[j]
- thats all

### 38. Longest String Chain
- Treat this question as LIS
- But with the size of strings
- make a check function for finding that those 2 string differ only by one char
- also sort the vector of string on the basis of size

### 39. Longest Bitonic Subsequnce
- make the LIS dp1 from the start
- make another LIS dp2 from the back
- if( only inc || only dec) --> acceptable 
- then ans =dp1[i]+dp2[i]-1;
- else if both are required for valid ans
- then only do ans=dp1[i]+dp2[i]-1; iff dp1[i]!=1 && dp2[i]!=1

### 40. Number Of LIS
- Do the same code
- use another vector to store numbers of lis
- if prev+ current forms the same length of lis ---> add the c[prev];
- else update to c[curr]==c[prev];
- in the end accumulate the max val of lis to count

## Partition DP
- When the order of performing operation generate different result
- Thats when we use partition dp

### 41. Matrix Chain Multiplication
- break into partitions
- (i--->j)== (1--> N-1)
- to make partition use k from i to j-1;
- ans is v[i-1]*v[k]*v[j]+solve(i,k)*solve(k+1,j);
- take the min of all 