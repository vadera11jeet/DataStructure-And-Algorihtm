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


class IsBST
{
public:
    int size_;
    bool isBST;
    int max_;
    int min_;

//    the reason of assigning max value is INT_MIN is that BST has property inorder traversal of BST give sorted value
//  right most element in left sub tree is smaller than root of tree to satisfied this rule we assign int min to max_value

    IsBST(int size_ = 0,  bool isBST = true, int max_ = INT_MIN, int min_ = INT_MAX)
    {
        this->size_ = size_;
        this->isBST = isBST;
        this->max_ = max_;
        this->min_ = min_;
    }

};

class BinarySearchTree
{
public:
    Node *root;

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

//   here we use bottom up approach so we use post order traversal
//   here we check first of all is left sub tree is BST  and right sub tree is BST

    IsBST largestBinayTreeInBST(Node *root)
    {
        if(!root)
            return IsBST();

        if(!root->left && !root->right)
            return IsBST(1);

        IsBST l = largestBinayTreeInBST(root->left);
        IsBST r = largestBinayTreeInBST(root->right);

        if(l.isBST && r.isBST && r.min_ > root->data && l.max_ < root->data)
        {
            return IsBST(1 + l.size_ + r.size_, true, min(root->data, l.min_), max(root->data, r.max_));
        }

        return IsBST(max(l.size_, r.size_), false, -1, -1);
    }


};

int main()
{
    BinarySearchTree b;

//    b.insertNode(60);
//    b.insertNode(65);
//    b.insertNode(70);
//    b.insertNode(50);

    b.root  = new Node(60);
    b.root->left = new Node(65);
    b.root->right = new Node(70);
    b.root->left->left = new Node(50);

    cout<<b.largestBinayTreeInBST(b.root).size_;

    return 0;
}
