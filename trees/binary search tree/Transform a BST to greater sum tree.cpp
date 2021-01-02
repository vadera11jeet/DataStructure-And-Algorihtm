// Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.
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
        if(!root)
            return;
        inorder(root->left);
        cout<<root->data<< "  ";
        inorder(root->right);
    }

    void BSTGreaterSum(Node *root,int & sum)
    {
        if(!root)
            return;

        BSTGreaterSum(root->right, sum);
        sum += root->data;
        root->data = sum - root->data;
        BSTGreaterSum(root->left, sum);

    }
};

int main()
{

    BinarySearchTree b;

//    b.insertNode(4);
//    b.insertNode(2);
//    b.insertNode(6);
//    b.insertNode(5);
//    b.insertNode(7);
//    b.insertNode(3);
//    b.insertNode(1);

    b.insertNode(11);
    b.insertNode(2);
    b.insertNode(29);
    b.insertNode(1);
    b.insertNode(7);
    b.insertNode(15);
    b.insertNode(40);
    b.insertNode(35);

    b.inorder(b.root);
    int sum = 0;
    b.BSTGreaterSum(b.root, sum);
    cout<<endl;
    b.inorder(b.root);



    return 0;
}
