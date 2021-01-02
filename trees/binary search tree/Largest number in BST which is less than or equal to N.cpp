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

    void inOrder(Node *root)
    {
        if(!root)
            return;
        inOrder(root->left);
        cout<<root->data<< "  ";
        inOrder(root->right);
    }

    void largestElementIsLessThan(Node *root, int n, int & max_)
    {
        if(!root)
            return;

        if(root->data <= n)
        {
            if(root->data > max_)
                max_ = root->data;

        }

        if(root->data >= n)
            largestElementIsLessThan(root->left, n, max_);
        else
            largestElementIsLessThan(root->right, n, max_);

    }

};


int main()
{
    BinarySearchTree b;

    b.insertNode(5);
    b.insertNode(2);
    b.insertNode(12);
    b.insertNode(1);
    b.insertNode(3);
    b.insertNode(9);
    b.insertNode(21);
    b.insertNode(19);
    b.insertNode(25);

    int ma = INT_MIN;

    b.largestElementIsLessThan(b.root, 4, ma);
    cout<<ma;

    return 0;
}
