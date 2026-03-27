#include <bits/stdc++.h>
using namespace std;
//Q15 Count subset with sum equal to k
int solve(int id,int tar,vector<int>&v, vector<vector<int>>&dp){
        if(id<0){
            return tar==0;
        }
        if(dp[id][tar]!=-1)return dp[id][tar];
        int np=solve(id-1,tar,v,dp);
        int p=0;
        if(tar>=v[id]){
            p=solve(id-1,tar-v[id],v,dp);
        }
        return dp[id][tar]=(np+p);
    }
    int perfectSum(vector<int>& v, int t) {
        // code here
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        if(v[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
            if(v[0]<=t)dp[0][v[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                //not pick case;
                int np=dp[i-1][j];
                int p=0;
                if(v[i]<=j){
                    p=dp[i-1][j-v[i]];
                }
            dp[i][j]=p+np;
            }
        }
        return dp[n-1][t];
    }

    //Both the tabulation and memoization is present


// Q16 Subset with difference equal to D
int solve(int id,int tar,vector<int>&v, vector<vector<int>> &dp){
      if(id<0){
          return tar==0;
      }
      if(dp[id][tar]!=-1)return dp[id][tar];
      int np=solve(id-1,tar,v,dp);
      int p=0;
      if(tar>=v[id]){
          p=solve(id-1,tar-v[id],v,dp);
      }
      return dp[id][tar]=p+np;
      
  }
    int countPartitions(vector<int>& v, int d) {
        // Code here
        int n=v.size();
        int sum=0;
        for(auto i:v)sum+=i;
        int tar=sum+d;
        if(tar & 1)return 0;
        
        vector<vector<int>> dp(n,vector<int>(tar/2 +1 ,-1));
        return solve(n-1,tar/2,v,dp);
        
    }

int main(){

}