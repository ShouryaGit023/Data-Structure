## HEAP?
Heap is basically Complete Binary Tree, <br>
### Types
1. MAX heap (each node is larger than each of its child)
2. MIN heap  (where each of the node is smaller than both of its child)

### HEAPIFY
convert every node to heaped<br> leaf nodes are already in heap so dont check them

### IMPLEMENTATION:
Implementation by  using array
<br>IMP: child of a node with index "i" is <b>2*i and 2*i+1 </b>

## QUESTIONS:<hr>
### 1. Kth smallest Element
insert in priority queue when the size of queue become greater than K just pop the top element 
<br>in the end the top element will be the kth smallest element

### 2. Merge 2 binary max heap
merge two given tree(given in form of vector);<br>
use heapify fun to convert the vector to heap;

### 3. Minimum Cost of Ropes
Task: connect all the ropes where the cost to connect two rope is the sum of their sizes
<br>Find the minimum cost of the merging 

<br><b>Algorithm</b><br>
Create a min heap and take two out push their sum in , if the size of heap is 1 return

### 4