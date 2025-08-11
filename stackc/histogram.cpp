#include <bits/stdc++.h>
using namespace std;
//histogram me main is to find right smaller as well as left smaller then just calculate the max area and store the max out of all


int  solve(vector<int> &v){
    int n=v.size();
    vector<int> r(n,0),l(n,0);
    stack <int> s;

    //right smaller
    for(int i=n-1;i>=0;i--){
        while(s.size()>0 && v[s.top()]>v[i]){
            s.pop();
        }
        s.empty()? r[i]=-1 :r[i]=s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    //left smaller
    for(int i=0;i<n;i++){
        while(s.size()>0 && v[s.top()]>v[i]){
            s.pop();
        }
        s.empty()? l[i]=-1 :l[i]=s.top();
        s.push(i);
    }
    int ca=0;
    int ma=0;
    for(int i=0;i<n;i++){
        ca=v[i]*(r[i]-l[i]-1);
        ma=max(ma,ca);
    }
    return ma;

}


int main(){

    vector<int> h={2,1,5,6,2,3};
    int ans=solve(h);
    cout<<ans<<endl;
    
}