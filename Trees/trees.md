### 1. Height of the Binary Tree
-> Height of the binary tree is the longest path b/w root node and the leaf node.
How can we find this
just by doing max(height(node->right),height(node->left))+1


### 2. Diameter of Binary Tree
->This is width: longest path between any 2 node.
this can be solved by using three ways
a. diameter is in right part
b. diamerte is in left part
c diametre is combo of left and right-> height of left+1+ height of right

using this approach makes the tc goes to n^2;
as we are using both dia and as well as height of the tree


OPTIMISED

we will be using pair to store both the height and diameter of binary tree and will be returning to upper root by using base condition


### 3. Check for balanced Tree
when the diff between the ht of right and left (for every node) is not more than 1 

Optimization: similar to the last one we will use pair to get both values in one only


### 4. Tree are equal or not
root check kro, true h then move to left and right,, if wrong then return false;

### 5. Max Path Sum 
Return the max sum taken in a part of tree. This can be done by using height and width of tree

### 6. Zig-Zag Traversal
for tree like
                
                  1  
              2      3
            4   5   6  7
Output will be 1,3,2,4,5,6. For this we will have one flag which will tell wheter to move from left to right or vice versa and will maintain queue and vector for storing


### 7. Boundry Traversal
for tree like
                
                  1  
              2      3
            4   5   6  7
               8  9 
traverse only the boundry elements
the output will be 1 2 4 8 9 6 7 3

ALGO: <br>
p1: print left part (exvluding leaf node) <br>
p2: print all the leaf nodes <br>
p3: print the right part(excluding leaf node + in reverse)


## there were some other view question refer to docs
### 8. Left View of Tree
Algo: <br>
Print the first node at each level
similar for right view
            

### 9. Sum of Longest Bloodline
<b>algo<br></b>
Recursively go to each side and check for max sum and max lenght

### 10. Lowest Common Ancestor
Lowest common meet up point of those two node
ALGO<br>
Recursively check for each side if the node is one of the given node or not and return the value
<br>
on this basis try to find the lca