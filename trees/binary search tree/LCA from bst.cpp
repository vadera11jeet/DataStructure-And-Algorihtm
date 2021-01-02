#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data = INT_MIN, Node *right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

class BinarySearchTree
{
public:
    Node *root;
    vector<int> v;


    BinarySearchTree()
    {
        root = NULL;
    }

    void insertNode(int value)
    {
        Node * newNode = new Node(value);

        if(!root)
            root = newNode;
        else
        {
            Node *temp = root;
            Node *par;

            while(temp)
            {
                par = temp;
                if(temp->data >= value)
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if(par->data >= value)
                par->left = newNode;
            else
                par->right = newNode;

        }

    }

    int LCAofBST(Node *root, int n, int m)
    {
        if(root->data > max(n, m))
            return LCAofBST(root->left, n, m);
        else if(root->data < min(n,m))
            return LCAofBST(root->right, n, m);
        else
            return root->data;
    }

};


int main()
{
    BinarySearchTree b;

    b.insertNode(20);
    b.insertNode(8);
    b.insertNode(22);
    b.insertNode(4);
    b.insertNode(12);
    b.insertNode(10);
    b.insertNode(14);

    cout<<b.LCAofBST(b.root, 10, 14);

    return 0;
}
