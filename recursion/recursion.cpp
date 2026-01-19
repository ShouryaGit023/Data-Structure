#include <bits/stdc++.h>
using namespace std;

//subsequence generation
void subset(int id,vector<int> v,int n,vector<int> &ans){
    //base case 
    if(id>=n){
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

    ans.push_back(v[id]);
    //condition of take
    subset(id+1,v,n,ans);
    //we came back so we pop and do the condition of not take;
    ans.pop_back();
    subset(id+1,v,n,ans);
}
//----------------------------------------------------------------

//Q2. Printing the subsequence with sum K
void sumSequence(int id,vector<int> v,int n,vector<int> &ans,int k,int &sum){
    if(id>=n){
        if(sum==k){
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;

        }
        return;
    }

    // take the ith element add
    ans.push_back(v[id]);
    sum+=v[id];
    sumSequence(id+1,v,n,ans,k,sum);

    //now remove for the condition of not take;
    ans.pop_back();
    sum-=v[id];
    sumSequence(id+1,v,n,ans,k,sum);
}

bool singleSumSequence(int id,vector<int> v,int n,vector<int> &ans,int k,int &sum){
    if(id>=n){
        if(sum==k){
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;

        }
        return false;
    }

    // take the ith element add
    ans.push_back(v[id]);
    sum+=v[id];

    // By doing this we ensure if the condition satisfy we wont call func for another case
    if(singleSumSequence(id+1,v,n,ans,k,sum)){
        return true;
    };

    //now remove for the condition of not take;
    ans.pop_back();
    sum-=v[id];
    if(singleSumSequence(id+1,v,n,ans,k,sum))return true;

    return false;
}

//-------------------------------------------------------------------
//Q3. Count the no of subsequence with sum equal to k;
int countSubsequence(int id,vector<int> v,int n,int k,int &sum){
    //base case with sum check
    if(id>=n){
        if(sum==k){
            return 1;
        }
        else{
            return 0;
        }
    }

    //condition of take;
    sum+=v[id];
    int l=countSubsequence(id+1,v,n,k,sum);
    //backtrack and not taking the ith value;
    sum-=v[id];
    int r=countSubsequence(id+1,v,n,k,sum);
    return l+r;
    
}

//--------------------------------------------
//Q4: Combinational Sum - I
void findCombi(int ind,int target,vector<int> &v,vector<vector<int>> &ans,vector<int> &ds){
    //base case
    if(ind==v.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    //pick the element
    if(v[ind]<=target){
        ds.push_back(v[ind]);
        findCombi(ind,target,v,ans,ds);
        ds.pop_back();
    }
    findCombi(ind+1,target,v,ans,ds);
}

vector<vector<int>> combiSum(vector<int> &v,int target){
vector<vector<int>> ans;
vector<int> ds;
findCombi(0,target, v, ans,ds);
return ans;
}


//-------------------------------------------------
//Q5. Combinational Sum- II
 void findCombo2(int id,int target, vector<int>& candidates,vector<vector<int>> & ans,vector<int> & ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=id;i<candidates.size();i++){
        if(i>id && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        ds.push_back(candidates[i]);
        findCombo2(id+1,target-candidates[i],candidates,ans,ds);
        ds.pop_back();
    }

 }

vector<vector<int>> combo2(vector<int> &candidates, int target){
    // sort the candidates to remove same sequences;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombo2(0,target,candidates,ans,ds);
    return ans;
}

//--------------------------------------------------------------
// Q6. Subset Sum-I
void findSubsetSum(int id, vector<int> &arr, int n, int sum, vector<int> &ans) {
    if (id == n) {
        ans.push_back(sum);
        return;
    }

    // pick
    findSubsetSum(id + 1, arr, n, sum + arr[id], ans);

    // not pick
    findSubsetSum(id + 1, arr, n, sum, ans);
}

vector<int> subsetSum(vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();
    findSubsetSum(0, arr, n, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

//----------------------------------------------------------------------------------
int main(){
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    vector<int> ans;
    cout<<endl;

    ans=subsetSum(v);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}