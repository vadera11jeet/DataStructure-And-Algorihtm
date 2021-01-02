#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

    Node(int data = INT_MIN, Node * right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};
// in this code we use an approach that is range division left sub tree of BST have value INT_MIN to root value -1
// and right sub tree have value root value + 1 to INT_MAX  so we make recursive call and dived into sum all part
int  BSTFromPreOrder(vector<int>&pre, int pos, Node *root, int s_range, int e_range)
{
    if(pos == pre.size() || pre[pos] < s_range || pre[pos] > e_range)
        return pos;

    if(pre[pos] < root->data)
    {
        Node *temp = new Node(pre[pos]);
        root->left = temp ;
        pos ++;
        pos = BSTFromPreOrder(pre, pos, root->left, s_range, root->data-1);
    }

    if(pos == pre.size() || pre[pos] < s_range || pre[pos] > e_range)
        return pos;

    Node *temp = new Node(pre[pos]);
    root->right = temp;
    pos ++;
    pos = BSTFromPreOrder(pre, pos, root->right, root->data+1, e_range);
    return pos;
}

void inOrder(Node *root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<< "  ";
    inOrder(root->right);
}

int main()
{

    vector<int> pre =  { 10, 5, 1, 7, 40, 50 };

    Node *root = new Node(pre[0]);
    BSTFromPreOrder(pre, 1, root, INT_MIN, INT_MAX);
    inOrder(root);

    return 0;
}
