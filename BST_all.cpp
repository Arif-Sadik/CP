#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right, *parent;

    Node(int val)
    {
        data = val;
        left = right = parent = nullptr;
    }
}; // <-- Added missing semicolon

class BST
{
    Node *root;

public:
    BST() // <-- Fixed constructor syntax
    {
        root = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val); // <-- Use constructor to set value
        newNode->parent = newNode->left = newNode->right = nullptr;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        Node *temp = root;
        Node *prev = nullptr;

        while (temp)
        {
            prev = temp;
            if (val < temp->data) // <-- Fixed temp->val -> temp->data
            {
                temp = temp->left;
            }
            else
                temp = temp->right; // <-- Fixed typo rigth -> right
        }
        newNode->parent = prev;
        if (newNode->data < prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }

    void delData(int val) // <-- Fixed name
    {
        Node *toDel = root;
        Node *temp = nullptr;

        while (toDel && toDel->data != val) /// Find node
        {
            if (val < toDel->data)
                toDel = toDel->left;
            else
                toDel = toDel->right;
        }
        if (!toDel)
            return;

        // 0 Child
        if (!toDel->left && !toDel->right)
        {
            if (toDel == root)
                root = nullptr;
            else
            {
                temp = toDel->parent;
                if (temp->left == toDel)
                    temp->left = nullptr;
                else
                    temp->right = nullptr;
            }
            delete toDel;
        }
        // 1 Child
        else if (!toDel->left || !toDel->right)
        {
            Node *child = (toDel->left) ? toDel->left : toDel->right;
            child->parent = toDel->parent;

            if (toDel == root)
                root = child;
            else
            {
                temp = toDel->parent;
                if (temp->left == toDel)
                    temp->left = child;
                else
                    temp->right = child;
            }
            delete toDel;
        }
        // 2 Children
        else
        {
            Node *succ = toDel->right;
            while (succ->left)
                succ = succ->left; /// smallest greater value x

            toDel->data = succ->data; // replace value

            // delete successor
            Node* succParent = succ->parent;
            Node* succChild = succ->right; // successor cannot have left child

            if (succParent->left == succ)
                succParent->left = succChild;
            else
                succParent->right = succChild;

            if (succChild)
                succChild->parent = succParent;

            delete succ;
        }
    }

    void inOrder(Node *temp)
    {
        if (!temp)
            return;
        inOrder(temp->left); /// 1. left   2. print     3. right
        cout << temp->data << " ";
        inOrder(temp->right);
    }

    void preOrder(Node *temp)
    {
        if (!temp)
            return;
        cout << temp->data << " "; /// 1. print   2. left    3. right
        preOrder(temp->left);
        preOrder(temp->right);
    }

    void postOrder(Node *temp)
    {
        if (!temp)
            return; /// 1.left   2. right     3.print
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }

    // Wrapper functions to call traversals easily
    void inOrder() { inOrder(root); cout << endl; }
    void preOrder() { preOrder(root); cout << endl; }
    void postOrder() { postOrder(root); cout << endl; }

    Node *search(int val)
    {
        Node *temp = root;
        while (temp)
        {
            if (temp->data == val)
                return temp;
            else if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return nullptr;
    }

    Node *findMin()
    {
        Node *temp = root;
        while (temp && temp->left)
            temp = temp->left;
        return temp;
    }

    Node *findMax()
    {
        Node *temp = root;
        while (temp && temp->right)
            temp = temp->right;
        return temp;
    }

    void sortA(Node *temp, vector<int> &sorted)
    {
        if (!temp)
            return;
        sortA(temp->left, sorted);        /// 1. left   2.push_back   3. right
        sorted.push_back(temp->data);
        sortA(temp->right, sorted);
    }

    Node *findSuccessor(Node *temp)
    {
        if (!temp)
            return nullptr;
        if (temp->right)
        {
            Node *cur = temp->right;
            while (cur->left)
                cur = cur->left;
            return cur;
        }
        Node *cur = temp->parent;
        while (cur && temp == cur->right)
        {
            temp = cur;
            cur = cur->parent;
        }
        return cur;
    }

    Node *findPredecessor(Node *temp)
    {
        if (!temp)
            return nullptr;
        if (temp->left)
        {
            Node *cur = temp->left;
            while (cur->right)
                cur = cur->right;
            return cur;
        }
        Node *cur = temp->parent;
        while (cur && temp == cur->left)
        {
            temp = cur;
            cur = cur->parent;
        }
        return cur;
    }

    Node* getRoot() { return root; } // <-- Added getter for root
};

int main()
{
    BST bst;
    vector<int> arr = {50, 20, 60, 10, 40, 70, 30};
    for (int x : arr)
        bst.insert(x);

    cout << "Inorder: ";
    bst.inOrder();

    cout << "Preorder: ";
    bst.preOrder();

    cout << "Postorder: ";
    bst.postOrder();

    Node* found = bst.search(40);
    if (found)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    cout << "Minimum: " << bst.findMin()->data << endl;
    cout << "Maximum: " << bst.findMax()->data << endl;

    cout << "Deleting 20...\n";
    bst.delData(20);

    cout << "Inorder after deletion: ";
    bst.inOrder();

    vector<int> sorted;
    bst.sortA(bst.getRoot(), sorted);
    cout << "Sorted array using BST: ";
    for (int x : sorted)
        cout << x << " ";
    cout << endl;

    return 0;
}
