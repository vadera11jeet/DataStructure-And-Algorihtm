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

    void kthSmallestElement(int k)
    {
        if(!root)
            return;
        Node *curr = root;
        Node *prev;
        int count_ = 0;
        while(curr)
        {
            if(!curr->left)
            {
                count_++;
                if(count_ == k)
                    cout<<curr->data<< "  ";
                curr = curr->right;
            }
            else
            {
                prev = curr->left;
                while(prev->right && prev->right != curr)
                    prev = prev ->right;

                if(!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    count_ ++;
                    if(count_ == k)
                        cout<<curr->data;
                    curr = curr->right;
                }
            }
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


    b.kthSmallestElement(3);

    return 0;
}
