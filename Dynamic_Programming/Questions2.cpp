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

// Q20. Unbounded Knapsack
int solve(int id,vector<int>&val, vector<int> &wt, int capacity, vector<vector<int>> &dp){
        if(id<0 || capacity<0)return 0;
        if(dp[id][capacity]!=-1)return dp[id][capacity];
        int nt=solve(id-1,val,wt,capacity,dp);
        int t=0;
        if(wt[id]<=capacity){
            t=val[id]+solve(id,val,wt,capacity-wt[id],dp);
        }
        return dp[id][capacity]=max(t,nt);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,val,wt,capacity,dp);
        
    }
    
// Q21 Rod Cutting
int solve(int id,int len,vector<int> &v,vector<vector<int>> &dp){
        if(len==0)return 0;
        if(id<0)return 0;
        if(dp[id][len]!=-1)return dp[id][len];
        int nt=solve(id-1,len,v,dp);
        int t=0;
        if(len-1>=id){
            t=v[id]+solve(id,len-id-1,v,dp);
        }
        return dp[id][len]=max(nt,t);
    }
    int cutRod(vector<int> &p) {
        // code here
        int n=p.size();
        int len=n;
        vector<vector<int>> dp(n,vector<int>(len+1,-1));
        return solve(n-1,len,p,dp);
        
    }


//Q22/ Longest Common Subsequence
 int solve(int n,int m,string &a,string &b,vector<vector<int>> &dp){
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1]){
            return dp[n][m]=1+solve(n-1,m-1,a,b,dp);
        }
        return dp[n][m]=max(solve(n-1,m,a,b,dp), solve(n,m-1,a,b,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return solve(n,m,a,b,dp);

        //tabulation
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }     

        //printing the lcs
        set<int> s;
        string ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]!=0 && s.count(dp[i][j])==0){
                    ans.push_back(a[i-1]);
                    s.insert(dp[i][j]);
                }
            }
        }  
        cout<<ans<<endl;


        return dp[n][m];
}

//Q23 Longest Common Substring
int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }

// Q24. Longest Palindromic Substring
int solve(int n,int m,string &a,string &b,vector<vector<int>> &dp){
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1]){
            return dp[n][m]=1+solve(n-1,m-1,a,b,dp);
        }
        return dp[n][m]=max(solve(n-1,m,a,b,dp), solve(n,m-1,a,b,dp));
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
        int n=s.size();
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(n,n,s,a,dp);
        
    }


//Q25 Min no of elemets to add to make string palindromes
int solve(int i,int j,string &a, string &b, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(i-1,j-1,a,b,dp);
        }
        return dp[i][j]=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string a=s;
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //match 
                if(s[i-1]==a[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }    

//Q26. Min operation to make string equal
 int minOperations(string &a, string b) {
        // Your code goes here
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n+m-2*dp[n][m];
    }

// Q27. Smallest Common Supersequence
int minSuperSeq(string &a, string &b) {
        // code here
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=n,j=m;
        while(i> 0 && j>0){
            if(a[i-1]==b[j-1]){
                ans+=a[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=a[i-1];
                i--;
            }
            else {
                ans+=b[j-1];
                j--;
            }
        }
        while(j>0){
            ans+=b[j-1];
            j--;
        }
        while(i>0){
            ans+=a[i-1];
            i--;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        
        return n+m-dp[n][m];
        
    }

// Q29. Distinct Subsequence
int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp){
        if(j<0)return 1;
        if(i<0 && j>=0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t=0;
        int nt=0;
        if(a[i]==b[j]){
            t= solve(i-1,j-1,a,b,dp)+solve(i-1,j,a,b,dp);
        }
        if(a[i]!=b[j]){
            nt= solve(i-1,j,a,b,dp);
        }
        return dp[i][j]=nt+t;
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
        
    }

int main(){

}