#include<iostream>
#include<queue>
#include<stack>
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

Node * createTree(int pre[], int post[], int start, int end_ ,int poststart ,int postend)
{
    static int preIndex = 0;

    if(start > end_)
        return NULL;

    Node *root = new Node(pre[preIndex++]);

    if(start == end_)
        return root;

    int nextRoot = poststart;

    for(nextRoot = poststart; nextRoot < postend; nextRoot++)
        if(post[nextRoot] == pre[preIndex])
            break;

    int leftTreeSize = nextRoot - poststart + 1;
    int rightTreeSize = postend - 1 - nextRoot;

    root->left = createTree(pre, post, preIndex, end_, poststart, leftTreeSize -1) ;
    root->right = createTree(pre, post, preIndex, end_, nextRoot +1, postend - 1) ;

    return root;

}

void preOrder(Node *root)
{
    if(!root)
        return;

    cout<<root->data<< "  ";
    preOrder(root->left);
    preOrder(root->right);

}

int main()
{
    int post [] = {4, 5, 2, 6, 7, 3, 1};
    int pre [] = {1, 2, 4, 5, 3, 6, 7};

    Node * root = createTree(pre, post, 0, 6, 0, 6);

    preOrder(root);

    return 0;
}
