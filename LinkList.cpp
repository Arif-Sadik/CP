#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val = 0)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head = nullptr;

public:
    //    LinkedList()
    //    {
    //        head=nullptr;
    //    }

    void createList(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            Node *newNode = new Node;
            int val;
            cin >> val;
            newNode->data = val;
            newNode->next = nullptr;

            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        cout << endl;
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "No list\n";
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void insertFirst(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Inserted at first\n";
    }

    void insertLast(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPos(int pos, int val)
    {
        if (pos < 1)
        {
            cout << "Invalid Pos\n";
        }
        else if (pos == 1)
        {
            insertFirst(val);
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = nullptr;

            Node *temp = head;
            for (int i = 2; i < pos; i++)
            {
                if (temp == nullptr)
                {
                    cout << "Insertion not possible atPos" << endl;
                }
                else
                {
                    temp = temp->next;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "Can't delete at first\n";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "deleted 1st\n";
        }
    }
    void deleteLast()
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "deleted last\n";
    }

    void deleteTargetVal(int val)
    {
        if (head->data == val)
        {
            Node *toDel = head;
            head = head->next;
            delete toDel;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr && temp->next->data != val)
            {
                temp = temp->next;
            }
            if (temp->next == nullptr)
            {
                cout << "Cant del by val: not found\n";
            }
            else
            {
                Node *toDel = temp->next;
                temp->next = temp->next->next;
                delete toDel;
            }
        }
    }

    void deletePos(int pos)
    {

        if (head == nullptr)
        {
            cout << "Invalid pos\n";
        }
        else if (pos == 1)
        {
            deleteFirst();
        }
        else
        {
            Node *temp = head;
            for (int i = 2; i < pos && temp != nullptr; i++)
            {
                temp=temp->next;
            }
            Node *toDel=temp->next;
            temp->next=temp->next->next;
            delete toDel;
        }
    }

    bool search(int val)
    {
        Node *temp=head;
        while(temp!=nullptr)
        {
            if (temp->data==val)
            {
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void sortAsc()
    {
        if (head==nullptr)
        {
            cout<<"Null";
        }
        else {
                for (Node *i=head; i->next!=nullptr; i=i->next)
                {
                    for(Node *j=i->next; j!=nullptr; j=j->next)
                    {
                        if (i->data>j->data)
                        {
                            int sw=j->data;
                            j->data=i->data;
                            i->data=sw;
                        }
                    }
                }
        }
    }

    void sortDes()
    {
        if (head==nullptr)
        {
            cout<<"Null";
        }
        else {
                for (Node *i=head; i->next!=nullptr; i=i->next)
                {
                    for(Node *j=i->next; j!=nullptr; j=j->next)
                    {
                        if (i->data<j->data)
                        {
                            int sw=j->data;
                            j->data=i->data;
                            i->data=sw;
                        }
                    }
                }
        }
    }
};

int main()
{
    LinkedList lst;
    int n;
    cin >> n;
    lst.createList(n);
    lst.printList();
    lst.insertFirst(50);
    lst.insertLast(100);
    lst.insertAtPos(3, 25);
    lst.printList();

    lst.deleteFirst();
    lst.printList();
    lst.deleteLast();
    lst.printList();
    int val;
    cout<<"del tar val: ";
    cin>>val;

    lst.deleteTargetVal(val);
    lst.printList();

    lst.deletePos(2);
    lst.printList();

    cout<<"Enter S val: ";
    cin>>val;
    //int x=lst.search(val);
    if (lst.search(val))
    {
        cout<<"Found\n";

    }
    else cout<<"Not F\n";

    lst.sortAsc();
    lst.printList();
    lst.sortDes();
    lst.printList();
}
