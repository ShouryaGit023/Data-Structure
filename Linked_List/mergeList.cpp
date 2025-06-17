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

    // using recursive approach to check kon pehle then uske baad kon
    //  l1= 1-3-5
    // l2 2-3-6
    //
    Node *merge(Node *l1, Node *l2)
    {
        // base case;
        if (l1 == NULL || l2 == NULL)
        {
            return l1 == NULL ? l2 : l1;
        }

        if (l1->data <= l2->data)
        {
            l1->next = merge(l1->next, l2);

            return l1; // head return krega t1 ka data but uske pehle pura rec. ka karnama
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
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
