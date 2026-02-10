#include <bits/stdc++.h>
using namespace std;


//Q1. Frog_Jump
// Recursive part
int f(int n,vector<int>& height){
        if(n==0)return 0;
        int l=f(n-1,height)+abs(height[n]-height[n-1]);
        int r=INT_MAX;
        if(n>1){
            r=f(n-2,height)+abs(height[n]-height[n-2]);
        }
        return min(l,r);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        int ans=f(n-1,height);
        return ans;
        
    }

//DP part (memoization)
       int f(int n,vector<int>& height,vector<int>& dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int l=f(n-1,height,dp)+abs(height[n]-height[n-1]);
        int r=INT_MAX;
        if(n>1){
            r=f(n-2,height,dp)+abs(height[n]-height[n-2]);
        }
        return dp[n]=min(l,r);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n+1,-1);
        int ans=f(n-1,height,dp);
        return ans;
        
    }
// Tabulation
int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            int fs=dp[i-1]+abs(height[i]-height[i-1]);
            int ss=INT_MAX;
            if(i>1){
                ss=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(fs,ss);
        }
        return dp[n-1];
    }


int main(){

}