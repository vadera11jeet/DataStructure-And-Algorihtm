#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;

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
        Node *newNode = new Node(value);
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
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            if(par->data >= value)
                par->left = newNode;
            else
                par->right = newNode;

        }
    }

    void inorder(Node *root)
    {
//      if you peform in order traversal on BST we get sorted value
        if(!root)
            return;
        inorder(root->left);
//        cout<<root->data<<"  ";
        v.push_back(root->data);
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if(!root)
            return;

        cout<<root->data<< "  ";
        preorder(root->left);
        preorder(root->right);

    }

    Node * bstToBalancedBST(int start, int end_)
    {
        if(start > end_)
            return NULL;

        int mid = (start + end_) / 2;
        Node *root = new Node(v[mid]);
        root->left = bstToBalancedBST(start, mid - 1);
        root->right = bstToBalancedBST(mid+1, end_);
        return root;
    }


};


int main()
{
    BinarySearchTree b;

    b.insertNode(10);
    b.insertNode(8);
    b.insertNode(7);
    b.insertNode(6);
    b.insertNode(5);


    b.inorder(b.root);
    b.preorder(b.root);
    cout<<endl;
    b.root = b.bstToBalancedBST(0, b.v.size()-1);
    b.preorder(b.root);

    return 0;
}
