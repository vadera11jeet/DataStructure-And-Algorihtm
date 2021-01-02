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

    int findDistancebetween2Nodes(int val1, int val2)
    {
        Node *lca = findLCA(root, val1, val2);

        int h1 = heightOfNode(lca, val1, 0);
        int h2 = heightOfNode(lca, val2, 0);

        return h1 + h2;
    }


private:

    int heightOfNode(Node *root, int element, int level)
    {
        if(!root)
            return INT_MIN;
        if( root->data == element)
            return level;
        if(root->data >= element)
           level = heightOfNode(root->left, element, level + 1);
        else
            level = heightOfNode(root->right, element, level+1);
        return level;
    }

    Node * findLCA(Node *root, int m, int n)
    {
        if(!root)
           return NULL;

        if(root->data == m || root->data == n)
            return root;


        Node *left = findLCA(root->left, m, n);
        Node *right = findLCA(root->right, m, n);

        if(left && right)
            return root;

        return left != NULL ? left :right;

    }

};


int main()
{
    BinarySearchTree b;

    b.insertNode(20);
    b.insertNode(10);
    b.insertNode(5);
    b.insertNode(15);
    b.insertNode(30);
    b.insertNode(25);
    b.insertNode(35);

    cout<<b.findDistancebetween2Nodes(5,35);

    return 0;
}
