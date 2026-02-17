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
//------------------------------------------------------------------------------------------
//Q2. Max sum of non adjacent element
//Recursion part
int f(int ind,vector<int> &v){
      if(ind<0)return 0;
      int pick=v[ind]+f(ind-2,v);
      int np=0+f(ind-1,v);
      return max(pick,np);
  }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& v) {
        // code here
        int n=v.size();
        return f(n-1,v);
        
    }

//DP memoisation
int f(int ind,vector<int> &v, vector<int> &dp){
      if(ind<0)return 0;
      if(dp[ind]!=-1){
          return dp[ind];
      }
      int pick=v[ind]+f(ind-2,v,dp);
      int np=0+f(ind-1,v,dp);
      return dp[ind]=max(pick,np);
  }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& v) {
        // code here
        int n=v.size();
        vector<int> dp(n,-1);
        f(n-1,v,dp);
        return dp[n-1];
        
        
    }

//Tabulation
int findMaxSum(vector<int>& v) {
        // code here
        int n=v.size();
        vector<int> dp(n,-1);
        dp[0]=v[0];
        for(int i=1;i<n;i++){
            int p=v[i];
            
            if(i>=2)p+=dp[i-2];
            int np=0+dp[i-1];
            
            dp[i]=max(p,np);
        }
        return dp[n-1];
        
        
    }
    //--------------------------------------------------
//Q3. House Robbery
int robLinear(vector<int>& nums, int l, int r) {
    int len = r - l + 1;
    vector<int> dp(len);

    dp[0] = nums[l];
    if (len > 1)
        dp[1] = max(nums[l], nums[l+1]);

    for (int i = 2; i < len; i++) {
        dp[i] = max(nums[l+i] + dp[i-2], dp[i-1]);
    }
    return dp[len-1];
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int c1=robLinear(nums,0,n-2);
        int c2=robLinear(nums,1,n-1);
        return max(c1,c2);
    }

//-----------------------------------------------
//Q4. Ninja Training
int solve(int day,int last,vector<vector<int>> &mat,vector<vector<int>> &dp){
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1)return dp[day][last];
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int skill=mat[day][i]+solve(day-1,i,mat,dp);
                maxi=max(maxi,skill);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(n-1,3,mat,dp);

        
    }

//---------------------------------------------
// Q5. No of Unique Paths
int solve(int m,int n,int a,int b,vector<vector<int>> &dp){
        if(a==(m-1) && b==(n-1)){
            return 1;
        }
        if(a>=m || b>=n){
            return 0;
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        int left=solve(m,n,a+1,b,dp);
        int right=solve(m,n,a,b+1,dp);
        return dp[a][b]=left+right;
    }
    int numberOfPaths(int m, int n) {
        // code here
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
        
        
    }

    //tabulation
    int numberOfPaths(int m, int n) {
        // code here
        vector<vector<int>>dp(m,vector<int>(n,1));
        
        // tabulation
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
        
    }
        


int main(){

}