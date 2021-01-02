#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data = INT_MIN, Node * right = NULL, Node * left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

Node * createTree(int inorder[], int postorder[], int startin, int endin, int startpost, int endpost)
{

    if(startin > endin)
        return NULL;

    int rootVal = postorder[endpost];
    Node *root = new Node(rootVal);
    int rootIndex;

    for(rootIndex = startin; rootIndex < endin; rootIndex++)
    {
        if(inorder[rootIndex] == rootVal)
        {
            break;
        }

    }

    int leftTreeSize = rootIndex - startin;
    int rightTreeSize = endin - rootIndex;

    root->left = createTree(inorder, postorder, startin, rootIndex - 1, startpost, startpost + leftTreeSize - 1);
    root->right = createTree(inorder, postorder, rootIndex + 1, endin, endpost - rightTreeSize  , endpost-1);

    return root;
}

void inOrder(Node * root)
{
    if(!root)
        return;

    inOrder(root->left);
    cout<<root->data<< "  ";
    inOrder(root->right);

}


int main()
{
    int in [] = {4, 2, 5, 1, 6, 3, 7};
    int post [] = {4, 5, 2, 6, 7, 3, 1};

    Node * root = createTree(in, post, 0, 6, 0, 6);

    inOrder(root);

    return 0;
}
