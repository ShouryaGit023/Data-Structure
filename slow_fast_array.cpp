#include <bits/stdc++.h>
using namespace std;

void slow_fast(vector<int> v, int size){
int s=v[0];
int f=v[0];
do{
    s=v[s]; //slow ++;
    f=v[v[f]]; // fast +=2;
}while(s!=f);

s=v[0];
while(s!=f){
    s=v[s];
    f=v[f];
}
cout<<s<<endl;
return;
}

int main(){
vector<int> v={ 4,1,3,4,2}; // assume like [(3,0), (1,1), (3,2), (4,3), (2,4)]

slow_fast(v,5);
}