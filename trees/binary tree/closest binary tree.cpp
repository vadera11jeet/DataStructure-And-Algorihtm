#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

// this is bfs approach
// there is also recursive approach also

// in this problem we have to find continuous tree or not
// A tree is a Continuous tree if in each root to leaf path, the absolute difference between keys of two adjacent is 1.
//We are given a binary tree, we need to check if the tree is continuous or not.

class Node
{
public:
    int data;
    Node *right, *left;

    Node(int data = 0, Node * right = NULL, Node * left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

class BinaryTree
{
public :
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    void insertNode(int value)
    {
        Node *temp = new Node(value);
        if(root == NULL)
        {
            root = temp;
            return;
        }

        queue <Node *> q;
        q.push(root);

        while(!q.empty())
        {
            Node * temp1 = q.front();
            q.pop();

            if(temp1->left == NULL)
            {
                temp1->left = temp;
                return;
            }
            else
            {
                q.push(temp1->left);
            }
             if(temp1->right == NULL)
            {
                temp1->right = temp;
                return;
            }
            else
            {
                q.push(temp1->right);
            }

        }
    }

    void inOrderTraversal(Node *temp)
    {
        if(temp == NULL)
            return;
        inOrderTraversal(temp->left);
        cout<<temp->data<<" ";
        inOrderTraversal(temp->right);
    }

    bool continous()
    {
        if(root == NULL)
            return true;

        else if(root->right == NULL && root->left == NULL)
            return true;

        else if(root->left != NULL && root->right == NULL)
            return (abs(root->data- root->left->data) == 1);

        else if(root->right != NULL && root->left == NULL)
            return (abs(root->data- root->right->data) == 1);

        else
        {
            queue <Node * > q;
            q.push(root);

            while(!q.empty())
            {
                Node * temp = q.front();
                q.pop();

                if(temp->right != NULL && temp->left != NULL)
                {
                    if(abs(temp->data - temp->right->data) == 1 && abs(temp->data - temp->left->data) == 1)
                    {
                        q.push(temp->left);
                        q.push(temp->right);
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(temp->right != NULL && temp->left == NULL)
                {
                    if(abs(temp->data - temp->right->data) == 1)
                    {
                        q.push(temp->right);
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(temp->left != NULL && temp->right == NULL)
                {
                    if(abs(temp->data - temp->left->data) == 1)
                    {
                        q.push(temp->left);
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            return true;
        }
    }

};

int main()
{
    BinaryTree b;
    b.insertNode(7);
    b.insertNode(5);
    b.insertNode(8);
    b.insertNode(6);
    b.insertNode(4);
    b.insertNode(10);
//    b.inOrderTraversal(b.root);
    b.continous() ? cout<<"yes" : cout<< "NO";
    return 0;
}
