## Intro:
left part should be lesser than the right part
<br>For example
            8
         3       10
     1     6   9    14
<br>
Also Duplicates are not allowed

### WHY?
the height of BST is log base 2 so the time complexity is not O(n), it will take O(log(n));


### Q1. Search in BST
since this is bst check for the root node val and check to move right or left

### Q2. Ceil in BST
if the root->val>key ---> go left
else go right
<br>Similar for the floor


### 3. Insert a given node in BST
Check where the given value might fit in and then check whether that is null or not and then return that node 

### Q4. Delete a Node of BST

### Q5 kth smallest in BST
Inorder of BST is always sorted
just do inorder and keep the count of node 
for cnt==k print that node thats all

### Q6. Validate a BST
everything to right of root is larger
everything to the left should be smaller

### Q7. LCA in BST
 Use the property of bst
 if n1 S root && n2 S root --->move to left; <br>
    n1 B root && n2 B root ---> move to right <br>
    return node iff any of n1 n2 becomes equal to node or n1 B root S n2

### Q8. Recover BST when two are swapped
just do inorder traversal and keep track of prev and curr
<br>If curr less than pre store them
<br>There will be two cases
<br> a. one when swapped are not adjacent
<br>b. swapped are adjacent

<br>Swap the elements and return the node