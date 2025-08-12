#include <bits/stdc++.h>
using namespace std;

//trapping rainwater LC42

//naive 
//for ith value find left max and right max and then take min of that, that becomes the amount of water that can be stored in that index

//better approach
//finding lmax and rmax in array

void better(vector<int> &v){
    int n=v.size();
    vector<int> lm(n,0),rm(n,0);
    lm[0]=v[0];
    rm[n-1]=v[n-1];
    for(int i=1;i<n;i++){
        lm[i]=max(lm[i-1],v[i]);
    }
    for(int i=n-2;i>=0;i--){
        rm[i]=max(rm[i+1],v[i]);
    }

    int ans=0;
    for(int i=1;i<n-1;i++){
        ans+=min(lm[i],rm[i])-v[i];
    }
    cout<<ans<<endl;
    
}

//another approach would be to optimise the space complexity of this
//using two pointer to simultaneously find the left and right max and then calculate the water in the ith index

void ultra(vector<int> &v){
    int n=v.size();
    int lm=0,rm=0;
    int l=0,r=n-1;
    int ans=0;
    while(l<r){
        lm=max(lm,v[l]);
        rm=max(rm,v[r]);

        if(lm<rm){
            ans+=lm-v[l];
            l++;
        }
        else{
            ans+=rm-v[r];
            r--;
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){

vector<int> v={4,2,0,3,2,5};
better(v);
ultra(v);

}