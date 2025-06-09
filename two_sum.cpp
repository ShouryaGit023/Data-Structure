#include <bits/stdc++.h>
using namespace std;
//  assuming unique solution
// brute force will take O(n*n);
void twosum(vector<int> &v,int size,int target){  //this is the better approach  O(nlogn)(sorting)
    sort(v.begin(),v.end());
    int s=0,e=size-1;
    while(s<e){
        if(v[s]+v[e]==target){
            cout<<v[s]<<" "<<v[e];
            return;
        }
        if(v[s]+v[e]>target){
            e--;
        }
        else{
            s++;
        }
    }
}

//optimised approach  O(n) (using unordered maps)

void ots(vector<int> &v,int size,int target){
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        int f=v[i];
        int s=target-f;
        if(m.find(s)!=m.end()){
            cout<<f<<" "<<s<<endl;//returns value, if index: cout<<i<<" "<<m[s];
            return;
        }
        m[v[i]]=i;
    }
}

int main(){
vector<int> v={5,2,11,7,15};
int t=9;
// twosum(v,5,t);
ots(v,5,t);
}



// another problem was FIND MISSING AND DUBLICATE   TC (O(n*n)) 2-D grid tha !
// dublicate using unordered set and then missing using sum wala funda!