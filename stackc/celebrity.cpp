#include <bits/stdc++.h>
using namespace std;
// find who is the celebrity in the matrix
// celebrity: who is known to all but doesnt knows anyone

//a[i][celeb]==1 and a[celeb][i]==0 for all 0<=i<n

//basic logic
//if a[i][j]==0 it means j can never be celebrity
// if a[i][j]==1 it means i can never be the celebrity

int celeb(vector<vector<int>> &v){
    int n=v.size();
    stack <int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        // check for who can be celeb among a and b and push potential candidate again to stack till only one element is left
        if(v[a][b]==0){
            //b canot be the celebrity
            s.push(a);
        }
        else if(v[a][b]==1){
                //b can be the celebrity
                s.push(b);
        }

    }

    int celeb=s.top();
    for(int i=0;i<n;i++){
        if(i!=celeb && (v[celeb][i]==1 || v[i][celeb]==0)){
            return -1;
        }
    }
    return celeb;

}

//O(n) time complexity and space complexity


int main(){
    vector<vector<int>> v={{0,1,0}, {0,0,0}, {0,1,0}};
    int ans= celeb(v);
    cout<<ans<<endl;
    
}