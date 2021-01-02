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

    bool isDeadEnd(Node *root, int start = 1, int end_ = INT_MAX)
    {
        if(!root)
            return false;
        if(start == end_)
            return true;
        return isDeadEnd(root->left, start, root->data-1) || isDeadEnd(root->right, root->data +1, end_);
    }

};

int main()
{
    BinarySearchTree b;

    b.insertNode(8);
    b.insertNode(5);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(7);
    b.insertNode(11);
    b.insertNode(4);

    cout<<b.isDeadEnd(b.root);

    return 0;
}
