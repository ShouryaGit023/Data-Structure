#include <bits/stdc++.h>
using namespace std;

//here we will be making LinkedList using classes

class Node{  //to create a single node
    public:
    int data;
    Node* next;

    Node(int value){ //constructor
        data=value;
        next=NULL;
    }
};

class List{ // for the creation of the list
    Node* head;
    Node* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
    }


    //push front function
    void push_front(int val){
        Node* newNode= new Node(val);  //creating a new node
        if(head==NULL){
            head=tail=newNode;
            return;
          }
        if(head!=NULL){
            newNode->next=head;
            head=newNode;
            return;
        }
    }

    //pushback in LinkedList
    void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        if(head!=NULL){
            tail->next=newNode;
            tail=newNode;
        }
    }


    //insert in middle; 0 indexing 

    void insertMid(int val,int pos){
        if(pos<0){
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
        Node* newNode= new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }



    //pop front
    void pop_front(){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;

        delete temp;
    }

    //popback

    void pop_back(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp=head;
        
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    //search in linkedlist

    void search(int val){
        Node* temp=head;
        int id=0;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<"value found at index: "<<id<<endl;
                return;
            }
            temp=temp->next;
            id++;
        }

        cout<<"not found"<<endl;
        return;
    }


    //printing the values of linkedlist;
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }



    //reversal  //206 in lc
    void reverse(){
        Node* curr=head;
        Node* prev=NULL;
        Node* ahead=NULL;
        
        while(curr!=NULL)
        {
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
    }

    tail=head;
    head=prev;
    }

    // middle node in linkedlist (slow fast approach)  //lc 876
    void middle(){
        Node* fast=head;
        Node* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"The middle element of linked list is: "<<slow->data<<endl;
        return;
    }

};


// 




int main(){

    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    
    ll.insertMid(4,0);
    // ll.search(4);
    // ll.search(8);
    ll.print();
    ll.middle();
    ll.reverse();
    ll.push_front(89);

    ll.print();
    ll.middle();


}