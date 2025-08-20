#include <bits/stdc++.h>
using namespace std;

int main(){
    // queue diya h usko reverse krana h 
    // can do by using q and stack together


    queue<int> a;
    a.push(4);
    a.push(3);
    a.push(1);
    a.push(10);
    a.push(2);
    a.push(6);
    stack<int>s;
    while(!(a.empty())){
        s.push(a.front());
        a.pop();
    }
    while(!(s.empty())){
        a.push(s.top());
        s.pop();
    }


    //print
    while(!(a.empty())){
        cout<<a.front()<<endl;
        a.pop();
    }



}