#include <bits/stdc++.h> //lc 503
using namespace std;

//the thing with this que is that array is circular
// the best way to remove cyclicity is to duplicate it ( :)and it worked  )

vector<int> solve(vector<int>& nums) {
        vector<int> v=nums;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
    
        vector<int> ans(n,-1);
        stack <int> s;
        for(int i=2*n-1;i>=0;i--){
        while(s.size()>0 && s.top()<=v[i%n]){
            s.pop();
        }
        if(s.size()!=0){
            ans[i%n]=s.top();
        }
        s.push(v[i]);
    }

    return ans;
        
    }


int main(){
    vector<int> v= {1,2,1};//circular array
    vector<int> ans= solve(v);
    for(auto i:ans){
        cout<<i<<endl;
    }


}