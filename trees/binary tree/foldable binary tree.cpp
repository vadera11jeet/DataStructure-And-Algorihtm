#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * right, *left;

    Node(int v = INT_MIN, Node * r = NULL, Node * l = NULL)
    {
        data = v;
        r = right;
        l = left;
    }
};

bool fold(Node *n1, Node *n2)
{
    if(n1 == NULL || n2 == NULL)
        return false;
    if(n1 == NULL && n2 == NULL)
        return true;
    return fold(n1->left, n2->right) && fold(n1->right , n2->left);
}

bool isFold(Node * root)
{
    if(root == NULL)
        return true;
    return fold(root->left, root->right);
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);

   cout<< isFold(root);

    return 0;
}
