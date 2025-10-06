#include <bits/stdc++.h>
using namespace std;

//sol of basic question by recursion 
int solve(int n,int i){ //n---> no of stairs || i---> current pos of in stair
    //base case
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    return solve(n, i+1)+solve(n, i+2);
}


//sol of main question by recurssion
int solve(vector<int> &cost,int n){  //this fails as the TC is high
    //base case;
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    int ans=cost[n]+ min(solve(cost,n-1),solve(cost,n-2));
    return ans;
}

//the DP Solution
int solve2(vector<int> &cost,int n,vector<int> &dp){ // TC&& SC-> O(n)
    //base case;
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }

    //checking for existing values
    if(dp[n]!=-1){
        return dp[n];
    }

    //storing in dp
    dp[n]=cost[n]+ min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    return dp[n];
}


//Tabulation Method
int tab(vector<int> &cost,int n){
    vector<int> t(n+1);
    t[0]=cost[0];
    t[1]=cost[1];

    for(int i=2;i<n;i++){
        t[i]=cost[i]+min(t[i-1],t[i-2]);
    }
    return min(t[n-1],t[n-2]);

}


int main(){
    vector<int> cost={10,15,20}; //ans---> 15
    int n=cost.size();
    //recursive solution
    int c=solve(cost,n);
    cout<<c<<endl;

    //dp solution 
    vector<int> dp(n+1,-1);
    int d=solve2(cost,n,dp);
    cout<<d<<endl;

    int tabul=tab(cost,n);
    cout<<tabul;



}