#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val = 0)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;

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
            newNode->prev = nullptr;

            if (head == nullptr)
            {
                head = newNode;
                tail = head;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        cout << endl;
    }

    void printList() // Forward
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
    void traverseBackward() // Backword
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertFirst(int val)
    {

        Node *newNode = new Node;
        newNode->data = val;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout << "Inserted at first\n";
        }
    }

    void insertLast(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            cout << "Inserted at last\n";
        }
    }

    void insertAtPos(int pos, int val) // from forword
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
            newNode->prev = nullptr;

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
            newNode->prev = temp;
            temp->next->prev = newNode;
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
            Node *toDel = head;
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }

            delete toDel;
            cout << "deleted 1st\n";
        }
    }
    void deleteLast()
    {
        if (tail == nullptr)
            return;
        Node *toDelete = tail;
        if (head == tail)
        { // one node
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete toDelete;
        cout << "deleted last\n";
    }

    void deleteTargetVal(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        // Case 1: deleting head
        if (head->data == val)
        {
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            return;
        }

        // Case 2: deleting middle/end
        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found\n";
            return;
        }

        if (temp == tail)
        { // deleting last
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        else
        { // deleting middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

        void deletePos(int pos)
    {
        if (head == nullptr)
        {
            cout << "Invalid pos\n";
            return;
        }

        if (pos == 1) // delete first
        {
            deleteFirst();
            return;
        }

        Node *temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        if (temp == tail)
        {
            deleteLast();
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }


    bool search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void sortAsc()
    {
        if (head == nullptr)
        {
            cout << "Null";
        }
        else
        {
            for (Node *i = head; i->next != nullptr; i = i->next)
            {
                for (Node *j = i->next; j != nullptr; j = j->next)
                {
                    if (i->data > j->data)
                    {
                        int sw = j->data;
                        j->data = i->data;
                        i->data = sw;
                    }
                }
            }
        }
    }

    void sortDes()
    {
        if (head == nullptr)
        {
            cout << "Null";
        }
        else
        {
            for (Node *i = head; i->next != nullptr; i = i->next)
            {
                for (Node *j = i->next; j != nullptr; j = j->next)
                {
                    if (i->data < j->data)
                    {
                        int sw = j->data;
                        j->data = i->data;
                        i->data = sw;
                    }
                }
            }
        }
    }
};

int main()
{
    DoublyLinkedList lst;
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
    cout << "del tar val: ";
    cin >> val;

    lst.deleteTargetVal(val);
    lst.printList();

    lst.deletePos(2);
    lst.printList();

    cout << "Enter S val: ";
    cin >> val;
    // int x=lst.search(val);
    if (lst.search(val))
    {
        cout << "Found\n";
    }
    else
        cout << "Not F\n";

    lst.sortAsc();
    lst.printList();
    lst.sortDes();
    lst.printList();
}
