#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data = INT_MIN, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
// here we create balanced binary search tree
Node* BSTFromArray(vector<int> arr, int start, int end_)
{
    if(start > end_)
        return NULL;

    int mid = (start + end_)/2;
    Node *root = new Node(arr[mid]);

    Node *left = BSTFromArray(arr, start, mid-1);
    root->left = left;
    Node *right = BSTFromArray(arr, mid+1, end_);
    root->right = right;

    return root;
}
void preOrder(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node *root = BSTFromArray(arr, 0, arr.size()-1);
    preOrder(root);


    return 0;
}
