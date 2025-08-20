#include <bits/stdc++.h>
using namespace std;


//reversing the first k element in queue
queue <int> ans(int k,queue<int> &d){
    stack<int>s;
    while(k--){
        s.push(d.front());
        d.pop();
    } 

    queue<int> r;
    while(!(s.empty())){
        r.push(s.top());
        s.pop();
    }

    while(!(d.empty())){
        r.push(d.front());
        d.pop();
    }


    return r;

}
int main(){

    
    queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    queue<int> b=ans(3,a);

    //printing
    while(!(b.empty())){
        cout<<b.front()<<endl;
        b.pop();
    }


}

