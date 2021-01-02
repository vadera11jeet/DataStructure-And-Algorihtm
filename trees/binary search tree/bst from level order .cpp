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

    void inorder(Node *root)
    {
        if(!root)
            return;
        inorder(root->left);
        cout<<root->data<< "  ";
        inorder(root->right);
    }

};
    Node * bstFromLevelOrderTraversal(vector<int> v)
    {
        if(v.size() == 0)
            return NULL;
        Node * root = new Node(v[0]);
        vector<int> l, r;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i] <= root->data)
                l.push_back(v[i]);
            else
                r.push_back(v[i]);
        }
        root->left = bstFromLevelOrderTraversal(l);
        root->right = bstFromLevelOrderTraversal(r);
        return root;
    }


int main()
{
    vector<int> v = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    BinarySearchTree b;

    Node *root = bstFromLevelOrderTraversal(v);
    b.inorder(root);

    return 0;
}
