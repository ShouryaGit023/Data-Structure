#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* left;
    node* right;


    node(int n){
        this->data=n;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the root: "<<endl;
    int data;cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

//also the bfs for tree so will use queue
void level_order(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<"/"<<" ";
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        
    }
}

//inorder LRN Left-Right-Node
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){ // NLR Node-Left-Right
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){ // LRN Left-Right-Node
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//-----------------------------------------------------------------------------------//

//Q1. Search in BST
    node* searchBST(node* root, int val) {
        while(root!=NULL && root->data!=val){
            if(root->data<val){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return root;
    }

//--------------------------------------------
// Q2. Ceil & Floor in BST
int findCeil(node* root, int key) {
        // code here
        int ceil = -2; 

    while (root) {
      
        // If root itself is ceil
        if (root->data == key) {
            return root->data; 
        }
 
        // If root is smaller, the ceil
        // must be in the right subtree
        if (key > root->data) {
            root = root->right; 
        } 
      
        // Else either root can be ceil
        // or a node in the left child
        else {
            ceil = root->data; 
            root = root->left; 
        }
    }
    return ceil; 
}

int findFloor(node* root, int x) {
        // code here
        int ans=-1;
        while(root){
            if(root->data==x){
                return root->data;
            }

            if(root->data > x){
                root=root->left;
            }
            else{
                ans=root->data;
                root=root->right;
            }
        }
        return ans;
        
    }

//-----------------------------------------------------------

//Q6. Validate the BST
bool check(node* root,int maxi,int mini){
      if(!root){
          return true;
      }
      if(root->data<=mini || root->data>=maxi){
          return false;
      }
      
      
      bool l=check(root->left,root->data,mini);
      bool r=check(root->right,maxi,root->data);
      return (l && r);
  }
    bool isBST(node* root) {
        // code here
        int mini=INT_MIN;
        int maxi=INT_MAX;
        return check(root,maxi,mini);
        
        
    }

//---------------------------------------------------------------

//Q7. LCA in BST
node* LCA(node* root, node* n1, node* n2) {
        // code here
        if(n1->data==root->data || n2->data==root->data){
            return root;
        }
        if(n1->data<root->data && n2->data<root->data){
            return LCA(root->left,n1,n2);
        }
        else if(n1->data>root->data && n2->data>root->data){
           return LCA(root->right,n1,n2);

        }
        else{
            return root;
        }
    }

//-----------------------------------------------------------------------------------
// Q8. Recover the BST
    node* first;
    node* prev;
    node* mid;
    node* last;
    void recover(node* root){
        if(!root){
            return;
        }
        recover(root->left);
        if(prev!=NULL && prev->data>root->data){

            //this means the first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }

            //this means second violation
            else{
                last=root;
            }
        }

        prev=root;
        recover(root->right);
    }

    void recoverTree(node* root){
        first=middle=last=NULL;
        prev=new node(INT_MIN);
        recover(root);
        if(first && last)swap(first->data,last->data);
        else if(first && middle)swap(first->data,middle->data);
    }
    



int main(){

}