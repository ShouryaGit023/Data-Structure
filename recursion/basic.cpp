#include <bits/stdc++.h>
using namespace std;

void pyramind(int id,int n){
    if(id>=n){
        return;
    }
    for(int i=0;i<(2*id+1);i++){
        cout<<"*";
    }
    cout<<endl;
    pyramind(id+1,n);
}

int main(){
    int n;cin>>n;
    pyramind(0,n);

}