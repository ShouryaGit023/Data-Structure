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

// Q35. Buy & Sell with Transaction Fee
int solve(int id,int buy, vector<int>&v, vector<vector<int>> &dp, int fee){
        if(id>=v.size())return 0;
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(solve(id+1,1,v,dp,fee),-v[id]+solve(id+1,0,v,dp,fee));
        }
        else{
            dp[id][buy]=max(solve(id+1,0,v,dp,fee), v[id]-fee+solve(id+1,1,v,dp,fee));
        }
        return dp[id][buy];
    }
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,v,dp,fee);
        
    }


//Q36. Longest Increasing Subsequence
int solve(int id,vector<int> &v, vector<vector<int>> &dp,int last){
        if(id<0)return 0;
        if(dp[id][last+1]!=-1)return dp[id][last+1];
        int len=solve(id-1,v,dp,last);
        if(last==-1 || v[id]<v[last]){
            len=max(len,1+solve(id-1,v,dp,id));
        }
        return dp[id][last+1]=len;
    }
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        // return solve(n-1,v,dp,-1);

        //tabulation code
        for(int i=n-1;i>=0;i--){
            for(int pi=i-1;pi>=0;pi--){
                int len=dp[i-1][pi+1];
                if(pi==0 || v[i]<v[pi]){
                    len=max(len,1+dp[i-1][i+1]);
                }
                dp[i][pi]=len;
            }
        }
        return dp[n-1][n];
        
    }

    //the space optimised code for tracing the LIS
     int lis(vector<int>& v) {
        // code here
        int lastind=0;
        int largest=1;
        int n=v.size();
        vector<int> hash(n,0);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(v[j]<v[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>largest){
                largest=dp[i];
                lastind=i;
            }
        }
        vector<int> result;
        result.push_back(v[lastind]);
        
        while (hash[lastind] != lastind) {
            lastind = hash[lastind];
            result.push_back(v[lastind]);
        }

        // The sequence is currently in reverse order
        reverse(result.begin(), result.end());

        // Printing the LIS
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
        return largest;
        
    }


    //Binary search approach of LIS
    int lis(vector<int>& v) {
        // code here
        int n=v.size();
        vector<int> ans;
        ans.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]>ans.back()){
                ans.push_back(v[i]);
            }
            else{
                auto it=lower_bound(ans.begin(),ans.end(),v[i]);
                *it=v[i];
            }
        }
        return ans.size();
        
    }

//Q37. Longest Divisible Subset
vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        int lar=1;
        int larid=0;
        vector<int> hash(n,0);
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(v[i]%v[j]==0 &&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;

                }
                if(dp[i]>lar){
                    lar=dp[i];
                    larid=i;
                }
            }
            if(dp[i]>lar){
                lar=dp[i];
                larid=i;
            }
        }
        vector<int> result;
        result.push_back(v[larid]);
        
        while (hash[larid] != larid) {
            larid = hash[larid];
            result.push_back(v[larid]);
        }

        reverse(result.begin(), result.end());

       return result;
        
    }


int main(){

}