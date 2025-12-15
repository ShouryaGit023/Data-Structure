#include <bits/stdc++.h>
using namespace std;

void kthSmallest(vector<int> v,int k){
    priority_queue<int> p;
    for(auto i:v){
        p.push(i);
        if(p.size()>k){
            p.pop();
        }
    }
    cout<<p.top()<<endl;
}

//---------------------------------------
// Q2. merge tow binary max heaps
void heapify(vector<int>&arr, int n, int i)
{
    // Initialize largest as root
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

vector<int> merge(vector<int> &a,vector<int> &b,int n,int m){
    //first merge both vector
    vector<int> ans;
    for(auto i:a){
        ans.push_back(i);
    }
    for(auto i:b){
        ans.push_back(i);
    }
    int size=ans.size();
    for(int i=(size/2)-1;i>=0;i--){
        heapify(ans,n,i);
    }
    return ans;

}

//--------------------------------------------------
//Q3. Minimum Cost of Ropes
void minCost(vector<int> v,int n){
    priority_queue<int> p;
    //to create this to a min heap enter all the element in -ve ordre
    for(auto i:v){
        p.push(-i);
    }
    

    int ans=0;
    while(p.size()>1){
        int a=0;
        a=a-p.top();
        p.pop();
        a=a-p.top();
        p.pop();
        p.push(-a);
        ans+=a;
    }
    cout<<ans<<endl;
}
//--------------------------------------------------------------
// Q4. kth Largest subarray sum
void kthSumSubarray(vector<int> &v,int k){
    priority_queue<int> mh;
    int n=v.size();
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=v[j];
            mh.push(-s);
            if(mh.size()>k){
                mh.pop();
            }
        }
    }
    cout<<-mh.top()<<endl;
    return;
}
//--------------------------------------------------------
// Q5. Merge K-sorted array
vector<int> mergeArray(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();

    //min heap storing {val,{row,col}};
    priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

    for(int i=0;i<n;i++){
        pq.push({mat[i][0],{i,0}}); //val,row,col
    }
    vector<int> ans;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int val = cur.first;
        int r   = cur.second.first;
        int c   = cur.second.second;
        ans.push_back(val);

        //push next element from the same row after checking the bounds
        if(c+1<m){
            pq.push({mat[r][c+1],{r,c+1}});
        }
    }
    return ans;
}

//-----------------------------------------------------------
//Q6. Smallest Range in K lists
vector<int> smallestRange(vector<vector<int>> &mat){
    int k=mat.size();
    
    //priority queue storing val row and column
    priority_queue<pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
                greater<pair<int,pair<int,int>>>
    >pq;

    int curr_max=INT_MIN; 

    //push the first element of each row       
    for(int i=0;i<k;i++){
        pq.push({mat[i][0],{i,0}});
        curr_max=max(curr_max,mat[i][0]);
    }
    int range_start=0,range_end=INT_MAX;
    while(pq.size()==k){
        auto curr=pq.top();
        pq.pop();
        int val=curr.first;
        int r=curr.second.first;
        int c=curr.second.second;

        if(curr_max-val<range_end-range_start){
            range_end=curr_max;
            range_start=val;   
        }
        if(c+1<mat[r].size()){ //check is list is exhausted or not
            int next_val=mat[r][c+1];
            //push the next val and update the curr_max
            pq.push({next_val,{r,c+1}});
            curr_max=max(curr_max,next_val);
        }
        else{// if a single list is exhausted, return 
            break;
        }
        
    }
    return {range_start,range_end};
}


int main(){
    vector<vector<int>> v={{4, 7, 9, 12, 15}, 
               {0, 8, 10, 14, 20}, 
               {6, 12, 16, 30, 50}
            };
    vector<int> ans=smallestRange(v);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}