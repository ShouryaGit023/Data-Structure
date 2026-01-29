## Graphs
Can be directed as well as undirected<br>
Representation by adjacency matrix and adjacency list

### Traversal
#### BFS:
make a visited array and a queue and put those in queue who are not visited, use list to check for the neighbours of the current list

`Time Complexity`

#### DFS
Traversing the depth first 

`Time Complexity`- O(n)+(2*Edges)----for undirected graph

for directed O(n)+(Edges)


## Questions:
### 1. Number of Provinces
- Make a vis array and check if not vis --- do dfs traversal
- ans ++ for every not visited found

### 2. Number of Islands
- Whenever we do bfs for any part increase the island cnt++;
- also push that into  visited 2-d array (basic bfs approach)

`Space Complexity: O(n*n)`

`Time Complexity: ~O(n*n)`

### 3. Flood Fill Algorithm
- Do either dfs or bfs keeping the initial color saved and changing the same colored components of graphs

- `Time Complexity:O(n*m)`
- `Space Complexity: O(n*m)`

### 4. Rotten Oranges
- Count the time req for all oranges to be rotten
- If some orange cant be rotten return -1
- DO BFS (level order traversal);
`Time and Space: O(n*m)`

### 5. Detect a Cycle in a Graph
- Done by BFS by checking if the upcoming node is visited--> then cycle
- Done by DFS
- For component check the cycle with each not visited node
- Graph has cycle if any of the component has cycle

`Time Complexity: O(N+2*E)`


### Cycle detection using dfs
- Store the source and parent 
- call the dfs
- if the node is previously visited and is not the current parent i.e ---> cycle exists

`Time Complexity: O(N+2*E)`

### 6. Distance of Nearest cell having 1
- do bfd from each one and update the level of each 0
- the min level of each 0 is the ans for that 0

`Time Complexity: O(n*m)`

### 7. Surrounded Region [Replace O with X]
- Check for boundry O and their connections-> they wont be converted ever 
- Rest can be converted

### 8. Number of Encalves
- Exactly same as the previous question
- we have to check the number of 1's that doesnot take us out of the boundry
- from the boundry 1's do BFS and mark every connection 1--> false;
- Count the number of True 1's