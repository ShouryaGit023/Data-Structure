## 1. Height of the Binary Tree
-> Height of the binary tree is the longest path b/w root node and the leaf node.
How can we find this
just by doing max(height(node->right),height(node->left))+1

## 2. Diameter of Binary Tree
->This is width: longest path between any 2 node.
this can be solved by using three ways
a. diameter is in right part
b. diamerte is in left part
c diametre is combo of left and right-> height of left+1+ height of right

using this approach makes the tc goes to n^2;
as we are using both dia and as well as height of the tree


OPTIMISED
