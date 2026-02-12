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
    int sub=0;
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
            cur->sub++;            
        }
        cur->EoW = true;
    }

    int start(string &s)
    {
        Node *cur =root;
        for (auto ch: s)
        {
            int j=ch-'a';
            if (cur->children[j]==nullptr)
            {
                return 0;
            }
            else {
                cur=cur->children[j];
            }
        }
        return cur->sub;
    }



};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie t;
    ll n, k, x, c, d, q;
    cin >> n >> q;
    string s;

    while (n--)
    {
        cin >> s;
        t.insert(s);
    }
    while (q--)
    {
        cin>>s;
        cout<<t.start(s)<<endl;

    }
    return 0;
}