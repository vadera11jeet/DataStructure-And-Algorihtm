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

    Node * deleteAllLeafNode(Node *root)
    {
        if(!root)
            return NULL;

        if(!root->left && !root->right)
            return NULL;

        Node*left = deleteAllLeafNode(root->left);
        Node*right = deleteAllLeafNode(root->right);

        return root;

    }

};

int main()
{
    return 0;
}
