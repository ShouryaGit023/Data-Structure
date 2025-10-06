//using both Top down and Bottom up approach to write this fibo in best time complexity

#include <bits/stdc++.h>
using namespace std;


//below is the basic recursive appraoch 
int fibo(int n){ 
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

//using recursion + memoisation 
int rm(int n, vector<int> &dp){ //O(n) ans SC-> O(n);
    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n]=rm(n-1,dp)+rm(n-2,dp);

}

//using tabulation method
int tab(int n, vector<int> &t){ // TC & SC---> O(n)
    if(n<=1){
        return n;
    }
    for(int i=2;i<=n;i++){
        t[i]=t[i-1]+t[i-2];
    }
    return t[n];
}




int main(){
    int n;cin>>n;
    vector<int> dp(n+1, -1);
    //calling the fun of memoisation 
    rm(n,dp);
    cout<<dp[n]<<endl;

    //tabulation
    vector<int> t(n+1);
    t[0]=0;
    t[1]=1;

    cout<<tab(n,t);



}