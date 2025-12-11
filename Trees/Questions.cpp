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

//Questions

//Q.1 Sum of Longest Bloodline
void slb(node* root,int sum,int &ms,int l,int &maxL){
    //base case;
    if(!root){
        if(l>maxL){
            maxL=l;
            ms=sum;
        }
        else if(l==maxL){
            ms=max(ms,sum);
        }
        return;
    }
    sum= sum+root->data;
    slb(root->left,sum,ms,l+1,maxL);
    slb(root->right,sum,ms,l+1,maxL);
}

int sumLargestBloodline(node* root){
    int l=0;
    int maxL=INT_MIN;
    int sum=0;
    int ms=0;
    slb(root,sum,ms,l,maxL);
    return ms;
}

//----------------------------------------------//
//Q2. Lowest Common Ancestor

node* lca(node* root,int n1,int n2){
    if(!root){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* lftans=lca(root->left, n1, n2);
    node* rgtans=lca(root->right, n1,n2);

    if(lftans && rgtans){
        return root;
    }
    else if(!lftans && rgtans){
        return rgtans;
    }
    else if(lftans && !rgtans){
        return lftans;
    }
    else {
        return NULL;
    }


}



//-------------------------------------------------------
//Q3. K sum paths
void pathSolve(node* root,vector<int> path,int &c, int k){
    //base case
    if( !root ){
        return ;
    }
    path.push_back(root->data);
    // call to left part
    pathSolve(root->left,path, c,k);
    //call to right part
    pathSolve(root->right,path, c,k);

    int n=path.size();
    int sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            c++;
        }
    }
    //when backtracking remove the last element from the vector
    path.pop_back();
    
}

int pathSum(node* root,int k){
    vector<int> path;
    int c=0;
    pathSolve(root, path, c,k);
    return c;
}

//----------------------------------------------

//Q4. Kth ancestor of the root

node* ks(node* root, int &k, int node){
    //base case (if k==0 return the node)
    if(!root){
        return NULL;
    }
    if(root->data==node){
        return root;
    }

    node*  lft=ks(root->left,k,node);
    node* rgt=ks(root->right,k,node);
    if(lft && !rgt){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return lft;
    }
    if(!lft && rgt){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rgt;
    }

    return NULL;

    //-----------------------------------------------------------

 //Q5. Minimum time to burn the tree
    
    
}
int kthAncestor(node* root, int &k, int node){
    return ks(root,k,node)->data;

}


int main(){
    
}