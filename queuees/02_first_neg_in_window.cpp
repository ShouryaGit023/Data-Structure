#include <bits/stdc++.h>
using namespace std;


// find the first neg ele in the window size of k

vector<int> solve(vector<int> &a,int n,int k){
    deque<int> d;
    vector<int> ans;

    //process the first window
    for(int i=0;i<k;i++){
        if(a[i]<0){
            d.push_back(i);
        }
    }

    //store the ans for the first k size
    if(d.size()>0){
        ans.push_back(a[d.front()]);

    }
    else{
        ans.push_back(0);
    }


    //process of rem ele
    for(int i=k;i<n;i++){
        if(!d.empty() && i-d.front()>=k){
            d.pop_front();
        }

        // pushing current ele in deque
        if(a[i]<0){
            d.push_back(i);
        }
       


        if(d.size()>0){
            ans.push_back(a[d.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;

}


int main(){
    vector<int> a={-8,2,3,-6,10};

    vector<int> ans=solve(a,5,2);

    for(auto i: ans){
        cout<<i<<" ";
    }



}