#include<iostream>
#include<queue>
#include<stack>
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

int search_(int val, int arr[], int start, int end_)
{
    for(int i = start; i<end_; i++)
    {
        if(arr[i] == val)
            return i;
    }
    return -1;
}

Node * buildTree(int in[], int pre [], int start ,int end_)
{
    static int preIndex = 0;

    if(start > end_)
        return NULL;

    Node * node = new Node(pre[preIndex++]);

    if(start == end_)
        return node;

    int inIndex =   search_(node->data, in, start, end_);

    node->left = buildTree(in, pre, start, inIndex-1);
    node->right = buildTree(in, pre, inIndex+1, end_);
}

void inOrder(Node *root)
{
    if(!root)
        return ;
    inOrder(root->left);
    cout<<root->data<< "  ";
    inOrder(root->right);
}

int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };

    Node *root = buildTree(in,pre,0,5);

    inOrder(root);

    return 0;
}
