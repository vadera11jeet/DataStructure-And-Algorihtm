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


    void preSecOfGivenNode(Node *root, int &pre, int &sec, int key)
    {
        if(!root)
            return;

        if(root->data == key)
        {
            if(root->left)
            {
                Node *temp = root->left;
                while(temp->right)
                    temp = temp->right;
                pre = temp->data;
            }
            if(root->right)
            {
                Node *temp = root->right;
                while(temp->left)
                    temp = temp->left;
                sec = temp->data;
            }
            return;
        }

        if(root->data >= key)
        {
            sec = root->data;
            preSecOfGivenNode(root->left, pre, sec, key);
        }
        else
        {
            pre = root->data;
            preSecOfGivenNode(root->right, pre, sec, key);
        }
    }

};

int main()
{

    BinarySearchTree b;

    b.insertNode(50);
    b.insertNode(30);
    b.insertNode(70);
    b.insertNode(20);
    b.insertNode(40);
    b.insertNode(60);
    b.insertNode(80);

    int pre = INT_MIN;
    int sec = INT_MIN;

    b.preSecOfGivenNode(b.root, pre, sec, 40);
    cout<<pre<<"  "<<sec;

    return 0;
}
