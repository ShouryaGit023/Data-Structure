#include <bits/stdc++.h>
using namespace std; //problem 560 lc

// return the count of subarray whose sum is k

void brute(vector<int> &v,int n,int k){ //O(n*n);
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(sum==k){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return;
}


void better(vector<int> &v,int n,int k){  //O(n)
    vector<int> pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+v[i];
    }

    int ans=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int val=pre[i]-k;
        if(m.find(val)!=m.end()){
            ans+=m[val];
        }
        if(pre[i]==k){
            ans++;
        }
        m[pre[i]]++;
    }
    cout<<ans<<endl;
    return;
}

int main(){

    vector<int> v={9,4,0,20,3,10,5};

    //brute force by using two loops and calculating the sum of all subarray
    // brute(v,6,33);
    
    //better is using prefix sum;

    better(v,7,33);

}