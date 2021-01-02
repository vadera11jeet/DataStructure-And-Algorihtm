#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node * right, *left ;

    Node(int data = INT_MIN, Node*right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }

};

Node * createTree(int pre[], char pos [], int * preindex,int size_)
{
    int index = *preindex;

    if(index == size_)
        return NULL;

    Node * temp = new Node(pre[index]);
    (*preindex)++;

    if(pos[index] == 'N')
    {
        temp->left = createTree(pre, pos, preindex, size_);
        temp->right = createTree(pre, pos, preindex, size_);
    }

    return temp;
}

void preOrder(Node *root)
{
    if(!root)
        return ;
    preOrder(root->left);
    cout<<root->data<< "  ";
    preOrder(root->right);

}

int main()
{
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    int  index = 0;

    Node *root = createTree(pre, preLN, &index, n);

    preOrder(root);

    return 0;
}
