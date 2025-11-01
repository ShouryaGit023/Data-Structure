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

pair<int,int> fdia(node* root){
    //first-> dia, second gives the height
    if(root==NULL){ //last node ka dia and height is 0,0
        return {0,0};
    }
    pair<int,int> l=fdia(root->left);
    pair<int,int> r=fdia(root->right);
    
    int oa=l.first;
    int ob=r.first;
    int oc=l.second+r.second+1;
    pair<int,int> ans;
    ans.first=max(oa,max(ob,oc));
    ans.second=max(l.second,r.second)+1;
    return ans;

}

//Q3. Balanced tree
 bool balanced(node* root){
    if(root==NULL){
        return true;
    }
    bool l=balanced(root->left);
    bool r=balanced(root->right);
    bool d=abs(height(root->right)-height(root->left))<=1;
    if( l && r && d){
        return true;
    }
    return false;
 }

 //optimised balanced
 pair<bool,int> fb(node* root){
    //first-> balanced or not | second-> return the height
    if(root==NULL){
        return {1,0}; //balanced-> True | height-> 0
    }
    pair<bool,int> l=fb(root->left);
    pair<bool,int> r=fb(root->right);
    bool d= abs(l.second-r.second)<=1;

    if(l.first && r.first && d){
        return {1,max(l.second,r.second)+1};
    }
    return {0,max(l.second,r.second)+1};

    //to use this
    // take fb.first to find whether tree is balanced or not
 }

 //Q4. Tree are equal or not
 bool equal(node* root1, node* root2){
    if(root1->data!=root2->data){
        return false;
    }
    
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2==NULL){
        return 0;
    }
    if(root1==NULL && root2!=NULL){
        return 0;
    }

    bool l=equal(root1->left, root2->left);
    bool r=equal(root1->right, root2->right);
    bool v= root1->data == root2->data;
    if(l && r && v){
        return true;
    }
    return false;
 }

 //Q5. Sum Tree
 bool sumT(node* root){
    if(root==NULL){
        return true;
    }
    bool l=sumT(root->left);
    bool r=sumT(root->right);
    bool m=(root->left->data+root->right->data)==root->data;
    if(l && r && m){
        return 1;
    }
    return false;
    
 }






 //-------------------------------------------------------------
int main(){

    node* root=NULL;
    root=buildTree(root);
    level_order(root);

    return 0;

}