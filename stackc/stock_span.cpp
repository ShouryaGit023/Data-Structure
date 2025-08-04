#include <bits/stdc++.h>
using namespace std;


void sol(vector<int> &v){
    vector<int> ans;
    int n=v.size();
    stack<int> s;
    for(int i=0;i<n;i++){
        while(s.size()>0 && v[s.top()]<=v[i]){
            s.pop();
        }

        if(s.empty()){
            ans.push_back(i+1);
        }
        else{
            ans.push_back(i-s.top());
        }
        s.push(i);
    }

    for(auto e:ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return;

}

int main(){
    vector<int> v={100,80,60,70,60,75,85};
    sol(v);

}
//span value
//max num of days from today where price<=todays price