#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-20

class Node
{
public:
    bool EoW;
    Node *children[26];

    Node()
    {
        EoW = false;
        for (ll i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node;
    }
    ~Trie()
    {
        clear(root);
    }

    void insert(string &s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int i = ch - 'a';
            if (cur->children[i] == nullptr)
            {
                cur->children[i] = new Node;
            }
            cur = cur->children[i];
        }
        cur->EoW = true;
    }

    bool find(string &s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int i = ch - 'a';
            if (cur->children[i] == nullptr)
            {
                return false;
            }
            cur = cur->children[i];
        }
        return cur->EoW;
    }

    void print(Node *cur, string s)
    {
        if (cur->EoW == true)
        {
            cout << s << " ";
        }
        for (ll i = 0; i < 26; i++)
        {
            if (cur->children[i] == nullptr)
            {
                continue;
            }
            char ch = char(i + 'a');
            print(cur->children[i], s + ch);
        }
    }
    /// int  int  int  int  int
    int del(string &s, Node *cur, int i)
    {
        if (cur == nullptr)
        {
            return 0;
        }
        if (i == s.size())
        {
            if (!cur->EoW)
            {
                return 0;
            }
            if (!isLeaf(cur))
            {
                cur->EoW = false;
                return 0;
            }
            return 1;
        }
        int j = s[i] - 'a';
        int d = del(s, cur->children[j], i + 1);

        if (d == 1)
        {
            delete cur->children[j];
            cur->children[j] = nullptr;
        }

        return isJ(cur) ? 0 : 1;
    }

    /// Helper
    bool isLeaf(Node *cur)
    {
        for (ll i = 0; i < 26; i++)
        {
            if (cur->children[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }
    bool isJ(Node *cur)
    {
        if (cur->EoW)
        {
            return true;
        }
        return !isLeaf(cur);
    }
    void clear(Node *cur)
    {
        for (int i = 0; i < 26; i++)
            if (cur->children[i])
                clear(cur->children[i]);

        delete cur;
    }
};

int main()
{
    Trie t;

    while (true)
    {
        cout << "\n=========================\n";
        cout << "1. Insert word\n";
        cout << "2. Search word\n";
        cout << "3. Delete word\n";
        cout << "4. Print all words\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";

        int op;
        cin >> op;

        if (op == 1)
        {
            string s;
            cout << "Enter word to insert: ";
            cin >> s;
            t.insert(s);
            cout << "Inserted.\n";
        }
        else if (op == 2)
        {
            string s;
            cout << "Enter word to search: ";
            cin >> s;
            cout << (t.find(s) ? "FOUND\n" : "NOT FOUND\n");
        }
        else if (op == 3)
        {
            string s;
            cout << "Enter word to delete: ";
            cin >> s;
            t.del(s, t.root, 0);
            cout << "Deleted.\n";
        }
        else if (op == 4)
        {
            cout << "Words in TRIE:\n";
            t.print(t.root, "");
        }
        else if (op == 5)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}