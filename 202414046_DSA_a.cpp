#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-18
class Node
{
public:
    bool EoW;
    Node *children[26];

    Node()
    {
        EoW = false;
        for (int i = 0; i < 26; i++)
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

    void insert(string &s)
    {
        Node *cur = root;
        for (char ch : s)
        {
            int i = ch - 'A';
            if (cur->children[i] == nullptr)
            {
                cur->children[i] = new Node;
            }
            cur = cur->children[i];
        }
        cur->EoW = true;
    }

    void collectWords(Node *cur, string currentString, vector<string> &results)
    {
        if (cur == nullptr)
            return;

        if (cur->EoW == true)
        {
            results.push_back(currentString);
        }

        for (int i = 0; i < 26; i++)
        {
            if (cur->children[i] != nullptr)
            {
                char ch = char(i + 'A');
                collectWords(cur->children[i], currentString + ch, results);
            }
        }
    }

    void searchPrefix(string &prefix, int queryNum)
    {
        Node *cur = root;
        cout << "Query " << queryNum << ": ";

        for (char ch : prefix)
        {
            int i = ch - 'A';
            if (cur->children[i] == nullptr)
            {
                cout << "No result found\n";
                return;
            }
            cur = cur->children[i];
        }

        vector<string> results;
        collectWords(cur, prefix, results);

        if (results.empty())
        {
            cout << "No result found\n";
        }
        else
        {
            for (int i = 0; i < results.size(); i++)
            {
                cout << results[i] << (i == results.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    Trie t;

    for (int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        t.insert(w);
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        string p;
        cin >> p;
        t.searchPrefix(p, i);
    }

    return 0;
}