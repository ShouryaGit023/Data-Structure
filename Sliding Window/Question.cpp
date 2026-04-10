#include <bits/stdc++.h>
using namespace std;

// Q1. Max points from cards
int maxScore(vector<int>& v, int k) {
        int ls=0;
        int rs=0;
        int n=v.size();
        for(int i=0;i<k;i++){
            ls+=v[i];
        }
        int ans=ls+rs;
        int l=k-1;
        int r=n-1;
        while(l>=0){
            ls-=v[l];
            rs+=v[r];
            r--;
            l--;
            ans=max(ls+rs,ans);
        }
        return ans;

    }


//Q2. Longest Substring with unique characters
int longestUniqueSubstr(string &s) {
        // code here
        map<char,int>m;
        int n=s.size();
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(m.find(s[r])!=m.end()){
                if(m[s[r]]>=l){
                    l=m[s[r]]+1;
                    
                }
               
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            
        }
        return ans;
    }


// Q3. Max Substring Length of consecutive one with atmost K flips
int longestOnes(vector<int>& v, int k) {
        int n=v.size();
        int ans=0;
        int z=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(v[r]==0)z++;
            while(z>k){
                if(v[l]==0)z--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }


int main(){

}