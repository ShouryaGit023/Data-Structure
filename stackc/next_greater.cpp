#include <bits/stdc++.h>
using namespace std;
//lc 496

void solve(vector<int> &v){ //O(n);
    int n=v.size();
    stack<int> s;
    vector<int> ans(n,-1);

    for(int i=n-1;i>=0;i--){
        while(s.size()>0 && s.top()<=v[i]){
            s.pop();
        }
        if(s.size()!=0){
            ans[i]=s.top();
        }
        s.push(v[i]);
    }
    for(auto a:ans){
        cout<<a<<" ";

    }
    cout<<endl;
    return;
}

void smaller(vector<int> &v){ //O(n);
    int n=v.size();
    stack<int> s;
    vector<int> ans(n,-1);

    for(int i=0;i<n;i++){
        while(s.size()>0 && s.top()>=v[i]){
            s.pop();
        }
        if(s.size()!=0){
            ans[i]=s.top();
        }
        s.push(v[i]);
    }
    for(auto a:ans){
        cout<<a<<" ";

    }
    cout<<endl;
    return;
}

int main(){
    vector<int> a={3,1,0,8,6};
    solve(a);
    smaller(a);
    

}