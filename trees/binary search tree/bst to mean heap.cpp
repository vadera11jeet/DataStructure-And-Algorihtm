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

    void preorder(Node *root)
    {
        if(!root)
            return;
        cout<<root->data<< "  ";
        preorder(root->left);
        preorder(root->right);
    }

    void BSTToMinHeap()
    {
        inorderToArray(root);
        int i = 0;
        minHeap(root, v, i);
    }

private:
    void minHeap(Node*root, vector<int> &v, int &i)
    {
        if(!root)
            return;
        root->data = v[i++];
        minHeap(root->left, v, i);
        minHeap(root->right, v, i);
    }
    void inorderToArray(Node *root)
    {
        if(!root)
            return;
        inorderToArray(root->left);
        v.push_back(root->data);
        inorderToArray(root->right);
    }

};
// pre order on min heap give sorted array

int main()
{
    BinarySearchTree b;

    b.insertNode(8);
    b.insertNode(4);
    b.insertNode(12);
    b.insertNode(2);
    b.insertNode(6);
    b.insertNode(10);
    b.insertNode(14);

    b.preorder(b.root);
    cout<<endl;
    b.BSTToMinHeap();
    b.preorder(b.root);

    return 0;
}
