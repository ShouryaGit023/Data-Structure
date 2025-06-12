#include <bits/stdc++.h> //problem 15 on leetcode;
using namespace std;

vector<vector<int>> better_ts(vector<int> &v, int size){ //O(n*n*log(n));
    set<vector<int>>s;
    for(int i=0;i<size;i++){
        int tar=-v[i];
        set<int> se;
        se.insert((v[i]));
        for(int j=i+1;j<size;j++){
            int tf=tar-v[j];
            if(se.find(tf)!=se.end()){
                vector<int> trip={v[i],v[j],tf};
                sort(trip.begin(),trip.end());
                s.insert((trip));
            }
            se.insert(v[j]);
        }
    }
    vector<vector<int>>ans(s.begin(),s.end());
    
    return ans;
}


//best approach using two pointer
void best_sum(vector<int> &v, int size){
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=0;i<size;i++){
        int init=v[i];
        int j=i+1;int k=size-1;
        while(j<k){
            if(v[j]+v[k]==-init){
                ans++;
            }
            if(v[j]+v[k]>-init){
                k--;
            }
            if(v[j]+v[k]<-init){
                j++;
            }
        }
    }
    cout<<ans<<endl;
    return;

}

int main(){
 
    vector<int> v={-1,0,1,2,-1,-4};
    //brute force is just finding all triplets and checking if condition satisfies or not O(n*n*n);

    //better will be using hashing finding first two number and another one by using the given equaion O(n*n);

    // vector<vector<int>> c=better_ts(v,6);
    // for(int i=0;i<c.size();i++){
    //     for(int j=0;j<c[i].size();j++){
    //         cout<<c[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    best_sum(v,6);
}