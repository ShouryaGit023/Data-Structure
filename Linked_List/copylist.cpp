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

//soltuion 

    Node* copyRand(Node* head){
        if(head==NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> m;
        Node* newHead= new Node(head->data);
        Node* oldTemp= head->next;
        Node* newTemp= newHead;
        m[head]=newHead;
        //simple copy of linked list
        while(oldTemp!=NULL){
            Node* copyNode=new Node(oldTemp->data);
            m[oldTemp]=copyNode;
            newTemp->next=copyNode;
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }

        oldTemp=head;
        newTemp=newHead;
        while(oldTemp!=NULL){
            // newTemp->random=m[oldTemp->random];   commented this as this was showing error as no random pointer was here
             oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }

        return newHead;


    }

};


int main()
{

    List l1;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(1);

    List l2;
    l2.push_front(6);
    l2.push_front(3);
    l2.push_front(2);
}

// lc 138 copy linked list from random pointer
