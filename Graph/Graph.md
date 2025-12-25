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