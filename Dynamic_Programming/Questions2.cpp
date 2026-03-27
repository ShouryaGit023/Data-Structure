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

    //Q17 KnapSack
    int solve(int id,int W,vector<int> &v, vector<int> &w,vector<vector<int>>&dp){
        if(id<0 || W==0){
            return 0;
        }
        if(dp[id][W]!=-1)return dp[id][W];
        int np=solve(id-1,W,v,w,dp);
        int p=0;
        if(W>=w[id]){
            p=v[id]+solve(id-1,W-w[id],v,w,dp);
        }
        return dp[id][W]=max(np,p);
    }
    int knapsack(int W, vector<int> &v, vector<int> &w) {
        // code here
        int n=v.size();
        vector<vector<int>> dp(n, vector<int> (W+1,-1));
        return solve(n-1,W,v,w,dp);
    }

    //tabulation approach
    int knapsack(int W, vector<int> &v, vector<int> &w) {
        // code here
        int n=v.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=W;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
            //not pick
            int np=dp[i-1][j];
            
            int p=0;
            if(w[i-1]<=j){
                p=v[i-1]+dp[i-1][j-w[i-1]];
            }
            dp[i][j]=max(p,np);
            }
        }
        return dp[n][W];
    }

//Q18. Min coin change
int solve(int id,vector<int> &v,int sum,vector<vector<int>> &dp){
        if(sum==0)return 0;
        if(sum<0 || id>=v.size())return 1e9;
        if(dp[id][sum]!=-1)return dp[id][sum];
        int nt=solve(id+1,v,sum,dp);
        int t=1e9;
        if(sum>=v[id] && v[id]>0){
            int res = solve(id, v, sum - v[id], dp);
            if (res != 1e9) {
                t = 1 + res;
            }
        }
        return dp[id][sum]=min(t,nt);
    }
    int minCoins(vector<int> &v, int sum) {
        // code here
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int ans=solve(0,v,sum,dp);
    
        return (ans>=1e9) ? -1 : ans;
    }

// Q19 Target Sum
int solve(int id,vector<int> &v, int t,vector<vector<int>> &dp){
        if(id<0){
            return t==0;
        }
        if(dp[id][t]!=-1)return dp[id][t];
        int nt=solve(id-1,v,t,dp);
        int p=0;
        if(v[id]<=t){
            p=solve(id-1,v,t-v[id],dp);
        }
        return dp[id][t]=p+nt;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n=v.size();
        int a=0;
        for(auto i:v)a+=i;
        if (abs(t) > a) return 0;
        int sum=t+a;
        if(sum & 1)return 0;
        vector<vector<int>> dp(n,vector<int>(sum/2 + 1,-1));
        return solve(n-1,v,sum/2,dp);
        
    }


int main(){

}