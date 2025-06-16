#include <bits/stdc++.h>
using namespace std;

class Node
{ // to create a single node
public:
    int data;
    Node *next;

    Node(int value)
    { // constructor
        data = value;
        next = NULL;
    }
};

class List
{ // for the creation of the list
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // push front function
    void push_front(int val)
    {
        Node *newNode = new Node(val); // creating a new node
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        if (head != NULL)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    // pushback in LinkedList
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        if (head != NULL)
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // insert in middle; 0 indexing

    void insertMid(int val, int pos)
    {
        if (pos < 0)
        {
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // pop front
    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    // popback

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
            return;
        }
        Node *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // printing the values of linkedlist;
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }



    //method using slow and fast method
    bool loop(){//how to detect? when slow ==fast that means list has one loop
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }

    // //starting point of the cycle is same as that of the array wala thingy

    // void start(){
    //     if(loop()){
    //         slow=head;
    //         while(slow!=fast){
    //             slow->next;
                    //prev=fast;
    //             fast->next;

    //         }
                //prev=NULL   tp remove the cycle
    //         return fast;
    //     }
    // }


    //to remove the cycle just loop me start ke pehle wale ka next null krdo
};




//problem 141 lc [checking linkedlist has cycle or not]
int main()
{



}