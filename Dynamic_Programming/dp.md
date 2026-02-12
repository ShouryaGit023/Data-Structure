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

 ### 12 Feb nai ho paya--- did fake commit

