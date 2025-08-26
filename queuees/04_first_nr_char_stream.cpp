#include <bits/stdc++.h>
using namespace std;

string solve(string &s){
    string ans="";
    int n=s.size();
    queue<char>d;
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        d.push(s[i]);
        while(!d.empty()){
          if(m[d.front()]>1){
            d.pop();
          }
          else{
            ans+=d.front();
            break;
          }

        }


        if(d.size()==0){
            ans+='#';
        }
        
    }
    return ans;
}

int main(){
//stream  a a b  c
//op      a # b b;
// logic : map me freq check krke queue me dalte jao and when found q.front is char,remove that ele and print new q.front


string a="aabc";
string ans=solve(a);
cout<<ans<<endl;



}