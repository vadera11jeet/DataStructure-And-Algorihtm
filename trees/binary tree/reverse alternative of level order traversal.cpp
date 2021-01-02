#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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
public:
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

void preorder( Node *root1,  Node*root2, int lvl)
{

    if (root1 == NULL || root2==NULL)
        return;


    if (lvl%2 == 0)
        swap(root1->data, root2->data);


    preorder(root1->left, root2->right, lvl+1);
    preorder(root1->right, root2->left, lvl+1);
}

void reverseAlternate( Node *root)
{
   preorder(root->left, root->right, 0);
}


void inOrder(Node *root)
{
    if(!root)
        return;

    inOrder(root->left);
    cout<<root->data<< "  ";
    inOrder(root->right);

}

};


int main()
{
    BinaryTree b;
    b.insertNode(1);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(4);
    b.insertNode(5);
    b.insertNode(6);
    b.insertNode(7);
    b.insertNode(8);
    b.insertNode(9);
    b.insertNode(10);
    b.insertNode(11);
    b.insertNode(12);
    b.insertNode(13);
    b.insertNode(14);
    b.insertNode(15);

    b.inOrder(b.root);
    cout<<endl;
    b.reverseAlternate(b.root);

    b.inOrder(b.root);

    return 0;
}
