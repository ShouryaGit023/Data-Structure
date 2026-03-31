#include <bits/stdc++.h>
using namespace std;

///Q31 Buy and Sell Stock II
int solve(int id,vector<int> &v,vector<vector<int>> &dp, bool buy){
        if(id==v.size()){
            return 0;
        }
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(solve(id+1,v,dp,buy), -v[id]+solve(id+1,v,dp,!buy));
        }
        else{
            dp[id][buy]=max(solve(id+1,v,dp,buy), v[id]+solve(id+1,v,dp,!buy));
        }
        return dp[id][buy];
    }
    int maxProfit(vector<int>& v) {
        bool buy=true;
        vector<vector<int>> dp(v.size()+1,vector<int>(2,0));
        // return solve(0,v,dp,buy);
        if(v.size()==0)return 0;
        for(int i=v.size()-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][1],-v[i]+dp[i+1][0]);
            dp[i][0]=max(dp[i+1][0],v[i]+dp[i+1][1]);
        }
        return dp[0][1];
        
    }

//Q32. Buy and sell Stock III
   int solve(int id, int buy, int cap, vector<int>& v, vector<vector<vector<int>>> &dp) {
        if (id == v.size() || cap == 0) return 0;
        
        // Use all three variables to check the cache
        if (dp[id][buy][cap] != -1) return dp[id][buy][cap];
        
        if (buy) {
            // Stay as is OR buy today
            dp[id][buy][cap] = max(solve(id + 1, 1, cap, v, dp), -v[id] + solve(id + 1, 0, cap, v, dp));
        } else {
            // Stay as is OR sell today (and decrement capacity)
            dp[id][buy][cap] = max(solve(id + 1, 0, cap, v, dp), v[id] + solve(id + 1, 1, cap - 1, v, dp));
        }
        return dp[id][buy][cap];
    }

    int maxProfit(vector<int>& v) {
        int n = v.size();
        // 3D DP: [day][can_buy][capacity] -> [n][2][3]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, v, dp);
    }

//Q34. Buy & Sell with cooldown
int solve(int id,bool buy, vector<int>&v, vector<vector<int>> &dp){
        if(id>=v.size()){
            return 0;
        }
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(-v[id]+solve(id+1,0,v,dp), solve(id+1,1,v,dp));
        }
        else{
            dp[id][buy]=max(solve(id+1,0,v,dp),v[id]+solve(id+2,1,v,dp));
        }
        return dp[id][buy];

    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        bool buy=true;
        return solve(0,1,v,dp);
        
    }



int main(){

}