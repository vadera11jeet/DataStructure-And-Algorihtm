#include<bits/stdc++.h>
using namespace std;
// this code is inefficient approach.
// here in order traversal is applied on both BST and then create balanced BST
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

};

Node *mergeTwoBinaryTree(vector<int> v, int start, int end_)
{
    if(start > end_)
        return NULL;


    int mid = (start + end_) / 2;

    Node *root = new Node(v[mid]);

    root->left = mergeTwoBinaryTree(v, start, mid-1);
    root->right = mergeTwoBinaryTree(v, mid+1, end_);

    return root;
}

void inorder(Node *root)
{
//      if you peform in order traversal on BST we get sorted value
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<"  ";
//    v.push_back(root->data);
    inorder(root->right);
}

int main()
{
    BinarySearchTree b1, b2;

    b1.insertNode(3);
    b1.insertNode(5);
    b1.insertNode(1);

    b1.inorder(b1.root);

    b2.insertNode(4);
    b2.insertNode(6);
    b2.insertNode(2);

    b2.inorder(b2.root);

//  this is the code for merging 2 vectors
    vector<int> v(b2.v.size() + b1.v.size());
    merge(b1.v.begin(), b1.v.end() ,b2.v.begin(), b2.v.end(), v.begin());

    Node *root = mergeTwoBinaryTree(v, 0, v.size()-1);

    inorder(root);


    return 0;
}
