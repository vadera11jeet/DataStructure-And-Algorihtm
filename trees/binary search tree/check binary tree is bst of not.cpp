#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

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
};

bool isBST(Node *root, int start_, int end_)
{
    if(!root)
        return true;
    if(root->data > end_  || root->data < start_)
        return false;
    return isBST(root->left, start_, root->data -1) && isBST(root->right, root->data +1, end_);
}


int main()
{
    BinarySearchTree b;

     Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(15);

    cout<<isBST(root, INT_MIN, INT_MAX);

    return 0;
}
