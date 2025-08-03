#include <bits/stdc++.h>
using namespace std;
//problem 20 lc


bool isValid(string a){
    stack<char> s;
    for(int i=0;i<a.size();i++){
        if(a[i]=='(' || a[i]=='{' || a[i]=='['){
            s.push(a[i]);
        }
        else{
         if(s.size()==0){
            return false;
         }   
         if((a[i]==')' && s.top()=='(') || (a[i]=='}' && s.top()=='{') || (a[i]==']' && s.top()=='[')){
            s.pop();
         }
         else{
            return false;
         }
        }
    }
    return s.size()==0;
}
int main(){
    string s="{[()]}";
    isValid(s);

}