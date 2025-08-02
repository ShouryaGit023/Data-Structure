#include <iostream>
using namespace std;
// circular me rehta similar to normal but last connected to first
//  i.e no node is first and no node is last

class Node
{
public:
    int val;
    Node *next;

    Node(int n)
    {
        val = n;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void iah(int n)
    { // insert at head
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void iat(int n)
    { // insert at tail
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void dah()
    {
        if (head == NULL)
        {
            cout << "already empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void dat()
    {
        if (head == NULL)
        {
            cout << "already empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            tail=temp;
            temp=temp->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
            return;
        }
        cout << head->val << " ";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    CircularList cll;
    cll.iah(4);
    cll.iah(5);
    cll.iat(68);
    cll.dah();
    cll.dat();
    cll.dat();
    cll.print();
}