#include <bits/stdc++.h>
using namespace std;

// ===============================
//             NODE
// ===============================
class Node
{
public:
    bool EoW;
    Node *children[26];

    Node()
    {
        EoW = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// ===============================
//             TRIE
// ===============================
class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    ~Trie()
    {
        clear(root);
    }

    // ===============================
    //             INSERT
    // ===============================
    void insert(string &s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int j = c - 'a';
            if (cur->children[j] == nullptr)
                cur->children[j] = new Node();
            cur = cur->children[j];
        }
        cur->EoW = true;
    }

    // ===============================
    //             FIND
    // ===============================
    bool find(string &s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int j = c - 'a';
            if (cur->children[j] == nullptr)
                return false;
            cur = cur->children[j];
        }
        return cur->EoW;
    }

    // ===============================
    //            PRINT
    // ===============================
    void printTRIE(Node *cur, string s)
    {
        if (cur->EoW)
            cout << s << "\n";

        for (int i = 0; i < 26; i++)
        {
            if (cur->children[i] == nullptr)
                continue;
            char ch = char(i + 'a');
            printTRIE(cur->children[i], s + ch);
        }
    }

    // ===============================
    //            DELETE
    // ===============================
    void erase(string &s)
    {
        deleteNode(s, root, 0);
    }

    int deleteNode(string &s, Node *cur, int i)
    {
        if (cur == nullptr)
            return 0;

        if (i == s.size())
        {
            if (!cur->EoW)
                return 0;

            if (!isLeaf(cur))
            {
                cur->EoW = false;
                return 0;
            }
            return 1;
        }

        int j = s[i] - 'a';
        int d = deleteNode(s, cur->children[j], i + 1);

        if (d == 1)
        {
            delete cur->children[j];
            cur->children[j] = nullptr;
        }

        return isJunction(cur) ? 0 : 1;
    }

    // ===============================
    //           HELPERS
    // ===============================
    bool isLeaf(Node *cur)
    {
        for (int i = 0; i < 26; i++)
            if (cur->children[i] != nullptr)
                return false;
        return true;
    }

    bool isJunction(Node *cur)
    {
        if (cur->EoW)
            return true;
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

// ===============================
//             MAIN
// ===============================
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
            t.erase(s);
            cout << "Deleted.\n";
        }
        else if (op == 4)
        {
            cout << "Words in TRIE:\n";
            t.printTRIE(t.root, "");
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
