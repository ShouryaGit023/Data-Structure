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

### 4. Kth largest sum of the subArray
Algo:<br>
insert the sum of all the subarray possible and apply the logic of kth Largest number by using priority queue

### 5. Merge K sorted array  
Algo: <br>
1st approach: put all the elements in pq and pop them TC is higher
<br>2nd put only the first element of each row with row and column value, while poping them out check the bounds of next column and push that element in the pq

#### Similar approach for Merge K Sorted LinkedList

### 6. Smallest Range in K list:
Algo: similar to previous one<br>
Put the first ele of every list in min heap , maintain curr max and range start and range end
<br>
update range start and range end if curr max- pq.top() is less than range_end-range_start, update range_end and range_starts respectively<br>
update the curr max
<br>
insert the next element from the same row of pq.top();
<br>if one row get exhausted break out of the while loop and return the {range_start,range_end}


### 7. Median in a Stream
Approach 1.: use insertion sort and place the ele in their correct position and then find the mediam
#### Why insertion sort? 
insertion sort me when a new ele comes in stream we can simply place it to its correct position (no need to do all the sorting again)

<br>
<b>Best Approach:</b> Use heap as they are already sorted
<br> make two heaps 
<br> Left heap ---> Max heap and Right heap---> Min heap
<br> some invariant : l.size()==r.size or l.size()==r.size()+1; and all ele of left should be less than every ele of right  
<br> odd size -----> median is l.top();
<br> Even size-----> median is (l.top + r.top())/2;