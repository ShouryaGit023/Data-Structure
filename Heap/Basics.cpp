#include <bits/stdc++.h>
using namespace std;
//implementing the max heap (parent > child)
class heap{
    public:
    int v[100];
    int size=0;

    void insert(int val){
        size++;
        int id=size;
        v[id]=val;

        //insertion done
        //now placing to its correct position
        while(id>1){
            int p=id/2;
            if(v[p]< v[id]){
                swap(v[p],v[id]);
                id=p;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    void del(){
        if(size==0){
            cout<<"already empty"<<endl;
            return;
        }
        //put last val to its first
        v[1]=v[size];

        size--;
        int i=1;
        while(i<size){
            int lci=2*i;
            int rci=lci+1;
            
            if(lci < size && v[lci]>v[i]){
                swap(v[lci],v[i]);
                i=lci;
            }
            else if(rci < size && v[rci]>v[i]){
                swap(v[rci],v[i]);
                i=rci;
            }
            else{
                return;
            }
        }

    }

    

};
void heapify(vector<int>&arr, int n, int i)
{
    // Initialize largest as root
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


int main(){
 heap h;
 h.insert(54);
 h.insert(53);
 h.insert(55);
 h.insert(52);
 h.insert(50);
 h.print();
 cout<<endl;
 cout<<"heapify"<<endl;

 vector<int> v={2,3,4,5,21,20,9};
 int n=v.size();
 for(int i=(n/2)-1;i>=0;i--){
    heapify(v,n,i);
 }
 for(auto i:v){
    cout<<i<<" ";
 }
 cout<<endl;

}