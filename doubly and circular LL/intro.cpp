#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int n){
        val=n;
        next=prev=NULL;
    }
};
class DoublyList{
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head=tail=NULL;
    }

    //pushfront
    void push_front(int n){
        Node* newNode= new Node(n);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pb(int n){
        Node* newNode=new Node(n);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void popf(){
        if(head==NULL){
            cout<<"list is already empty"<<endl;
            return;
        }

        else{
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }
    void popb(){
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" <=> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

};

int main(){
    DoublyList dll;
    dll.push_front(2);
    dll.push_front(4);
    dll.pb(8);
    dll.popf();
    dll.popb();
    dll.print();

}

//flattening of circular linkedlist
// #430 lc
// making a recursive function
// tc= O(n); traversal of linked list once;

// Node* fun(Node* head){
//     if(head==NULL){
//         return head;
//     }
//     Node* temp=head;
//     while(temp!=NULL){
//         if(temp->child!=NULL){
//             //flattening of child nodes
//             Node* ahead=temp->next;
//             temp->next=fun(temp->child);
//             temp->next->prev=temp;
//             temp->child=NULL;

//             //connection with the flaten part(finding tail)
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }

//             //attaching tail with next ptr
//             if(ahead!=NULL){
//             temp->next=ahead;
//             ahead->prev=temp;

//             }  
//         }
//         temp=temp->next;

        
//     }
//     return head;
// }
