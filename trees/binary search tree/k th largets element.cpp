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


//   idea is the use reverse morris in order traversal
    void kthLargestElement(int k)
    {
        Node * curr = root;
        int count_ = 0;

        while(curr)
        {
            if(!curr->right)
            {
                count_ ++;
                if(k == count_)
                {
                    cout<< curr->data;
                    break;
                }
                curr = curr->left;
            }
            else
            {
                Node *temp = curr->right;

                while(temp->left && temp->left != curr)
                    temp = temp->left;

                if(!temp->left)
                {
                    temp->left = curr;
                    curr = curr->right;
                }
                else
                {
                    temp->left = NULL;
                    count_++;
                    if(count_ == k)
                    {
                        cout<<curr->data;
                        break;
                    }

                    curr = curr->left;
                }
            }
        }


    }

};

int main()
{
    BinarySearchTree b;

    b.insertNode(4);
    b.insertNode(2);
    b.insertNode(7);
    b.insertNode(1);
    b.insertNode(3);
    b.insertNode(6);
    b.insertNode(10);

    b.kthLargestElement(2);

    return 0;
}
