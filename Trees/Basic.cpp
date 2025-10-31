// creation of binary tree

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
//----------------------------------------------------------------------------//
// Q1. height of binary tree
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    int ans=max(l,r)+1;
    return ans;
}

//2. Diameter of Tree
int dia(node* root){
    if(root==NULL){
        return 0;
    }
    int l=dia(root->left);
    int r=dia(root->right);
    int m=height(root->right)+1+height(root->left);
    return max(l,max(r,m));
}

int main(){

    node* root=NULL;
    root=buildTree(root);
    level_order(root);

    return 0;

}