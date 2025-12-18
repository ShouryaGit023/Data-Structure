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

    int sum=0;
    sumSequence(0,v,n,ans,3,sum);
    cout<<endl;

    singleSumSequence(0,v,n,ans,3,sum);
    cout<<"the no. of subsequence are: "<<endl;
    cout<<countSubsequence(0,v,n,3,sum)<<endl;
    
}