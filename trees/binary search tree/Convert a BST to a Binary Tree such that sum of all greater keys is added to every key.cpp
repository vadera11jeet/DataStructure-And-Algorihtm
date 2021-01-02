#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

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
    Node *root ;

    BinarySearchTree()
    {
        root = NULL;
    }

    void insertNode(int value)
    {
        Node *temp = new Node(value);
        if(!root)
            root = temp;
        else
        {
            Node *temp1 = root;
            Node *temp2 ;
            while(temp1)
            {
                temp2 = temp1;
                if(value <= temp1->data)
                {
                    temp1 = temp1->left;
                }
                else
                {
                    temp1 = temp1->right;
                }
            }
            if(temp2->data >= value)
                temp2->left = temp;
            else
                temp2->right = temp;
        }
    }

    void inorder(Node *root)
    {
        if(!root)
            return ;
        inorder(root->left);
        cout<<root->data<< "  ";
        inorder(root->right);
    }

    void addGreaterElementSum(Node *root, int &sum)
    {
        if(!root)
            return;

        addGreaterElementSum(root->right, sum);
        root->data += sum;
        sum += (root->data - sum);
        addGreaterElementSum(root->left, sum);

    }

};

int main()
{
    BinarySearchTree b;

    b.insertNode(5);
    b.insertNode(2);
    b.insertNode(13);


    b.inorder(b.root);
    cout<<endl;
    int sum = 0;
    b.addGreaterElementSum(b.root,sum );
    b.inorder(b.root);


    return 0;
}
