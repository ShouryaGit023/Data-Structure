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


int main(){
    vector<int> v={4,3,2,6};
    int n;cin>>n;
    minCost(v,n);
}