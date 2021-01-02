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
        cout<<root->data<<"  ";
        inorder(root->right);
    }


    void deleteNode(int value)
    {
        if(!root)
            return;

        Node *parent, *curr, *temp;
        curr = root;
//       searching node which you want to delete
        while(curr && curr->data != value)
        {
            parent = curr;
            if(curr->data >value)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
//      delete node which have 2 children
        if(curr->left && curr->right)
        {
            temp = curr->right;
            while(temp->left)
            {
                parent = temp;
                temp = temp -> left;
            }
            curr->data = temp->data;
            parent->left = NULL;
            delete temp;
        }
//      delete node with only one child
        else if(curr->left || curr->right)
        {
            if(curr->left)
            {
                temp = curr->left;
                curr->data = curr->left->data;
                curr->left = NULL;
                delete temp;
            }
            else
            {
                temp = curr->right;
                curr->data = curr->right->data;
                curr->right = NULL;
                delete temp;
            }
        }
//     delete leaf node
        else
        {
            if(parent->left == curr)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
    }

};


int main()
{
    BinarySearchTree b;

    b.insertNode(8);
    b.insertNode(3);
    b.insertNode(10);
    b.insertNode(1);
    b.insertNode(6);
    b.insertNode(4);
    b.insertNode(7);
    b.insertNode(14);
    b.insertNode(13);

    b.inorder(b.root);
    cout<<endl;
    b.deleteNode(7);
    b.inorder(b.root);
    cout<<endl;
    b.deleteNode(14);
    b.inorder(b.root);
    cout<<endl;
    b.deleteNode(3);
    b.inorder(b.root);

    return 0;
}



